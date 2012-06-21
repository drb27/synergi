/*
 * basic.h
 *
 *  Created on: May 31, 2012
 *      Author: drb
 */

#ifndef BASIC_H_
#define BASIC_H_

#include "common/types.h"
#include "common/ns.h"
#include <stdlib.h>

s_namespace_2(synergi,engine)

struct rawbuffer_t
{
	rawbuffer_t(uint32_t sz)
	{
		buffer=(byte_t*)calloc(sz,1);
		size=sz;
		count=0;
	}

	virtual byte_t* detach(void)
	{
		if(buffer)
		{
			free(buffer);
			buffer=0;
		}
	}

	virtual ~rawbuffer_t()
	{
		if (buffer)
			free(buffer);
	}

	byte_t* buffer;
	uint32_t size;
	uint32_t count;
};

s_namespace_end_2

#endif /* BASIC_H_ */

