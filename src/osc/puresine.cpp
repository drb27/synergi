/*
 * puresine.cpp
 *
 *  Created on: Jun 2, 2012
 *      Author: drb
 */

#include "puresine.h"
#include <math.h>
#include <iostream>

namespace synergi {
namespace engine {

puresine::puresine() :sampleRate(44100), phase(0), samplesPerCycle(100)
{
	// TODO Auto-generated constructor stub

}

puresine::~puresine() {
	// TODO Auto-generated destructor stub
}

void puresine::synthesize(circularbuffer<uint16_t>& buffer, uint32_t samples)
{
	// STUB Generate a 440Hz tone (A)
	const double amplitude = 8000.0;

	for ( int i = 0 ; i < samples ; i++)
	{
		double x = (phase++) / (double)samplesPerCycle;
		double inter = 32000+ (amplitude * sin(2.0*3.142*x));
		double inter2 = 32000+ (amplitude * sin(2.0*3.142*x));
		uint16_t sample = (uint16_t)inter;
		uint16_t sample2 = (uint16_t)inter2;
		buffer.insert(sample);	// Right channel
		buffer.insert(sample2); 	// Left channel

		if (phase >= samplesPerCycle) phase=0;
	}

}

} /* namespace engine */
} /* namespace synergi */
