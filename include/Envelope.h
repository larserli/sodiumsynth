/*
 * ADSR.h
 *
 *  Created on: Feb 11, 2021
 *      Author: lars
 */

#pragma once
#include "IAudioModule.h"
#include "TimeVariant.h"

class Envelope : public IAudioModule, public TimeVariant{
public:
	Envelope(IClockSource *clock, float a, float d, float s, float r);
	virtual ~Envelope();
	void KeyDown();
	void KeyUp();
	virtual float get() override;
private:
	enum class state{
		ATTACK,
		SUSTAIN,
		OFF,
	};
	float _attack;
	float _decay;
	float _sustain;
	float _release;
	float _time;
	float _step;
	//enum state _state;
};


