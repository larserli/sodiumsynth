/*
 * SawOsc.cpp
 *
 *  Created on: Feb 11, 2021
 *      Author: lars
 */

#include "SawOsc.h"

SawOsc::SawOsc(IClockSource *clock, float frequency) : IOsc(clock) {
	// TODO Auto-generated constructor stub
	_freq = frequency;
	_step = _freq * (2.0f / _clock_freq);

}

SawOsc::~SawOsc() {
	// TODO Auto-generated destructor stub
}

void SawOsc::setFreq(float freq){
	_freq = freq;
	_step = _freq * (2.0f / _clock_freq);
}

void SawOsc::tick(){
	if(_lfo != nullptr){
		_step = (_freq + (_lfo->get() * _mod_depth)) * (2.0f / _clock_freq);
	}
	_val += _step;
	if(_val > 1.0f){
		_val -= 2.0f;
	}
	_out  = _val;
}

