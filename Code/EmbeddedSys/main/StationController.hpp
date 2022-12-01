#include "ClockCalendar.hpp"
#include "Queue.hpp"
#include "datapacket.hpp"

#define READ_SENSOR_EVENT 1
#define PREDICT_VERIF     2

#define ERROR_RANGE 10 

class StationController{
	int state;
	ClockCalendar cc;
	Sensor node;
	Queue log;
	
	public:
		StationController();
		void create_log(uint8_t event, CData data);
		void FSM();
};
