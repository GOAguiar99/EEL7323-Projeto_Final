/**
 * Author: Gabriel de Oliveira Aguiar
 * Institution: UFSC
 * Date: 26/11/2022
 * File: datapacket.hpp
 */

#ifndef _DATAPACKET_HPP_
#define _DATAPACKET_HPP_

#include "DHT11.hpp"
#include "ClockCalendar.hpp"

// Structure containing all the data to be stored in ine log entry
struct datapacket
{
    clock_t         log_time;
    calendar_t      log_date;
    uint8_t         sensID;
    CData           dht11_data;
    bool            error;       /*Only used for the ML verification event (correct or incorrect prevision). 0 - prevision inside the error range. 1 - prevision is not in the error range*/
    uint8_t         event_type;  /*1 - Sensor data reading event. 2 - ML prevision verification event. For now, only this two events are being recorded, but it can be expanded.*/
};


#endif /* _DATAPACKET_HPP_ */
