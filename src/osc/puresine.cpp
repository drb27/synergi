/*
 * puresine.cpp
 *
 *  Created on: Jun 2, 2012
 *      Author: drb
 */

#include "dsp/dsp.h"
#include "puresine.h"
#include <math.h>
#include <iostream>

namespace synergi {
namespace engine {

using dsp::PI;

puresine::puresine(double freq, uint16_t wvAmplitude, uint16_t wvOffset)
	: sampleRate(44100), phase(0.0), frequency(freq), amplitude(wvAmplitude), offset(wvOffset)
{
	// TODO Auto-generated constructor stub

}

puresine::~puresine() {
	// TODO Auto-generated destructor stub
}

void puresine::populate(rawbuffer_t* pBuf)
{
	uint16_t* pNextSample = (uint16_t*)pBuf->buffer;
	for ( int i = 0 ; i < (pBuf->size/4) ; i++)
	{
		phase+=2*PI*(1.0/(double)sampleRate);
		double inter = offset + (((double)amplitude) * sin(frequency*phase));
		double inter2 = inter;
		uint16_t sample = (uint16_t)inter;
		uint16_t sample2 = (uint16_t)inter2;

		// Insert the samples into the buffer
		*(pNextSample++) = sample;
		*(pNextSample++) = sample2;

		if (phase >= PI*2.0) phase=0;
	}

}

} /* namespace engine */
} /* namespace synergi */
