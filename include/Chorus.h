/*
 * Chorus.h
 *
 *  Created on: Feb 14, 2021
 *      Author: lars
 */

#ifndef INCLUDE_CHORUS_H_
#define INCLUDE_CHORUS_H_
#include "IAudioModule.h"
#include "IClockSource.h"
#include "IOsc.h"
#include <vector>
#include <memory>

class Chorus: public TimeVariant{
public:
	Chorus(IClockSource *clock);
	virtual ~Chorus();
	void setSource(IAudioModule *source);
	void setModDepth(float depth);
	void setModRate(float freq);
	void setMix(float mix);
	void tick() override;

private:
	std::shared_ptr<IOsc>m_osc;
	float m_mod_depth;
	float m_delay;
	float m_base_delay;
	float m_max_delay;
	float m_mix;
	std::vector<float> m_buffer;
	size_t m_put_at;
	IAudioModule *m_source;


};



#endif /* INCLUDE_CHORUS_H_ */
