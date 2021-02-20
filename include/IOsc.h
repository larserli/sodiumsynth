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
		m_val = 0.0f;
		m_lfo = nullptr;
		m_mod_depth = 0.0f;
		m_freq = 0.0f;

	};
	virtual void setFreq(float freq) = 0;
	virtual ~IOsc(){

	};
	void setLfo(IOsc *lfo, float depth){
		m_lfo = lfo;
		m_mod_depth = depth;
	};

protected:
	float m_val;
	float m_freq;
	IOsc *m_lfo;
	float m_mod_depth;


};
