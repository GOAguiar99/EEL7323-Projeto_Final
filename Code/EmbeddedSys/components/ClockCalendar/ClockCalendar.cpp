/**
 * Author: Gabriel de Oliveira Aguiar
 * Institution: UFSC
 * Date: 26/11/2022
 * File: ClockCalendar.cpp
 */
#include "ClockCalendar.hpp"

//ClockCalendar class members
ClockCalendar::ClockCalendar() : Clock(), Calendar() {}

ClockCalendar::ClockCalendar(int mt, int d, int y, int h, int m, int s, bool pm) : Clock(h, m, s, pm), Calendar(mt, d, y) {}

ClockCalendar::ClockCalendar(clock_t new_time, calendar_t new_date) : Clock(new_time), Calendar(new_date) {}

ClockCalendar::ClockCalendar(time_t current_time){
    int mt, d, y, h, m, s;
    bool pm = false;
    struct tm * timeinfo = localtime (&current_time); // Stores system time in local time format
    
    mt = timeinfo->tm_mon + 1; // Add 1 because tm_mon ranges from 0 to 11, not from 1 to 12
    d = timeinfo->tm_mday;
    y = timeinfo->tm_year + 1900; //Add 1900 because tm_year represents years past since 1900, for 2021 tm_year has a value of 121
    h = timeinfo->tm_hour;
    m = timeinfo->tm_min;
    s = timeinfo->tm_sec;

    // Changes from 24h format to 12h format
    if (h >= 12)
    {
        pm = true;
        if (h >= 13)
        {
            h -=12;
        }
    }
    else
    {
        pm = false;
    }
    
    // Stores the adjusted time information
    setClock(h, m, s, pm);
    setCalendar(mt, d, y);
}

void ClockCalendar::advance (){
    bool was_pm = time_.is_pm;
    Clock::advance();
    if ((was_pm) && (!time_.is_pm))
    {
        Calendar::advance();
    }
    
}
