/*
 * SquareOsc.cpp
 *
 *  Created on: Feb 11, 2021
 *      Author: lars
 */

#include "SquareOsc.h"

SquareOsc::SquareOsc(IClockSource *clock, float frequency) : IOsc(clock) {
	_freq = frequency;
	_prd = static_cast<float>(_clock_freq) / frequency;
	_prd_low = _prd / 2.0f;
	_pwMod = nullptr;
	_pwModDepth = 0.0f;
}

SquareOsc::~SquareOsc() {
	// TODO Auto-generated destructor stub
}

void SquareOsc::SetPWMod(IOsc * mod, float depth){
	_pwMod = mod;
	_pwModDepth = depth;
}

void SquareOsc::setFreq(float freq){
	_freq = freq;
	_prd = static_cast<float>(_clock_freq) / _freq;
}

void SquareOsc::tick(){
	if(_pwMod != nullptr){
		_prd_low = (_prd / 2.0f) + (_pwMod->get() * _pwModDepth * _prd);
		if(_prd_low < 0.0f){
			_prd_low = 0.0f;
		}else if(_prd_low > _prd){
			_prd_low = _prd;
		}
	}
	_val += 1.0f;
	if(_val > _prd){
		_val -= _prd;
	}
	if(_val < _prd_low){
		_out = -1.0f;
	}else{
		_out = 1.0f;
	}
}

