/*
 * Amp.cpp
 *
 *  Created on: Feb 12, 2021
 *      Author: lars
 */

#include "Amp.h"

Amp::Amp() {
	m_source = nullptr;
	m_mod = nullptr;
	m_level = 0.0f;
	m_mod_level = 0.0f;
}

Amp::~Amp() {

}

void Amp::SetSource(IAudioModule *source){
	m_source = source;
}

void Amp::SetLevel(float level){
	m_level = level;
}

void Amp::SetMod(IAudioModule *mod, float level){
	m_mod = mod;
	m_mod_level = level;
}

float Amp::get(){
	if(m_source == nullptr){
		return 0.0f;
	}
	float level = m_level;
	if(m_mod != nullptr){
		level = m_mod->get() * m_level;
	}
	float signal = m_source->get() * level;
	/*if(signal > 1.0){
		signal = 1.0;
	}else if(signal < -1.0){
		signal = -1.0;
	}*/
	return signal;
}
