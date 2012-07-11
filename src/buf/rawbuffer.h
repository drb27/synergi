/*
 * rawbuffer.h
 *
 *  Created on: May 31, 2012
 *      Author: drb
 */

#ifndef RAWBUFFER_H_
#define RAWBUFFER_H_

#include "common/types.h"
#include "common/ns.h"
#include <stdlib.h>

#include <memory.h>

namespace synergi
{
namespace engine
{

struct rawbuffer_t
{
	rawbuffer_t(uint32_t sz);
	rawbuffer_t(const rawbuffer_t& other);

	virtual byte_t* detach(void);

	virtual ~rawbuffer_t();

	byte_t* buffer;
	uint32_t size;
	uint32_t count;
};

}
}

#endif /* RAWBUFFER_H_ */

