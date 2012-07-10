/*
 * puresine.h
 *
 *  Created on: Jun 2, 2012
 *      Author: drb
 */

#ifndef PURESINE_H_
#define PURESINE_H_

#include "oscillator.h"

namespace synergi { namespace test {
class PuresineTest;
} }

namespace synergi {
namespace engine {

class puresine: public synergi::engine::oscillator {
public:
	puresine(double freq, uint16_t wvAmplitude, uint16_t wvOffset);
	virtual ~puresine();

	virtual void populate(rawbuffer_t* pbuf);

protected:
	uint32_t sampleIndex;
	double tOffset;
	const uint32_t sampleRate;
	const double frequency;
	const uint16_t amplitude;
	const uint16_t offset;

	friend class synergi::test::PuresineTest;
};

} /* namespace engine */
} /* namespace synergi */
#endif /* PURESINE_H_ */
