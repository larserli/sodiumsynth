/*
 * ADSR.h
 *
 *  Created on: Feb 11, 2021
 *      Author: lars
 */

#pragma once
#include "IAudioModule.h"
#include "TimeVariant.h"

/**
 *  ADSR envelope
 */
class Envelope : public TimeVariant{
public:
	Envelope(IClockSource *clock, float a, float d, float s, float r);
	virtual ~Envelope();
	/**
	 * Key down event
	 */
	void KeyDown();
	/**
	 * Key up event
	 */
	void KeyUp();
	/**
	 * Set attack time (ms)
	 */
	void setAttack(float attack);
	/**
	 * Set decay time (ms)
	 */
	void setDecay(float decay);
	/**
	 * Set sustain level [0-1]
	 */
	void setSustain(float sustain);
	/**
	 * Set release time (ms)
	 */
	void setRelease(float release);
	/**
	 * Return attack time (ms)
	 */
	float getAttack();
	/**
	 * Return decay time (ms)
	 */
	float getDecay();
	/**
	 * Return sustain level [0-1]
	 */
	float getSustain();
	/**
	 * Return release time (ms)
	 */
	float getRelease();
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
	float m_t;
	enum state m_state;
	float m_val;
	void tick() override;
};


