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

/** Interface for classes that can serve as a clock source
 */
class IClockSource{
public:
	/** Get the clock frequency
	 * @returns Clock frequency in Hz
	 */
	int GetFrequency();
	/** Add a clock observer
	 * @param observer
	 */
	void AddObserver(ClockObserver *observer);
	/** Remove a clock observer
	 * @param observer
	 */
	void RemoveObserver(ClockObserver *observer);
	IClockSource();
	virtual ~IClockSource();
protected:
	/** Update all attached observers
	 * (call tick() in all observers
	 */
	void updateObservers();
	//Clock frequency
	int m_freq;
private:
	//List of observers
	std::list<ClockObserver*> m_observers;

};



#endif /* ICLOCKSOURCE_H_ */
