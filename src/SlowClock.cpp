/*
 * SlowClock.cpp
 *
 *  Created on: Feb 14, 2021
 *      Author: lars
 */

#include "SlowClock.h"

SlowClock::SlowClock(IClockSource *clock){
	_master_clock = clock;
	_rate = 1;
	_ticks = 0;
}

SlowClock::SlowClock(IClockSource *clock, float rate){
	_master_clock = clock;
	_rate = static_cast<int>(static_cast<float>(_master_clock->GetFrequency()) / rate);
	_ticks = 0;
}

SlowClock::~SlowClock(){

}

void SlowClock::setRate(float rate){
	_rate = static_cast<int>(static_cast<float>(_master_clock->GetFrequency()) / rate);
}

void SlowClock::tick(){
	if(++_ticks >= _rate){
		updateObservers();
		_ticks = 0;
	}
}



