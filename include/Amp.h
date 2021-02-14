/*
 * Amp.h
 *
 *  Created on: Feb 12, 2021
 *      Author: lars
 */

#ifndef AMP_H_
#define AMP_H_

#include "IAudioModule.h"

class Amp: public IAudioModule {

public:
	Amp();
	virtual ~Amp();
	void SetSource(IAudioModule *source);
	void SetLevel(float level);
	void SetMod(IAudioModule *mod, float level);
	float get() override;

private:
	IAudioModule *_source;
	IAudioModule *_mod;
	float _level;
	float _mod_level;

};

#endif /* AMP_H_ */
