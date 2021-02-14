/*
 * NoiseGen.h
 *
 *  Created on: Feb 11, 2021
 *      Author: lars
 */

#ifndef NOISEGEN_H_
#define NOISEGEN_H_
#include "IAudioModule.h"

class NoiseGen : public IAudioModule{
public:
	NoiseGen();
	virtual ~NoiseGen();
	virtual float get() override;
};

#endif /* NOISEGEN_H_ */
