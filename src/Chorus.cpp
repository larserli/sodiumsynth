/*
 * Chorus.cpp
 *
 *  Created on: Feb 14, 2021
 *      Author: lars
 */

#include "Chorus.h"
#include "SineOsc.h"
#include <memory>


Chorus::Chorus(IClockSource *clock) : TimeVariant(clock){
	m_osc = std::shared_ptr<IOsc>(new SineOsc(clock, 0.0f));
	m_source = nullptr;
	m_mod_depth = 0.0f;
	m_max_delay = 0.1f;
	m_buffer.resize(m_max_delay * clock->GetFrequency());
	m_put_at = 0;
	m_delay = 0.03f;
	m_base_delay = 0.03f;
	m_mix = 0.5f;
}

Chorus::~Chorus(){

}


void Chorus::setSource(IAudioModule *source){
	m_source = source;
}

void Chorus::setModDepth(float depth){
	m_mod_depth = depth;
}

void Chorus::setModRate(float freq){
	m_osc->setFreq(freq);
}

void Chorus::setMix(float mix){
	m_mix = mix;
}

void Chorus::tick(){
	if(m_source == nullptr){
		m_out = 0.0f;
		return;
	}
	float delay = m_delay + (m_osc->get() * m_mod_depth);
	int get_at = m_put_at - static_cast<int>(delay * m_clock->GetFrequency());
	if(get_at < 0){
		get_at += m_buffer.size();
	}
	m_out = (m_buffer[get_at] * m_mix) + (m_source->get() * (1.0f - m_mix));
	m_buffer[m_put_at++] = m_source->get();
	if(m_put_at >= m_buffer.size()){
		m_put_at = 0;
	}


}
