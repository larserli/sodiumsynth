/*
 * IOsc.h
 *
 *  Created on: Feb 11, 2021
 *      Author: lars
 */

#pragma once
#include "IAudioModule.h"
#include "TimeVariant.h"
#include "ClockObserver.h"

class IOsc : public TimeVariant{
public:
	IOsc(IClockSource *clock) : TimeVariant(clock){
		_val = 0.0f;
		_lfo = nullptr;
		_mod_depth = 0.0f;
		_freq = 0.0f;

	};
	virtual void setFreq(float freq) = 0;
	virtual ~IOsc(){

	};
	void SetLfo(IOsc *lfo, float depth){
		_lfo = lfo;
		_mod_depth = depth;
	};

protected:
	float _val;
	float _freq;
	IOsc *_lfo;
	float _mod_depth;


};
