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
	IAudioModule *_source;

	float _cutoff;
	float _resonance;

	std::vector<float> _x;
	std::vector<float> _y;
	std::vector<float> _a;
	std::vector<float> _b;

	int _order;

	int _n;

};
