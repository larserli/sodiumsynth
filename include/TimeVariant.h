/*
 * TimeVariant.h
 *
 *  Created on: Feb 13, 2021
 *      Author: lars
 */

#ifndef TIMEVARIANT_H_
#define TIMEVARIANT_H_
#include "ClockObserver.h"
#include "IClockSource.h"
#include "IAudioModule.h"

/**
 * Generic interface for time dependent audio modules
 * Modules of this type depend on input from a clock source and will
 * act as observers to this clock source.
 */
class TimeVariant: public ClockObserver, public IAudioModule{
public:
	TimeVariant(IClockSource *clock){
		m_clock = clock;
		m_clock_freq = clock->GetFrequency();
		m_clock->AddObserver(this);
		m_out = 0.0;
	};
	virtual ~TimeVariant(){
		m_clock->RemoveObserver(this);
	};
	virtual float get() override{return m_out;};
protected:
	IClockSource *m_clock;
	float m_clock_freq;
	float m_out;
};


#endif /* TIMEVARIANT_H_ */
