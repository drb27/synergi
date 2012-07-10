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
	silence();
	virtual ~silence();
	virtual void synthesize(circularbuffer<uint16_t>&,uint32_t);
};

}
}

#endif /* SILENCE_H_ */
