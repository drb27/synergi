/*
 * source.cpp
 *
 *  Created on: Jun 15, 2012
 *      Author: drb
 */

#include "buf/rawbuffer.h"
#include "component.h"
#include "source.h"

namespace synergi
{
namespace engine
{

source::source() : component()
{
	// TODO Auto-generated constructor stub

}

source::~source()
{
	// TODO Auto-generated destructor stub
}

rawbuffer_t* source::get_src_buffer(uint32_t sampleCount)
{
	// A source generates new buffers (overriding behaviour in outlet)
	return new rawbuffer_t(sampleCount);
}

} /* namespace engine */
} /* namespace synergi */
