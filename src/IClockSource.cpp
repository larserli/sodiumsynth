/*
 * IClockSource.cpp
 *
 *  Created on: Feb 12, 2021
 *      Author: lars
 */

#include "IClockSource.h"

IClockSource::IClockSource(){
	m_freq = 0;
}

IClockSource::~IClockSource(){

}

int IClockSource::GetFrequency(){
	return m_freq;
}
void IClockSource::AddObserver(ClockObserver *observer){
	m_observers.push_back(observer);
}
void IClockSource::RemoveObserver(ClockObserver *observer){
	m_observers.remove(observer);
}

void IClockSource::updateObservers(){
	for(auto &o : m_observers){
		o->tick();
	}
}



