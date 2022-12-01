#include <unistd.h>
#include <timer.h>
#include "StationController.hpp"
#inclde "DHT11.hpp"
#include "UART.hpp"
#include "Sensor.hpp"
#include "ClockCalendar.hpp"
#include "datapacket.hpp"
#include "Queue.hpp"

StationController::StationController()
{
	state = 0; //control the actual state
}

void StationController::create_log(uint8_t event, CData data)
{	
	datapacket datapkt;

	clock_t    rd_time;
	calendar_t rd_date;
	
	datapkt.sensID = node.getID();
	CData predicted_data;
	bool estimate_error;
	
	/*Read actual date*/
	cc.readClock(rd_time);
    cc.readCalendar(rd_date);
    
    datapkt.log_date = rd_date;
    datapkt.log_time = rd_time;
    
    /*Sensor measurement event*/
    if(event == READ_SENSOR_EVENT){
    	datapkt.dht11_data = data;
    	datapkt.event_type = READ_SENSOR_EVENT;
	}
	
	/*ML prediction verification event*/
	else{
		predicted_data = ML_predict();
		
		if(abs(predicted_data.Temperature - data.Temperature) > ERROR_RANGE || abs(predicted_data.Humidity - data.Humidity) > ERROR_RANGE){
			estimate_error = 1; //Error too big
		}else{
			estimate_error = 0; //Error is acceptable
		}		
		datapkt.error = estimate_error;
    	datapkt.event_type = PREDICT_VERIF;
	}
    
    log.enqueue(datapkt);
}


void StationController::FSM() //Logic for next state
{
	/*Variables for time counting*/
	bool timer_finish, timer_running;
	double time_diff;
	struct timespec start, stop, new_stop; //Variables which hold the start and stop time count for the timer
	CData Data;
	
	unsigned char command[];//Assuming that until now there's only one command, which request to send data
	
	/*Read sensor variables*/
	CRaspberryPi Raspi;
    DHT11 Dht11(Raspi, 4);
    CData Data;
	
	char tx_buffer[];
	

	switch(state)
	{
		case 0://Wait for UART commands and sensor reading timeout

/*------------------------------------------------------------TIMER CHECKING ------------------------------------------------------------*/

			/*Timer is not already running, starting the time counting*/
			if((timer_finish == 0) && (timer_running == 0)){
				clock_gettime( CLOCK_REALTIME, &start);
				timer_running = 1;						
			}
			
			/*Timer is already running, check for timeout*/
			else if((timer_finish == 0) && (timer_running == 1)){
					clock_gettime( CLOCK_REALTIME, &stop);
					time_diff = stop.tv_sec - start.tv_sec; //Difference between start and stop 
					if(time_diff >= SENSOR_READ_TIMEOUT){
						timer_finish = 1;
						timer_running = 0;
						state = 1; //Sensor read timeout, change to state which reads and logs sensor values
						
						/*Advance clock calendar if 1 second has passed between the actual and last time verification*/
						if(new_stop.tv_sec - stop.tv_sec >= 1){
							cc.advance();
						}
					}
			}
			
			/*Any other values mean an error ocurred, reseting time counting*/
			else{
				timer_finish = 0;
				timer_running = 0;	
			}
/*------------------------------------------------------------ END TIMER CHECKING ------------------------------------------------------------*/						

			/*Poll for command reception*/
			if(UART_Read(&command) == 1)
			{
				state = 3;	
			}
		break;
		
		case 1://Read data and log events
			
			/*Reading Sensor*/
			Data = Dht11.Measure();
			create_log(READ_SENSOR_EVENT,Data);
			state = 2;
		break;
			
		case 2://Check ML predict
			create_log(PREDICT_VERIF,Data);
			state = 1;
		break;
		
		case 3://Send log
		//While last element in queue still not null, convert queue elements to char, send via UART and dequeue
		while(log.head.getData != 0){
			itoa(log.head.getData,tx_buffer,10);
			log.dequeue;
			UART_Write(&tx_buffer, strlen(tx_buffer));
		}	
	}
}
