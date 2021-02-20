/*
 * TriangleOsc.cpp
 *
 *  Created on: Feb 14, 2021
 *      Author: lars
 */

#include "TriangleOsc.h"

TriangleOsc::TriangleOsc(IClockSource *clock) : IOsc(clock){
	m_freq = 0;
	m_step = calcStep(m_freq);
	m_state = 0;
}

TriangleOsc::TriangleOsc(IClockSource *clock, float freq): IOsc(clock){
	m_freq = freq;
	m_step = calcStep(m_freq);
	m_state = 0;
}

TriangleOsc::~TriangleOsc(){

}

void TriangleOsc::setFreq(float freq){
	m_freq = freq;
	m_step = calcStep(m_freq);
}

float TriangleOsc::calcStep(float freq){
	return freq * (4.0 / m_clock_freq);
}

void TriangleOsc::tick(){
	if(m_lfo != nullptr){
		m_step = calcStep(m_freq + (m_lfo->get() * m_mod_depth));
	}
	//Switch state if the output is going outside [-1,1]
	if(m_out > (1.0f - m_step)){
		m_state = 1;
	}else if(m_out < (-1.0f + m_step)){
		m_state = 0;
	}
	if(m_state == 0){
		m_out += m_step;
	}else{
		m_out -= m_step;
	}
}

