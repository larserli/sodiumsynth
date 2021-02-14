/*
 * IClockSource.cpp
 *
 *  Created on: Feb 12, 2021
 *      Author: lars
 */

#include "IClockSource.h"

IClockSource::IClockSource(){
	_freq = 0;
}

IClockSource::~IClockSource(){

}

int IClockSource::GetFrequency(){
	return _freq;
}
void IClockSource::AddObserver(ClockObserver *observer){
	_observers.push_back(observer);
}
void IClockSource::RemoveObserver(ClockObserver *observer){
	_observers.remove(observer);
}

void IClockSource::updateObservers(){
	for(auto &o : _observers){
		o->tick();
	}
}



