/*
 * SawOsc.cpp
 *
 *  Created on: Feb 11, 2021
 *      Author: lars
 */

#include "SawOsc.h"

SawOsc::SawOsc(IClockSource *clock, float frequency) : IOsc(clock) {
	m_freq = frequency;
	m_step = m_freq * (2.0f / m_clock_freq);
}

SawOsc::SawOsc(IClockSource *clock) : IOsc(clock){
	m_freq = 0.0f;
	m_step = 0.0f;
}

SawOsc::~SawOsc() {

}

void SawOsc::setFreq(float freq){
	m_freq = freq;
	m_step = m_freq * (2.0f / m_clock_freq);
}

void SawOsc::tick(){
	if(m_lfo != nullptr){
		m_step = (m_freq + (m_lfo->get() * m_mod_depth)) * (2.0f / m_clock_freq);
	}
	m_val += m_step;
	if(m_val > 1.0f){
		m_val -= 2.0f;
	}
	m_out  = m_val;
}

