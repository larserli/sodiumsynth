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

class TimeVariant: public ClockObserver, public IAudioModule{
public:
	TimeVariant(IClockSource *clock){
		_clock = clock;
		_clock_freq = clock->GetFrequency();
		_clock->AddObserver(this);
		_out = 0.0;
	};
	virtual ~TimeVariant(){
		_clock->RemoveObserver(this);
	};
	float get() override{return _out;};
protected:
	IClockSource *_clock;
	float _clock_freq;
	float _out;
};


#endif /* TIMEVARIANT_H_ */
