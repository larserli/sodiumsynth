/*
 * Filter.h
 *
 *  Created on: Feb 26, 2021
 *      Author: lars
 */

#pragma once
#include "IAudioModule.h"
#include "TimeVariant.h"
#include <vector>

class Filter : public TimeVariant
{
public:
	enum class FilterType{
		LOWPASS,
		HIGHPASS
	};

	Filter(IClockSource *clock, FilterType type = FilterType::LOWPASS);
	virtual ~Filter();
	void setSource(IAudioModule *source);
	void setCutoff(float fc);

	void setMod(IAudioModule *modSource, float sourceLo = 0.0f, float sourceHi=1.0f, float offset=0.0f);
	void tick() override;
private:
	float m_a1;
	float m_a2;
	float m_b0;
	float m_b1;
	float m_b2;
	float m_fc;
	void calcCoefficients(float fc);
	FilterType m_type;

	std::vector<float> m_x;
	std::vector<float> m_y;

	IAudioModule *m_source;

	IAudioModule *m_modSource;
	float m_modsourceLo;
	float m_modsourceHi;
	float m_modOffset;


};


