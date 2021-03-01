/*
 * SineOsc.cpp
 *
 *  Created on: Feb 11, 2021
 *      Author: lars
 */

#include "SineOsc.h"
#include <cmath>

SineOsc::SineOsc(IClockSource *clock, float frequency) : IOsc(clock) {
	m_freq = frequency;
	m_step =  m_freq * ((2.0f * M_PI) / m_clock_freq);

}

SineOsc::~SineOsc() {
}

void SineOsc::setFreq(float freq){
	m_freq = freq;
	m_step = m_freq * ((2.0f * M_PI) / m_clock_freq);
}

void SineOsc::tick(){
	if(m_lfo != nullptr){
		m_step = (m_freq + (m_lfo->get() * m_mod_depth)) * ((2.0f * std::numbers::pi / m_clock_freq));
	}
	m_val += m_step;
	if(m_val > (2 * M_PI)){
		m_val -= 2 * M_PI;
	}
	m_out = sin(m_val);
}

