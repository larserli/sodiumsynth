/*
 * Distortion.cpp
 *
 *  Created on: Feb 16, 2021
 *      Author: lars
 */
#include "Distortion.h"
#include "Amp.h"
#include <cmath>


Distortion::Distortion(){
	m_preGain = std::shared_ptr<Amp>(new Amp());
}

Distortion::~Distortion(){

}

void Distortion::setSource(IAudioModule *source){
	m_preGain->SetSource(source);
}

void Distortion::setGain(float gain){
	m_preGain->SetLevel(gain);
}

float Distortion::get(){
	return tanh(m_preGain->get());
}


