/*
 * audiobuffer.cpp
 *
 *  Created on: May 31, 2012
 *      Author: drb
 */

#include <common/ns.h>
#include <common/types.h>
#include "audiobuffer.h"
#include <stdlib.h>

s_namespace_2(synergi,engine)

audiobuffer::audiobuffer(uint32_t rate, uint32_t sz) : sampleRate(rate), size(sz), latestOp(read)
{
	// Allocate memory for the buffer
	base = (byte_t*)calloc(sz,1);

	// Check for success
	if (!base) throw allocationfailed();

	// We're good ...
	pNextWriteByte = base;
	pNextReadByte = base;

}

audiobuffer::~audiobuffer()
{
	free(base);
}

audiobuffer& audiobuffer::operator<<(const rawbuffer_t& rawBuffer)
{
	return *this;
}

void audiobuffer::insert(byte_t data)
{
	if (!is_full())
	{
		*(pNextWriteByte++) = data;
		if (pNextWriteByte >= (base+size))
			pNextWriteByte=base;
		latestOp = write;
	}
	else
		throw overrun();
}

byte_t audiobuffer::extract(void)
{
	if (!is_empty())
	{
		byte_t retVal = *(pNextReadByte++);
		if (pNextReadByte >= (base+size))
			pNextReadByte=base;
		latestOp = read;
		return retVal;
	}
	else
		throw underrun();
}

uint32_t audiobuffer::length(void) const
{
	if (is_empty()) return 0;
	if (is_full()) return capacity();

	if (pNextWriteByte>pNextReadByte)
	{
		return pNextWriteByte-pNextReadByte;
	}
	else
	{
		return pNextWriteByte+capacity()-pNextReadByte;
	}
}




s_namespace_end_2
