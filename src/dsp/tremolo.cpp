/*
 * tremolo.cpp
 *
 *  Created on: Jul 1, 2012
 *      Author: drb
 */

#include "tremolo.h"

namespace synergi {
namespace dsp {

tremolo::tremolo(outlet& srcOutlet, double freq, double strength)
	:dsp(srcOutlet), lfoFreq(freq), modStrength(strength)
{
	// TODO Auto-generated constructor stub
	pLFO = new engine::puresine(freq,strength*100,strength*100);

}

tremolo::~tremolo() {
	// TODO Auto-generated destructor stub
	delete pLFO;
}

void tremolo::transform(const rawbuffer_t& pSrc, rawbuffer_t* pDest) const
{
	// First, pull samples from the LFO
	rawbuffer_t* pLFOBuf = pLFO->pull(pSrc.size);

	// Now modulate the output with the LFO
	for ( uint32_t index = 0 ; index <= pSrc.size/2 ; index++)
	{
		double sample = (double)(((uint16_t*)(pDest->buffer))[index])-32000.0;
		double multiplier = (double)(((uint16_t*)(pLFOBuf->buffer))[index]);
		multiplier -= 100.0;
		multiplier /= 100.0;

		((uint16_t*)(pDest->buffer))[index] = 32000 + (uint16_t)(sample*0.5 + (0.5*(sample*(1.0+multiplier))));

	}

	delete pLFOBuf;

}


} /* namespace dsp */
} /* namespace synergi */
