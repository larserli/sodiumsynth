/*
 * LPFilter.cpp
 *
 *  Created on: Feb 14, 2021
 *      Author: lars
 */

#include "LPFilter.h"

LPFilter::LPFilter(IClockSource *clock) : TimeVariant(clock){
	m_n = 0;
	m_order = 0;
}

LPFilter::~LPFilter(){

}

void LPFilter::tick(){
	m_x[m_n] = m_source->get();

	m_y[m_n] = 0.0f;
	for(size_t i=0;i<m_b.size();i++){
		int z = m_n - i;
		if(z < 0){
			z+=m_x.size();
		}
		m_y[m_n] += m_b[i] * m_x[z];
	}
	for(size_t i=1;i<m_b.size();i++){
		int p = m_n - i;
		if(p < 0){
			p+=m_y.size();
		}
		m_y[m_n] += m_a[i] * m_y[p];
	}
	m_out = m_y[m_n];
	m_n++;
	if(m_n > m_order){
		m_n = 0;
	}
}


