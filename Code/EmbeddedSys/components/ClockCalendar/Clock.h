/**
 * Author: Gabriel de Oliveira Aguiar
 * Institution: UFSC
 * Date: 26/11/2022
 * File: Clock.hpp
 */
#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include <cstdint>

// clock_t structure containing time information
struct clock_t
{
    uint8_t hr;         // Hours
    uint8_t min;        // Minutes
    uint8_t sec;        // Seconds
    bool    is_pm;      // AM:PM indicator
};


//Clock class
class Clock {
    protected:
        clock_t time_;
    public:
    	/**
    	 * @brief Construct a new Clock object with default constructor.
    	 * 
    	 */
        Clock();

        /**
         * @brief Construct a new Clock object.
         * 
         * @param h Hours.
         * @param m Minutes.
         * @param s Second.
         * @param pm am:pm indicator.
         */
        Clock (int h, int m, int s, bool pm);

        /**
         * @brief Construct a new Clock object using clock_t struct
         * 
         * @param new_time New time to set
         */
        Clock (clock_t new_time);

        /**
         * @brief Set the Clock object to a specific time.
         * 
         * @param h Hours.
         * @param m Minutes.
         * @param s Seconds.
         * @param pm am:pm indicator.
         */
        void setClock (int h, int m, int s, bool pm);

        /**
         * @brief Set the Clock object using clock_t struct
         * 
         * @param new_time New time to set
         */
        void setClock (clock_t new_time);

        /**
         * @brief Reads currently stored time. Values passed by reference.
         * 
         * @param h Hours.
         * @param m Minutes.
         * @param s Seconds.
         * @param pm am:pm indicator.
         */
        void readClock (int& h, int& m, int& s, bool& pm);

        /**
         * @brief Reads currently stored time using clock_t struct
         * 
         * @param rd_time struct to hold the time
         */
        void readClock (clock_t &rd_time);
        
        /**
         * @brief Advances the clock by one second.
         * 
         */
        void advance ();
};

#endif /* CLOCK_HPP_ */
