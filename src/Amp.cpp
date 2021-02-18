/*
 * Amp.cpp
 *
 *  Created on: Feb 12, 2021
 *      Author: lars
 */

#include "Amp.h"

Amp::Amp() {
	_source = nullptr;
	_mod = nullptr;
	_level = 0.0f;
	_mod_level = 0.0f;
}

Amp::~Amp() {

}

void Amp::SetSource(IAudioModule *source){
	_source = source;
}

void Amp::SetLevel(float level){
	_level = level;
}

void Amp::SetMod(IAudioModule *mod, float level){
	_mod = mod;
	_mod_level = level;
}

float Amp::get(){
	if(_source == nullptr){
		return 0.0f;
	}
	float level = _level;
	if(_mod != nullptr){
		level += (_mod->get() * _mod_level);
	}
	float signal = _source->get() * level;
	/*if(signal > 1.0){
		signal = 1.0;
	}else if(signal < -1.0){
		signal = -1.0;
	}*/
	return signal;
}
