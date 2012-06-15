/*
 * source.cpp
 *
 *  Created on: Jun 15, 2012
 *      Author: drb
 */

#include "buf/basic.h"
#include "source.h"

namespace synergi
{
namespace engine
{

source::source()
{
	// TODO Auto-generated constructor stub

}

source::~source()
{
	// TODO Auto-generated destructor stub
}

rawbuffer_t* source::pull(uint32_t sampleCount)
{
	rawbuffer_t* pBuf = new rawbuffer_t(sampleCount);
	populate(pBuf);
	return pBuf;
}

} /* namespace engine */
} /* namespace synergi */
