/*
 * tremolo.h
 *
 *  Created on: Jul 1, 2012
 *      Author: drb
 */

#ifndef TREMOLO_H_
#define TREMOLO_H_

#include "dsp.h"
#include "osc/puresine.h"

namespace synergi {
namespace dsp {

class tremolo: public synergi::dsp::dsp
{
public:
	tremolo(outlet& srcOutlet, double freq, double strength);
	virtual ~tremolo();

	virtual void transform(const rawbuffer_t& pSrc, rawbuffer_t* pDest) const;

protected:
	double lfoFreq;
	double modStrength;

	engine::puresine* pLFO;
};

} /* namespace dsp */
} /* namespace synergi */
#endif /* TREMOLO_H_ */
