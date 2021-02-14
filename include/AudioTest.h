/*
 * AudioTest.h
 *
 *  Created on: Feb 7, 2021
 *      Author: lars
 */

#ifndef AUDIOTEST_H_
#define AUDIOTEST_H_

#include "portaudio.h"
#include "IClockSource.h"
#include <exception>
#include <string>
#include <list>
#include <vector>
#include "IAudioModule.h"

class AudioTest : public IClockSource{
public:
	AudioTest();
	void Init(IAudioModule *lSrc, IAudioModule *rSrc);
	void Stop();
	static AudioTest *Instance();
	virtual ~AudioTest();
	static int paTestCallback(const void* inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags, void *userData);

	int GetSampleRate();
private:
	IAudioModule *_lSrc;
	IAudioModule *_rSrc;
	bool _running;
	int _sample_rate;
	int _frames_per_buffer;
	static AudioTest *_instance;
};

class AudioException : public std::exception{
public:
	AudioException(std::string msg):_msg(msg){}
	virtual const char *what() const noexcept override{return _msg.c_str();}
private:
	std::string _msg;
};

#endif /* AUDIOTEST_H_ */
