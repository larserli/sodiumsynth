/*
 * SquareOsc.h
 *
 *  Created on: Feb 11, 2021
 *      Author: lars
 */

#ifndef SQUAREOSC_H_
#define SQUAREOSC_H_
#include "IOsc.h"
/**
 * Square wave oscillator, supports pulse width modulation (PWM)
 */
class SquareOsc : public IOsc{
public:
	SquareOsc(IClockSource *clock, float frequency);
	virtual ~SquareOsc();
	void setFreq(float freq) override;
	void tick() override;
	/**
	 * Set pulse with modulation
	 * @param mod Modulation source
	 * @param depth Modulation depth
	 */
	void SetPWMod(IOsc *mod, float depth);
private:

	float m_prd_low;
	float m_prd;
	IOsc *m_pwMod;
	float m_pwModDepth;
};

#endif /* SQUAREOSC_H_ */
