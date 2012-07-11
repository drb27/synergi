/*
 * rawbuffer.cpp
 *
 *  Created on: Jul 10, 2012
 *      Author: drb
 */

#include "common/types.h"
#include <stdlib.h>
#include <memory.h>
#include "rawbuffer.h"

namespace synergi
{
namespace engine
{

rawbuffer_t::rawbuffer_t(uint32_t sz)
{
	buffer=(byte_t*)calloc(sz,1);
	size=sz;
	count=0;
}

rawbuffer_t::rawbuffer_t(const rawbuffer_t& other)
{
	// Set up an identical buffer
	buffer=(byte_t*)malloc(other.size);
	size=other.size;
	count = other.count;

	// Copy the contents
	memcpy(buffer,other.buffer,size);
}

rawbuffer_t::~rawbuffer_t()
{
	if (buffer)
		free(buffer);
}

byte_t* rawbuffer_t::detach(void)
{
	byte_t* retVal = buffer;

	if(buffer)
	{
		free(buffer);
		buffer=0;
	}

	return retVal;
}

}
}


