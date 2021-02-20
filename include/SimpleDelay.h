/*
 * SimpleDelay.h
 *
 *  Created on: Feb 13, 2021
 *      Author: lars
 */

#ifndef SIMPLEDELAY_H_
#define SIMPLEDELAY_H_

#include "IAudioModule.h"
#include "TimeVariant.h"
#include <vector>

class SimpleDelay: public TimeVariant {
public:
	SimpleDelay(IClockSource *clock);
	virtual ~SimpleDelay();
	//TIme in ms
	void SetTime(unsigned long time);
	//Delay feedback [0-1]
	void SetFeedback(float feedback);
	//Delay mix [0-1]
	void SetMix(float mix);
	//Input
	void SetSource(IAudioModule* source);
	//Update
	void tick() override;

private:
	unsigned long m_delay_time;
	float m_feedback;
	float m_mix;
	std::vector<float> m_buffer;
	IAudioModule *m_source;
	size_t m_get_at;
	size_t m_put_at;
};

#endif /* SIMPLEDELAY_H_ */
