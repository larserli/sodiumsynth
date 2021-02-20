/*
 * ADSR.h
 *
 *  Created on: Feb 11, 2021
 *      Author: lars
 */

#pragma once
#include "IAudioModule.h"
#include "TimeVariant.h"

class Envelope : public TimeVariant{
public:
	Envelope(IClockSource *clock, float a, float d, float s, float r);
	virtual ~Envelope();
	void KeyDown();
	void KeyUp();
	virtual float get() override;
private:
	enum class state{
		ATTACK,
		DECAY,
		SUSTAIN,
		RELEASE,
	};
	float m_attack;
	float m_decay;
	float m_sustain;
	float m_release;
	float m_time;
	float m_step;
	enum state m_state;
	float m_val;
	void tick() override;
};


