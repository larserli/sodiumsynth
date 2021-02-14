/*
 * IClockSource.h
 *
 *  Created on: Feb 12, 2021
 *      Author: lars
 */

#ifndef ICLOCKSOURCE_H_
#define ICLOCKSOURCE_H_
#include <list>
#include "ClockObserver.h"

class IClockSource{
public:
	int GetFrequency();
	void AddObserver(ClockObserver *observer);
	void RemoveObserver(ClockObserver *observer);
	IClockSource();
	virtual ~IClockSource();
protected:
	void updateObservers();
	int _freq;
private:

	std::list<ClockObserver*> _observers;

};



#endif /* ICLOCKSOURCE_H_ */
