/*
 * outlet.h
 *
 *  Created on: Jun 29, 2012
 *      Author: drb
 */

#ifndef OUTLET_H_
#define OUTLET_H_

namespace synergi {
namespace engine {

#include "component.h"

class outlet : public virtual component
{
public:
	outlet();
	virtual ~outlet();

	/// Requests a number of samples from the source.
	/// Note that the returned buffer indicates how many samples are actually returned.
	/// Ownership of the buffer is delegated to the caller, and will not be modified by
	/// subsequent calls to this method.
	/// @param sampleCount
	///		The number of samples requested per channel
	/// @return
	///		Always returns a rawbuffer_t, which contains UP TO the requested number of samples.
	virtual rawbuffer_t* pull(uint32_t sampleCount);

protected:
	virtual void populate(rawbuffer_t* pBuf)=0;
	virtual rawbuffer_t* get_src_buffer(uint32_t sampleCount)=0;
};

} /* namespace engine */
} /* namespace synergi */
#endif /* OUTLET_H_ */
