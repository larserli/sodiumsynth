/*
 * Midi.h
 *
 *  Created on: Feb 14, 2021
 *      Author: lars
 */

#ifndef INCLUDE_MIDI_H_
#define INCLUDE_MIDI_H_
#include <string>

/**
 * Midi functions
 */
class Midi{
public:
	/** Convert a MIDI note value to frequency
	 *
	 */
	static float ToFreq(unsigned int note);
	/** Convert a note value to frequency
	 * Note values are stored on the following format:
	 * Note - Modifier - Octave
	 *
	 * Example:
	 * - G#5
	 * - A3
	 * - Bb6
	 *
	 */
	static float ToFreq(std::string note);
};


#endif /* INCLUDE_MIDI_H_ */
