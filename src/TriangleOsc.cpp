/*
 * TriangleOsc.cpp
 *
 *  Created on: Feb 14, 2021
 *      Author: lars
 */

#include "TriangleOsc.h"

TriangleOsc::TriangleOsc(IClockSource *clock) : IOsc(clock){
	_freq = 0;
	_step = calcStep(_freq);
	_state = 0;
}

TriangleOsc::TriangleOsc(IClockSource *clock, float freq): IOsc(clock){
	_freq = freq;
	_step = calcStep(_freq);
	_state = 0;
}

TriangleOsc::~TriangleOsc(){

}

void TriangleOsc::setFreq(float freq){
	_freq = freq;
	_step = calcStep(_freq);
}

float TriangleOsc::calcStep(float freq){
	return freq * (4.0 / _clock_freq);
}

void TriangleOsc::tick(){
	if(_lfo != nullptr){
		_step = calcStep(_freq + (_lfo->get() * _mod_depth));
	}
	//Switch state if the output is going outside [-1,1]
	if(_out > (1.0f - _step)){
		_state = 1;
	}else if(_out < (-1.0f + _step)){
		_state = 0;
	}
	if(_state == 0){
		_out += _step;
	}else{
		_out -= _step;
	}
}

