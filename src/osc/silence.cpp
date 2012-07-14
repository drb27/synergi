/*
 * silence.cpp
 *
 *  Created on: Jun 1, 2012
 *      Author: drb
 */

#include "common/ns.h"
#include "common/types.h"
#include "buf/circularbuffer.h"
#include "silence.h"

namespace synergi
{
namespace engine
{

silence::silence(uint16_t offset) : zeroOffset(offset)
{

}

silence::~silence() {
	// TODO Auto-generated destructor stub
}

void silence::populate(rawbuffer_t* pBuf)
{

	uint16_t* pNextSample = (uint16_t*)pBuf->buffer;

	for ( int i = 0 ; i < (pBuf->size/4) ; i++)
	{

		// Insert the samples into the buffer
		*(pNextSample++) = zeroOffset;
		*(pNextSample++) = zeroOffset;

	}

}

}
}
