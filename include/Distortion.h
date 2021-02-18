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

class Distortion : public IAudioModule{
public:
	Distortion();
	~Distortion();
	void setSource(IAudioModule *source);
	void setGain(float gain);
	float get() override;

private:
	std::shared_ptr<Amp> m_preGain;
};



