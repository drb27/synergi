/*
 * unitygain.h
 *
 *  Created on: Jul 1, 2012
 *      Author: drb
 */

#ifndef UNITYGAIN_H_
#define UNITYGAIN_H_

#include "dsp.h"

namespace synergi {
namespace dsp {

class unitygain: public dsp
{
public:
	unitygain(engine::outlet& srcOutlet);
	virtual ~unitygain();

	virtual void transform(const rawbuffer_t& pSrc, rawbuffer_t* pDest) const;

};

} /* namespace dsp */
} /* namespace synergi */
#endif /* UNITYGAIN_H_ */
