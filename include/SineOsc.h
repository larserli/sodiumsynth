/*
 * SineOsc.h
 *
 *  Created on: Feb 11, 2021
 *      Author: lars
 */

#ifndef SINEOSC_H_
#define SINEOSC_H_
#include "IOsc.h"

class SineOsc : public IOsc{
public:
	SineOsc(IClockSource *clock, float frequency);
	virtual ~SineOsc();
	virtual void tick() override;
	void setFreq(float freq) override;
private:
	float _step;
};

#endif /* SINEOSC_H_ */
