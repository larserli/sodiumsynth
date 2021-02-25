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

/**
 * Oscillator base
 * An oscillator is any module that will produce a periodic signal at a defined frequency
 */
class IOsc : public TimeVariant{
public:
	/**
	 * Constructor
	 * @param clock Clock source
	 */
	IOsc(IClockSource *clock) : TimeVariant(clock){
		m_val = 0.0f;
		m_lfo = nullptr;
		m_mod_depth = 0.0f;
		m_freq = 0.0f;

	};
	/**
	 * Set frequency (Hz)
	 */
	virtual void setFreq(float freq) = 0;
	virtual ~IOsc(){

	};
	/**
	 * Modulating signal (frequency modulation)
	 * @param lfo Oscillator object
	 * @param depth Modulation depth
	 */
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
