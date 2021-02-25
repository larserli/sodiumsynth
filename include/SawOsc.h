/*
 * SawOsc.h
 *
 *  Created on: Feb 11, 2021
 *      Author: lars
 */

#ifndef SAWOSC_H_
#define SAWOSC_H_
#include "IOsc.h"

/**
 * Sawtooth (ramp) oscillator
 */
class SawOsc : public IOsc{
public:
	SawOsc(IClockSource *clock, float frequency);
	SawOsc(IClockSource *clock);
	virtual ~SawOsc();
	void tick() override;
	void setFreq(float freq) override;
private:
	float m_step;
};

#endif /* SAWOSC_H_ */
