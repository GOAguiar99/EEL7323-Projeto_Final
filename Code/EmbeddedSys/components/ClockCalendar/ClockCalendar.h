
/**
 * Author: Gabriel de Oliveira Aguiar
 * Institution: UFSC
 * Date: 26/11/2022
 * File: ClockCalendar.hpp
 */
#ifndef CLK_CAL_HPP_
#define CLK_CAL_HPP_

#include <ctime>
#include "Clock.hpp"
#include "Calendar.hpp"

//ClockCalendar class
class ClockCalendar : public Clock, public Calendar {
    public:
        /**
         * @brief Construct a new Clock Calendar object with default constructor.
         * 
         */
        ClockCalendar ();
        
        /**
         * @brief Construct a new Clock Calendar object with specific values.
         * 
         * @param mt Month.
         * @param d Day.
         * @param y Year.
         * @param h Hour.
         * @param m Minutes.
         * @param s Seconds.
         * @param pm am:pm indicator.
         */
        ClockCalendar (int mt, int d, int y, int h, int m, int s, bool pm);

        /**
         * @brief Construct a new Clock Calendar object with clock_t and calendar_t structs
         * 
         * @param new_time New time to set
         * @param new_date New date to set
         */
        ClockCalendar (clock_t new_time, calendar_t new_date);
        
        /**
         * @brief Construct a new Clock Calendar object using time_t type from ctime library.
         * 
         * @param time System time to store.
         */
        ClockCalendar (time_t time);
        void advance ();
};

#endif /* CLK_CAL_HPP_ */
