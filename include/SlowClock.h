/*
 * SlowClock.h
 *
 *  Created on: Feb 14, 2021
 *      Author: lars
 */

#ifndef INCLUDE_SLOWCLOCK_H_
#define INCLUDE_SLOWCLOCK_H_
#include "IClockSource.h"
#include "ClockObserver.h"

class SlowClock: public IClockSource, public ClockObserver{
public:
	SlowClock(IClockSource *clock);
	SlowClock(IClockSource *clock, float rate);
	virtual ~SlowClock();
	void setRate(float rate);
	void tick() override;

private:
	int _ticks;
	int _rate;
	IClockSource *_master_clock;
};



#endif /* INCLUDE_SLOWCLOCK_H_ */
