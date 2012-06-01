/*
 * audiobuffer.h
 *
 *  Created on: May 31, 2012
 *      Author: drb
 */

#ifndef AUDIOBUFFER_H_
#define AUDIOBUFFER_H_

#include <common/types.h>
#include <common/ns.h>

s_namespace_2(synergi,engine)

class audiobuffer
{

private:
	const uint32_t sampleRate;

public:
	audiobuffer(uint32_t rate);
	virtual ~audiobuffer();
};

s_namespace_end_2

#endif /* AUDIOBUFFER_H_ */

