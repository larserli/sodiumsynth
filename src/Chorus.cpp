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
	_osc = std::shared_ptr<IOsc>(new SineOsc(clock, 0.0f));
	_source = nullptr;
	_mod_depth = 0.0f;
	_max_delay = 0.1f;
	_buffer.resize(_max_delay * clock->GetFrequency());
	_put_at = 0;
	_delay = 0.03f;
	_base_delay = 0.03f;
	_mix = 0.5f;
}

Chorus::~Chorus(){

}


void Chorus::setSource(IAudioModule *source){
	_source = source;
}

void Chorus::setModDepth(float depth){
	_mod_depth = depth;
}

void Chorus::setModRate(float freq){
	_osc->setFreq(freq);
}

void Chorus::setMix(float mix){
	_mix = mix;
}

void Chorus::tick(){
	if(_source == nullptr){
		_out = 0.0f;
		return;
	}
	float delay = _delay + (_osc->get() * _mod_depth);
	int get_at = _put_at - static_cast<int>(delay * _clock->GetFrequency());
	if(get_at < 0){
		get_at += _buffer.size();
	}
	_out = (_buffer[get_at] * _mix) + (_source->get() * (1.0f - _mix));
	_buffer[_put_at++] = _source->get();
	if(_put_at >= _buffer.size()){
		_put_at = 0;
	}


}
