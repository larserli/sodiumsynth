/*
 * Filter.cpp
 *
 *  Created on: Feb 26, 2021
 *      Author: lars
 */

#include "Filter.h"
#include <cmath>

Filter::Filter(IClockSource *clock, FilterType type) : TimeVariant(clock)
{
	m_a1 = m_a2 = 0.0f;
	m_b0 = m_b1 = m_b2 = 0.0f;
	m_x = {0.0f, 0.0f, 0.0f};
	m_y = {0.0f, 0.0f, 0.0f};
	m_source = nullptr;
	m_type = type;
	m_modSource = nullptr;
	m_modsourceLo = 0.0f;
	m_modsourceHi = 1.0f;
	m_modOffset = 0.0f;
	m_fc = 0.0f;
}

Filter::~Filter()
{

}

void Filter::setSource(IAudioModule *source)
{
	m_source = source;
}

void Filter::setMod(IAudioModule *modSource, float sourceLo, float sourceHi, float offset)
{

	m_modsourceLo = sourceLo;
	m_modsourceHi = sourceHi;
	m_modOffset = offset;
	m_modSource = modSource;
}

void Filter::setCutoff(float fc){
	m_fc = fc;
	calcCoefficients(m_fc);
}

void Filter::calcCoefficients(float fc)
{
	fc = (fc < 10.0f) ? 10.0f : fc;
	//fc = (fc < 0.0f) ? -fc : fc;

	//Normalized cutoff frequency
	float ff = (fc / m_clock_freq);

	//Pre warped cutoff frequency
	float ita = 1.0f / tanf(ff * M_PI);

	//Parameters for second order butterworth filter
	m_b0 = 1.0f / (1.0f + M_SQRT2*ita + ita*ita);
	m_b1 = m_b0 * 2;
	m_b2 = m_b0;
	m_a1 = 2.0f * (ita*ita - 1.0f) * m_b0;
	m_a2 = -(1.0f - M_SQRT2*ita + ita*ita) * m_b0;

	//Convert coefficients for high pass mode
	if(m_type == FilterType::HIGHPASS)
	{
		m_b0 = m_b0 * ita* ita;
		m_b1 = -(m_b1 * ita * ita);
		m_b2 = m_b2 * ita * ita;
	}
}

void Filter::tick(){
	if(m_source == nullptr){
		m_out = 0.0f;
		return;
	}
	if(m_modSource != nullptr)
	{
		float fc = ((m_modSource->get() - m_modsourceLo) / (m_modsourceHi - m_modsourceLo))* (m_fc - m_modOffset) + m_modOffset;
		calcCoefficients(fc);
	}
	m_x[2] = m_x[1];
	m_x[1] = m_x[0];
	m_x[0] = m_source->get();

	m_y[2] = m_y[1];
	m_y[1] = m_y[0];
	m_y[0] = m_b0 * m_x[0] + m_b1 * m_x[1] + m_b2 * m_x[2] + m_a1 * m_y[1] + m_a2 * m_y[2];
	m_out = m_y[0];
}
