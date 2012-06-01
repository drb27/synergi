/*
 * audiobuffer.cpp
 *
 *  Created on: May 31, 2012
 *      Author: drb
 */

#include <common/ns.h>
#include <common/types.h>
#include "audiobuffer.h"

s_namespace_2(synergi,engine)

audiobuffer::audiobuffer(uint32_t rate) : sampleRate(rate)
{
	// TODO Auto-generated constructor stub

}

audiobuffer::~audiobuffer() {

	// TODO Auto-generated destructor stub
}

audiobuffer& audiobuffer::operator<<(byte_t* rawBuffer)
{
	return *this;
}


s_namespace_end_2
