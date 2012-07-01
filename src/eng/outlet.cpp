/*
 * outlet.cpp
 *
 *  Created on: Jun 29, 2012
 *      Author: drb
 */

#include "buf/basic.h"
#include "component.h"
#include "outlet.h"

namespace synergi {
namespace engine {

outlet::outlet() {
	// TODO Auto-generated constructor stub

}

outlet::~outlet() {
	// TODO Auto-generated destructor stub
}

rawbuffer_t* outlet::pull(uint32_t sampleCount)
{
	rawbuffer_t* pBuf = new rawbuffer_t(sampleCount);
	populate(pBuf);
	return pBuf;
}

} /* namespace engine */
} /* namespace synergi */
