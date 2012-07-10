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

puresine::puresine(double freq, uint16_t wvAmplitude, uint16_t wvOffset)
	: sampleRate(44100), sampleIndex(0), tOffset(0.0),
	  frequency(freq), amplitude(wvAmplitude), offset(wvOffset)
{

}

puresine::~puresine()
{

}

void puresine::populate(rawbuffer_t* pBuf)
{
	using dsp::PI;

	double tWavelength = 1.0/frequency;

	uint16_t* pNextSample = (uint16_t*)pBuf->buffer;

	for ( int i = 0 ; i < (pBuf->size/4) ; i++)
	{
		double t = ((double)sampleIndex) / ((double)sampleRate);
		double inter = ((double)offset) + ((double)amplitude) * sin(2.0*PI*frequency*(t+tOffset));

		uint16_t sample = (uint16_t)inter;

		// Insert the samples into the buffer
		*(pNextSample++) = sample;
		*(pNextSample++) = sample;

		sampleIndex++;

		if ( (t+tOffset) > tWavelength)
		{
			tOffset = t + tOffset - tWavelength;
			sampleIndex=1;
		}

	}

}

} /* namespace engine */
} /* namespace synergi */
