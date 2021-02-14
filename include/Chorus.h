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
	std::shared_ptr<IOsc>_osc;
	float _mod_depth;
	float _delay;
	float _base_delay;
	float _max_delay;
	float _mix;
	std::vector<float> _buffer;
	size_t _put_at;
	IAudioModule *_source;


};



#endif /* INCLUDE_CHORUS_H_ */
