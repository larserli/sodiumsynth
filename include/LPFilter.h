#pragma once
#include "IAudioModule.h"
#include "TimeVariant.h"
#include <vector>

class LPFilter : public TimeVariant{
public:
	LPFilter(IClockSource *clock);
	virtual ~LPFilter();
	void setSource(IAudioModule *source);
	void setCutoff(float cutoff);
	void tick() override;


private:
	IAudioModule *m_source;

	float m_cutoff;
	float m_resonance;

	std::vector<float> m_x;
	std::vector<float> m_y;
	std::vector<float> m_a;
	std::vector<float> m_b;

	int m_order;

	int m_n;

};
