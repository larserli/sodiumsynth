/*
 * Mixer.h
 *
 *  Created on: Feb 13, 2021
 *      Author: lars
 */

#ifndef MIXER_H_
#define MIXER_H_
#include <list>
#include "IAudioModule.h"
class Mixer : public IAudioModule{
public:
	Mixer();
	virtual ~Mixer();
	virtual float get() override;
	void AddChannel(IAudioModule *channel, float level);
	void RemoveChannel(IAudioModule *channel);
	void SetLevel(IAudioModule *channel, float level);
private:
	struct channel{
		IAudioModule *source;
		float level;
	};
	std::list<struct channel> _channels;
};

#endif /* MIXER_H_ */
