/*
 * SquareOsc.h
 *
 *  Created on: Feb 11, 2021
 *      Author: lars
 */

#ifndef SQUAREOSC_H_
#define SQUAREOSC_H_
#include "IOsc.h"
class SquareOsc : public IOsc{
public:
	SquareOsc(IClockSource *clock, float frequency);
	virtual ~SquareOsc();
	void setFreq(float freq) override;
	virtual void tick() override;
	void SetPWMod(IOsc *mod, float depth);
private:
	float _prd_low;
	float _prd;
	IOsc *_pwMod;
	float _pwModDepth;
};

#endif /* SQUAREOSC_H_ */
