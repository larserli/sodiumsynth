
#pragma once

class ClockObserver{
public:
	virtual void tick() = 0;
	virtual ~ClockObserver(){};
};
