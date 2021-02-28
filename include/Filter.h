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

/** Lowpass or highpass filter
 *
 */
class Filter : public TimeVariant
{
public:
	enum class FilterType{
		LOWPASS,
		HIGHPASS
	};

	/** Class constructor
	 * @param clock sample clock source
	 * @param type Filter type (lowpass or highpass)
	 */
	Filter(IClockSource *clock, FilterType type = FilterType::LOWPASS);
	virtual ~Filter();
	/** Set input (source)
	 * @param source
	 */
	void setSource(IAudioModule *source);
	/** Set the filter cutoff frequency (Fc)
	 * @param fc Cutoff frequency (Hz)
	 */
	void setCutoff(float fc);
	/** Assing a modulator
	 *
	 * Modulation source will control the cutoff frequency between offset and the assigned cutoff frequency
	 *
	 * @param modSource Modulation source
	 * @param sourceLo Source signal range (low)
	 * @param sourceHi Source signal range (high)
	 * @param offset Modulation offset
	 */
	void setMod(IAudioModule *modSource, float sourceLo = 0.0f, float sourceHi=1.0f, float offset=0.0f);
	/** Update filter
	 *
	 */
	void tick() override;
private:
	//Filter coefficients
	float m_a1;
	float m_a2;
	float m_b0;
	float m_b1;
	float m_b2;
	float m_fc;
	/** Calculate the filter coefficients
	 * @param fc Cutoff frequency
	 */
	void calcCoefficients(float fc);
	///Filter type
	FilterType m_type;

	std::vector<float> m_x;
	std::vector<float> m_y;

	IAudioModule *m_source;

	IAudioModule *m_modSource;
	float m_modsourceLo;
	float m_modsourceHi;
	float m_modOffset;


};


