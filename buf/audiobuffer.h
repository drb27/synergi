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

#define DEFAULT_SAMPLE_RATE 44100

s_namespace_2(synergi,engine)

class audiobuffer
{

private:
	const uint32_t sampleRate;

public:
	audiobuffer(uint32_t rate = DEFAULT_SAMPLE_RATE);
	virtual ~audiobuffer();

	inline uint32_t sample_rate() const { return sampleRate; }

	audiobuffer& operator<<(byte_t* rawBuffer);
};

s_namespace_end_2

#endif /* AUDIOBUFFER_H_ */

