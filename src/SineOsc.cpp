/*
 * SineOsc.cpp
 *
 *  Created on: Feb 11, 2021
 *      Author: lars
 */

#include "SineOsc.h"
#include <numbers>
#include <cmath>

SineOsc::SineOsc(IClockSource *clock, float frequency) : IOsc(clock) {
	_freq = frequency;
	_step =  _freq * ((2.0f * std::numbers::pi) / _clock_freq);

}

SineOsc::~SineOsc() {
	// TODO Auto-generated destructor stub
}

void SineOsc::setFreq(float freq){
	_freq = freq;
	_step = _freq * ((2.0f * std::numbers::pi) / _clock_freq);
}

void SineOsc::tick(){
	if(_lfo != nullptr){
		_step = (_freq + (_lfo->get() * _mod_depth)) * ((2.0f * std::numbers::pi / _clock_freq));
	}
	_val += _step;
	if(_val > (2 * std::numbers::pi)){
		_val -= 2 * std::numbers::pi;
	}
	_out = sin(_val);
}

