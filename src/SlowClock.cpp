/*
 * SlowClock.cpp
 *
 *  Created on: Feb 14, 2021
 *      Author: lars
 */

#include "SlowClock.h"

SlowClock::SlowClock(IClockSource *clock){
	m_master_clock = clock;
	m_rate = 1;
	m_ticks = 0;
	m_master_clock->AddObserver(this);
}

SlowClock::SlowClock(IClockSource *clock, float rate){
	m_master_clock = clock;
	m_rate = static_cast<int>(static_cast<float>(m_master_clock->GetFrequency()) / rate);
	m_ticks = 0;
	m_master_clock->AddObserver(this);
}

SlowClock::~SlowClock(){

}

void SlowClock::setRate(float rate){
	m_rate = static_cast<int>(static_cast<float>(m_master_clock->GetFrequency()) / rate);
}

void SlowClock::tick(){
	if(++m_ticks >= m_rate){
		updateObservers();
		m_ticks = 0;
	}
}



