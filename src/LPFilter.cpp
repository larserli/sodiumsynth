/*
 * LPFilter.cpp
 *
 *  Created on: Feb 14, 2021
 *      Author: lars
 */

#include "LPFilter.h"

LPFilter::LPFilter(IClockSource *clock) : TimeVariant(clock){
	_n = 0;
	_order = 0;
}

LPFilter::~LPFilter(){

}

void LPFilter::tick(){
	_x[_n] = _source->get();

	_y[_n] = 0.0f;
	for(int i=0;i<_b.size();i++){
		int z = _n - i;
		if(z < 0){
			z+=_x.size();
		}
		_y[_n] += _b[i] * _x[z];
	}
	for(int i=1;i<_b.size();i++){
		int p = _n - i;
		if(p < 0){
			p+=_y.size();
		}
		_y[_n] += _a[i] * _y[p];
	}
	_out = _y[_n];
	_n++;
	if(_n > _order){
		_n = 0;
	}
}


