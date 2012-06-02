/*
 * silence.h
 *
 *  Created on: Jun 1, 2012
 *      Author: drb
 */

#ifndef SILENCE_H_
#define SILENCE_H_

#include <common/ns.h>
#include <common/types.h>
#include "oscillator.h"

s_namespace_2(synergi,engine)

class silence : public oscillator {
public:
	silence();
	virtual ~silence();
	virtual void synthesize(circularbuffer&,uint32_t);
};

s_namespace_end_2

#endif /* SILENCE_H_ */
