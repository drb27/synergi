/*
 * dsp.cpp
 *
 *  Created on: Jun 15, 2012
 *      Author: drb
 */

#include <math.h>
#include "dsp.h"

namespace synergi
{
namespace engine
{

const double PI = 4.0*atan(1.0);

dsp::dsp()
{
	// TODO Auto-generated constructor stub

}

dsp::~dsp()
{
	// TODO Auto-generated destructor stub
}

rawbuffer_t* dsp::get_src_buffer(uint32_t sampleCount)
{
	// get from the upstream component
	return get_src()->pull(sampleCount);
}

void dsp::populate(rawbuffer_t* pBuf)
{
	// Copy the data pulled from the source into a temporary buffer
	rawbuffer_t tempBuffer(*pBuf);

	// Generate the output into the buffer returned by the source pull
	transform(tempBuffer,pBuf);

	// NOTE: Temporary buffer drops out of scope here, and is automatically cleaned up
}

} /* namespace engine */
} /* namespace synergi */
