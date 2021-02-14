/*
 * SimpleDelay.cpp
 *
 *  Created on: Feb 13, 2021
 *      Author: lars
 */

#include "SimpleDelay.h"

SimpleDelay::SimpleDelay(IClockSource *clock) : TimeVariant(clock) {
	_delay_time = 0;
	_feedback = 0.0f;
	_mix = 0.0;
	_source = nullptr;
	_get_at = 1;
	_put_at = 0;
}

SimpleDelay::~SimpleDelay() {
	// TODO Auto-generated destructor stub
}

void SimpleDelay::SetFeedback(float feedback){
	_feedback = feedback;
}

void SimpleDelay::SetMix(float mix){
	_mix = mix;
}

void SimpleDelay::SetTime(unsigned long time){
	_delay_time = time;
	_buffer.resize((time * _clock_freq) / 1000);

}

void SimpleDelay::SetSource(IAudioModule *source){
	_source = source;
}

void SimpleDelay::tick(){
	if(_source == nullptr){
		_out = 0.0f;
	}
	if(_delay_time == 0){
		_out = _source->get();
	}
	_out = (_buffer[_get_at++] * _mix) + (_source->get() * (1.0f-_mix));
	if(_get_at >= _buffer.size()){
		_get_at = 0;
	}
	if(_out > 1.0f){
		_out = 1.0f;
	}else if(_out < -1.0f){
		_out = -1.0f;
	}
	_buffer[_put_at++] = _source->get() + (_out * _feedback);
	if(_put_at >= _buffer.size()){
		_put_at = 0;
	}




}
