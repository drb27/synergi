/*
 * unitygain.cpp
 *
 *  Created on: Jul 1, 2012
 *      Author: drb
 */

#include "unitygain.h"

namespace synergi {

namespace dsp {

unitygain::unitygain()
{

}

unitygain::unitygain(engine::outlet& srcOutlet) : dsp(srcOutlet)
{
	// TODO Auto-generated constructor stub

}

unitygain::~unitygain() {
	// TODO Auto-generated destructor stub
}

void unitygain::transform(const rawbuffer_t& pSrc, rawbuffer_t* pDest) const
{
	// Simply copy the source into the destination. Done.
	// OPTIMISATION: As the destination already contains the source on entry, do nothing.
}

} /* namespace dsp */
} /* namespace synergi */
