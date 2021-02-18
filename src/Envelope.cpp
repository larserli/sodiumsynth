/*
 * ADSR.cpp
 *
 *  Created on: Feb 11, 2021
 *      Author: lars
 */

#include "Envelope.h"

Envelope::Envelope(IClockSource *clock, float a, float d, float s, float r) : TimeVariant(clock) {
	m_attack = a;
	m_decay = d;
	m_sustain = s;
	m_release = r;
	m_time = 0.0f;
	m_step = 1.0f / _clock_freq;
	m_state = state::RELEASE;
	m_val = 0.0f;

}

Envelope::~Envelope() {
	// TODO Auto-generated destructor stub
}

void Envelope::KeyDown(){
	m_state = state::ATTACK;
}

void Envelope::KeyUp(){
	m_state = state::RELEASE;
}

float Envelope::get(){
	switch(m_state){
	case state::ATTACK:
	{
		float step = m_attack / static_cast<float>(_clock->GetFrequency());
		m_val += step;
		if(m_val >= 1.0f){
			m_val = 1.0f;
			m_state = state::RELEASE;
		}
	}
		break;
	case state::DECAY:
	{
		float step = m_decay / static_cast<float>(_clock->GetFrequency());
		m_val -= step;
		if(m_val <= m_sustain){
			m_val = m_sustain;
			m_state = state::SUSTAIN;
		}
	}
		break;
	case state::SUSTAIN:
		m_val = m_sustain;
		break;
	case state::RELEASE:
	{
		float step = m_release / static_cast<float>(_clock->GetFrequency());
		m_val -= step;
		if(m_val < 0.0f){
			m_val = 0.0f;
		}

	}
	break;
	}
	return m_val;
}

