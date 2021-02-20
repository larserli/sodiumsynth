/*
 * Mixer.cpp
 *
 *  Created on: Feb 13, 2021
 *      Author: lars
 */

#include "Mixer.h"

Mixer::Mixer() {
	// TODO Auto-generated constructor stub

}

Mixer::~Mixer() {
	// TODO Auto-generated destructor stub
}

void Mixer::AddChannel(IAudioModule *channel, float level){
	_channels.push_back({channel, level});
}

void Mixer::RemoveChannel(IAudioModule *channel){
	_channels.remove_if([&](struct channel &c)->bool{return c.source == channel;});

}

void Mixer::SetLevel(IAudioModule *channel, float level){
	for(auto &c : _channels){
		if(c.source == channel){
			c.level = level;
			break;
		}
	}
}

float Mixer::get(){
	if(_channels.size() == 0){
		return 0.0f;
	}else{
		float out = 0.0f;
		for(auto &c : _channels){
			out += (c.source->get() * c.level);
		}
		if(out > 1.0f){
			out = 1.0f;
		}else if(out < -1.0f){
			out = -1.0f;
		}
		return out;
	}
}

