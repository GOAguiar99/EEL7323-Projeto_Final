/**
 * Author: Gabriel de Oliveira Aguiar
 * Institution: UFSC
 * Date: 26/11/2022
 * File: Calendar.hpp
 */
#ifndef CALENDAR_HPP_
#define CALENDAR_HPP_

#include <cstdint>

// calendar_t structure containing time information
struct calendar_t
{
    uint8_t mo;
    uint8_t day;
    uint8_t yr;
};

//Calendar class
class Calendar {
    protected:
        calendar_t date_;
    public:
        /**
         * @brief Construct a new Calendar object with default constructor.
         * 
         */
        Calendar();

        /**
         * @brief Construct a new Calendar object.
         * 
         * @param m Month.
         * @param d Day.
         * @param y Year.
         */
        Calendar (int m, int d, int y);

        /**
         * @brief Construct a new Calendar object using calendar_t struct
         * 
         * @param new_date New date to be set
         */
        Calendar (calendar_t new_date);

        /**
         * @brief Set the Calendar object.
         * 
         * @param m Month.
         * @param d Day.
         * @param y Year.
         */
        void setCalendar (int m, int d, int y);

        /**
         * @brief Set the Calendar object using calendar_t struct
         * 
         * @param new_date New date to be set
         */
        void setCalendar (calendar_t new_date);

        /**
         * @brief Reads currently stored date. Values passed by reference.
         * 
         * @param m Month.
         * @param d Day.
         * @param y Year.
         */
        void readCalendar (int& m, int& d, int& y);

        /**
         * @brief Read currently stored date using calendar_t struct
         * 
         * @param rd_date struct to hold the date
         */
        void readCalendar (calendar_t &rd_date);

        /**
         * @brief Advance the calendar by one day.
         * 
         */
        void advance ();
};

#endif /* CALENDAR_HPP_ */
