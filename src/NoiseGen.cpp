/*
 * NoiseGen.cpp
 *
 *  Created on: Feb 11, 2021
 *      Author: lars
 */

#include "NoiseGen.h"
#include <cmath>

NoiseGen::NoiseGen() {
	// TODO Auto-generated constructor stub

}

NoiseGen::~NoiseGen() {
	// TODO Auto-generated destructor stub
}


float NoiseGen::get(){
	return ((static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) * 2.0f) - 1.0f;
}
