/*
 * SawOsc.h
 *
 *  Created on: Feb 11, 2021
 *      Author: lars
 */

#ifndef SAWOSC_H_
#define SAWOSC_H_
#include "IOsc.h"

class SawOsc : public IOsc{
public:
	SawOsc(IClockSource *clock, float frequency);
	virtual ~SawOsc();
	virtual void tick() override;
	void setFreq(float freq) override;
private:
	float _step;
};

#endif /* SAWOSC_H_ */
