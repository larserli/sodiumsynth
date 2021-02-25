
#pragma once

/** Interface for clock observers (sinks)
 *
 */
class ClockObserver{
public:
	/**
	 * Update function
	 */
	virtual void tick() = 0;
	virtual ~ClockObserver(){};
};
