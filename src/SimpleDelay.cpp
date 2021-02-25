/*
 * SimpleDelay.cpp
 *
 *  Created on: Feb 13, 2021
 *      Author: lars
 */

#include "SimpleDelay.h"

SimpleDelay::SimpleDelay(IClockSource *clock) : TimeVariant(clock) {
	m_delay_time = 0;
	m_feedback = 0.0f;
	m_mix = 0.0;
	m_source = nullptr;
	//Since the whole buffer is used
	m_front = 1;
	m_back = 0;
}

SimpleDelay::~SimpleDelay() {
}

void SimpleDelay::SetFeedback(float feedback){
	m_feedback = feedback;
}

void SimpleDelay::SetMix(float mix){
	m_mix = mix;
}

void SimpleDelay::SetTime(unsigned long time){
	m_delay_time = time;
	m_buffer.resize((time * m_clock_freq) / 1000);
	m_front = 1;
	m_back = 0;

}

void SimpleDelay::SetSource(IAudioModule *source){
	m_source = source;
}

void SimpleDelay::tick(){
	if(m_source == nullptr){
		m_out = 0.0f;
	}
	if(m_delay_time == 0){
		m_out = m_source->get();
	}
	m_out = (m_buffer[m_front++] * m_mix) + (m_source->get() * (1.0f-m_mix));
	if(m_front >= m_buffer.size()){
		m_front = 0;
	}
	if(m_out > 1.0f){
		m_out = 1.0f;
	}else if(m_out < -1.0f){
		m_out = -1.0f;
	}
	m_buffer[m_back++] = m_source->get() + (m_out * m_feedback);
	if(m_back >= m_buffer.size()){
		m_back = 0;
	}

}
