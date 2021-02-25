#pragma once
#include "TimeVariant.h"
#include <string>
#include <vector>

class Sequencer : public TimeVariant
{
public: 
	Sequencer(IClockSource *clock);
	Sequencer(IClockSource* clock, std::vector<int> sequence);
	Sequencer(IClockSource* clock, std::vector<std::string> sequence);
	void setSequence(std::vector<int> sequence);
	void setSequence(std::vector<std::string> sequence);
	virtual ~Sequencer();
	void tick() override;
private:
	std::vector<float> m_sequence;
	size_t m_at;
};
