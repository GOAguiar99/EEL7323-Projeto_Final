
/*
 * Author: Gabriel de Oliveira Aguiar
 * Institution: UFSC
 * Date: 26/11/2022
 * File: Calendar.cpp
 */
#include "Calendar.hpp"

//Calendar class members
Calendar::Calendar() : date_ {} {}

Calendar::Calendar(int m, int d, int y) : date_ { m, d, y } {}

Calendar::Calendar(calendar_t new_date) : date_ { new_date } {}

void Calendar::setCalendar(int m, int d, int y){
    date_.mo = m;
    date_.day = d;
    date_.yr = y;
}

void Calendar::setCalendar(calendar_t new_date)
{
    date_ = new_date;
}

void Calendar::readCalendar(int& m, int& d, int& y){
    m = date_.mo;
    d = date_.day;
    y = date_.yr;
}

void Calendar::readCalendar(calendar_t &rd_date)
{
    rd_date = date_;
}

void Calendar::advance(){
    date_.day++;
    if (date_.day > 30)
    {
        date_.day = 1;
        date_.mo++;
        if (date_.mo > 12)
        {
            date_.mo = 1;
            date_.yr++;
        }
    }
}
