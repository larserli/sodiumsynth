/*
 * SquareOsc.cpp
 *
 *  Created on: Feb 11, 2021
 *      Author: lars
 */

#include "SquareOsc.h"

SquareOsc::SquareOsc(IClockSource *clock, float frequency) : IOsc(clock) {
	m_freq = frequency;
	m_prd = static_cast<float>(m_clock_freq) / frequency;
	m_prd_low = m_prd / 2.0f;
	m_pwMod = nullptr;
	m_pwModDepth = 0.0f;
}

SquareOsc::~SquareOsc() {
}

void SquareOsc::SetPWMod(IOsc * mod, float depth){
	m_pwMod = mod;
	m_pwModDepth = depth;
}

void SquareOsc::setFreq(float freq){
	m_freq = freq;
	m_prd = static_cast<float>(m_clock_freq) / m_freq;
}

void SquareOsc::tick(){
	if(m_pwMod != nullptr){
		m_prd_low = (m_prd / 2.0f) + (m_pwMod->get() * m_pwModDepth * m_prd);
		if(m_prd_low < 0.0f){
			m_prd_low = 0.0f;
		}else if(m_prd_low > m_prd){
			m_prd_low = m_prd;
		}
	}
	m_val += 1.0f;
	if(m_val > m_prd){
		m_val -= m_prd;
	}
	if(m_val < m_prd_low){
		m_out = -1.0f;
	}else{
		m_out = 1.0f;
	}
}

