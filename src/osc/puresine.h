/*
 * puresine.h
 *
 *  Created on: Jun 2, 2012
 *      Author: drb
 */

#ifndef PURESINE_H_
#define PURESINE_H_

#include "oscillator.h"

// Hi

namespace synergi {
namespace engine {

class puresine: public synergi::engine::oscillator {
public:
	puresine();
	virtual ~puresine();

	//virtual void synthesize(circularbuffer<uint16_t>&, uint32_t);
	virtual void populate(rawbuffer_t* pbuf);

protected:
	uint32_t phase;
	const uint32_t sampleRate;
	const uint32_t samplesPerCycle;
};

} /* namespace engine */
} /* namespace synergi */
#endif /* PURESINE_H_ */
