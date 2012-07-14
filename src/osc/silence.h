/*
 * silence.h
 *
 *  Created on: Jun 1, 2012
 *      Author: drb
 */

#ifndef SILENCE_H_
#define SILENCE_H_

#include "common/ns.h"
#include "common/types.h"
#include "oscillator.h"

namespace synergi
{
namespace engine
{

class silence : public oscillator {
public:
	silence(uint16_t offset);
	virtual ~silence();
protected:
	virtual void populate(rawbuffer_t*);
	uint16_t zeroOffset;
};

}
}

#endif /* SILENCE_H_ */
