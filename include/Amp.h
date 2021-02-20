/*
 * Amp.h
 *
 *  Created on: Feb 12, 2021
 *      Author: lars
 */

#ifndef AMP_H_
#define AMP_H_

#include "IAudioModule.h"

/**
 * Amplifier module.
 * Changes the amplitude of an audio signal
 * Supports modulation input
 *
 */

class Amp: public IAudioModule {

public:
	//Class constructor
	Amp();
	virtual ~Amp();
	/**Assign an input
	 * @param source Audio input
	 */
	void SetSource(IAudioModule *source);
	/**Set gain (level)
	 * @param level [0-..] 1.0 is unity gain
	 */
	void SetLevel(float level);
	/**Set mod source
	 * @param mod Mod source
	 * @param level Mod level
	 */
	void SetMod(IAudioModule *mod, float level);
	/** Get audio output
	 *
	 */
	float get() override;

private:
	IAudioModule *m_source;
	IAudioModule *m_mod;
	float m_level;
	float m_mod_level;

};

#endif /* AMP_H_ */
