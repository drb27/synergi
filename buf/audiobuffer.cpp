/*
 * audiobuffer.cpp
 *
 *  Created on: May 31, 2012
 *      Author: drb
 */

#include <common/ns.h>
#include "audiobuffer.h"

namespace
{
	const uint32_t DefaultSampleRate = 44100;
}

s_namespace_2(synergi,engine)

audiobuffer::audiobuffer(uint32_t rate = DefaultSampleRate) : sampleRate(rate)
{
	// TODO Auto-generated constructor stub

}

audiobuffer::~audiobuffer() {
	// TODO Auto-generated destructor stub
}

s_namespace_end_2
