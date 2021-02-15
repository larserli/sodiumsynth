/*
 * Midi.h
 *
 *  Created on: Feb 14, 2021
 *      Author: lars
 */

#ifndef INCLUDE_MIDI_H_
#define INCLUDE_MIDI_H_
#include <string>


class Midi{
	/** Convert a MIDI note value to frequency
	 *
	 */
	static float ToFreq(unsigned int note);
	/** Convert a note value to frequency
	 *
	 */
	static float ToFreq(std::string note);
};


#endif /* INCLUDE_MIDI_H_ */
