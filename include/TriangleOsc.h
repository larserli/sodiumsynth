/*
 * TriangleOsc.h
 *
 *  Created on: Feb 14, 2021
 *      Author: lars
 */

#ifndef INCLUDE_TRIANGLEOSC_H_
#define INCLUDE_TRIANGLEOSC_H_

#include "IOsc.h"

/**
 * Triangle oscillator
 */
class TriangleOsc: public IOsc{
public:
	TriangleOsc(IClockSource *clock);
	TriangleOsc(IClockSource *clock, float freq);
	virtual ~TriangleOsc();
	void setFreq(float freq) override;
	void tick() override;
private:
	float calcStep(float freq);
	float m_step;
	int m_state;
};


#endif /* INCLUDE_TRIANGLEOSC_H_ */
