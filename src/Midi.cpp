/*
 * Midi.cpp
 *
 *  Created on: Feb 14, 2021
 *      Author: lars
 */
#include "Midi.h"
#include <map>
#include <vector>
#include <cmath>

/** Frequency of all notes in the lowest octave playable in MIDI
 * Higher octaves can be calculated with 2^octave * note
 */
std::vector<float> notemap = {
	8.17578125,		//C
	8.661953125,	//C#
	9.17703125,		//D
	9.722734375,	//D#
	10.300859375,	//E
	10.913359375,	//F
	11.56234375,	//F#
	12.24984375,	//G
	12.97828125,	//G#
	13.75,			//A
	14.56765625,	//A#
	15.433828125	//B
};

float Midi::ToFreq(unsigned int note){
	int oct = note / 12;
	int n = note - (oct * 12);
	return  (1 << (oct)) *  notemap[n];
}

float Midi::ToFreq(std::string note){
	int pos = 0;
	char n = note[pos++];
	int notevalue = 0;
	if(n == 'A'){
		notevalue = 9;
	}else if(n=='B'){
		notevalue = 11;
	}else if(n=='C'){
		notevalue = 0;
	}else if(n=='D'){
		notevalue = 2;
	}else if(n=='E'){
		notevalue = 4;
	}else if(n=='F'){
		notevalue = 5;
	}else if(n=='G'){
		notevalue = 7;
	}

	if(note.length() == 3){
		if(note[pos] == '#'){
			notevalue += 1;
		}else if(note[pos] == 'b'){
			notevalue -= 1;
		}
		pos++;
	}
	int octave = static_cast<int>(note[pos]) - '0';
	notevalue += ((octave + 1) * 12);
	return ToFreq(notevalue);
}

