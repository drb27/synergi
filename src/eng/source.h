/*
 * source.h
 *
 *  Created on: Jun 15, 2012
 *      Author: drb
 */

#ifndef SOURCE_H_
#define SOURCE_H_

namespace synergi
{
namespace engine
{

/**
 * Acts as a multi-channel source of samples for a DSP chain.
 */
class source
{
public:
	source();
	virtual ~source();

	/// Requests a number of samples from the source.
	/// Note that the returned buffer indicates how many samples are actually returned.
	/// Ownership of the buffer is delegated to the caller, and will not be modified by
	/// subsequent calls to this method.
	/// @param sampleCount
	///		The number of samples requested per channel
	/// @return
	///		Always returns a rawbuffer_t, which contains UP TO the requested number of samples.
	rawbuffer_t* pull(uint32_t sampleCount);

protected:
	virtual void populate(rawbuffer_t* pBuf)=0;
};

} /* namespace engine */
} /* namespace synergi */
#endif /* SOURCE_H_ */
