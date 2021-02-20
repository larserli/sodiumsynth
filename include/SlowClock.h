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

/** Generate a slow clock signal from a master clock
 *  The slow clock will tick all observers at a given frequency
 */
class SlowClock: public IClockSource, public ClockObserver{
public:
	//Class constructor
	SlowClock(IClockSource *clock);
	SlowClock(IClockSource *clock, float rate);
	virtual ~SlowClock();
	/** Set clock frequency (rate)
	 * @param rate Frequency in Hz
	 */
	void setRate(float rate);
	/** Tick from the master clock
	 *
	 */
	void tick() override;

private:
	int m_ticks;
	int m_rate;
	IClockSource *m_master_clock;
};



#endif /* INCLUDE_SLOWCLOCK_H_ */
