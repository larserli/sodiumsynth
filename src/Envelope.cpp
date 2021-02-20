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
	m_step = 1.0f / m_clock->GetFrequency();
	m_state = state::RELEASE;
	m_val = 0.0f;

}

Envelope::~Envelope() {
}

void Envelope::KeyDown(){
	m_state = state::ATTACK;
}

void Envelope::KeyUp(){
	m_state = state::RELEASE;
}

float Envelope::get(){
	return m_val;

}

void Envelope::tick(){
	switch(m_state){
	case state::ATTACK:
	{
		if(m_attack <= 0.0){		//Avoid divide by zero
			m_state = state::DECAY;
			break;
		}
		float step = 1.0f / (m_attack * static_cast<float>(m_clock->GetFrequency()));
		m_val += step;
		if(m_val >= 1.0f){
			m_val = 1.0f;
			m_state = state::DECAY;
		}
	}
		break;
	case state::DECAY:
	{
		if(m_decay <= 0.0){
			m_state = state::SUSTAIN;
			break;
		}
		float step = (1.0f - m_sustain) / ( m_decay * static_cast<float>(m_clock->GetFrequency()));
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
		if(m_release <= 0.0){
			m_val = 0.0f;
		}else{
			float step = (m_sustain)/ (m_release * static_cast<float>(m_clock->GetFrequency()));
			m_val -= step;
			if(m_val < 0.0f){
				m_val = 0.0f;
			}
		}

	}
	break;
	}


}

