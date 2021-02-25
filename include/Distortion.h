/*
 * Distortion.h
 *
 *  Created on: Feb 16, 2021
 *      Author: lars
 */

#pragma once
#include "IAudioModule.h"
#include <memory>
class Amp;

/**
 * Distortion effect.
 * Uses an S-curve function to clip the signal
 */
class Distortion : public IAudioModule{
public:
	Distortion();
	~Distortion();
	/**
	 * Set source (input)
	 */
	void setSource(IAudioModule *source);
	/**
	 *  Set input gain
	 */
	void setGain(float gain);

	float get() override;

private:
	std::shared_ptr<Amp> m_preGain;
};



