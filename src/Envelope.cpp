/*
 * ADSR.cpp
 *
 *  Created on: Feb 11, 2021
 *      Author: lars
 */

#include "Envelope.h"

Envelope::Envelope(IClockSource *clock, float a, float d, float s, float r) : TimeVariant(clock) {
	_attack = a;
	_decay = d;
	_sustain = s;
	_release = r;
	_time = 0.0f;
	_step = 1.0f / _clock_freq;

}

Envelope::~Envelope() {
	// TODO Auto-generated destructor stub
}

float Envelope::get(){
	if(_time < _attack){

	}
	_time += _step;
}

