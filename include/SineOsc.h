/*
 * SineOsc.h
 *
 *  Created on: Feb 11, 2021
 *      Author: lars
 */

#ifndef SINEOSC_H_
#define SINEOSC_H_
#include "IOsc.h"

/**
 * Sine wave oscillator
 */
class SineOsc : public IOsc{
public:
	SineOsc(IClockSource *clock, float frequency);
	virtual ~SineOsc();
	void tick() override;
	void setFreq(float freq) override;
private:
	float m_step;
};

#endif /* SINEOSC_H_ */
