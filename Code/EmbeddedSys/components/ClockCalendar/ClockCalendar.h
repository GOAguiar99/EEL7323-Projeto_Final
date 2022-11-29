#include "Clock.h"
#include "Calendar.h"

class ClockCalendar: public Clock, public Calendar{
	public:
	ClockCalendar(int d, int m, int y, int h, int min, int s, int pm);
	void advance();	
};
