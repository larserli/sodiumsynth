/*
 * IAudioModule.h
 *
 *  Created on: Feb 11, 2021
 *      Author: lars
 */

#pragma once

/** Audio module interface
 * Any module that has an audio level output
 *
 */
class IAudioModule{
public:
	/**Get a sample
	 * @return float [0-1]
	 */
	virtual float get() = 0;
	virtual ~IAudioModule(){};
};




