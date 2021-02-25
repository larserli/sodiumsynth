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
/**
 * Mix down inputs
 */
class Mixer : public IAudioModule{
public:
	Mixer();
	virtual ~Mixer();
	float get() override;
	/**
	 * Add a channel to the mixer
	 */
	void AddChannel(IAudioModule *channel, float level);
	/**
	 * Remove a channel from the mixer
	 */
	void RemoveChannel(IAudioModule *channel);
	/**
	 * Adjust channel level
	 */
	void SetLevel(IAudioModule *channel, float level);
private:
	struct channel{
		IAudioModule *source;
		float level;
	};
	std::list<struct channel> m_channels;
};

#endif /* MIXER_H_ */
