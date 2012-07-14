/*
 * dsp.h
 *
 *  Created on: Jun 15, 2012
 *      Author: drb
 */

#ifndef DSP_H_
#define DSP_H_

#include "buf/rawbuffer.h"
#include "eng/eng.h"

namespace synergi
{
namespace dsp
{

using synergi::engine::rawbuffer_t;
using synergi::engine::inlet;
using synergi::engine::outlet;

extern const double PI;

class dsp : public inlet, public outlet
{
public:
	dsp(outlet& sourceOutlet );
	virtual ~dsp();
protected:
	virtual void populate(rawbuffer_t* pBuf);
	virtual rawbuffer_t* get_src_buffer(uint32_t sampleCount);
	virtual void transform(const rawbuffer_t& pSrc, rawbuffer_t* pDest) const =0;

	dsp();

};

} /* namespace engine */
} /* namespace synergi */
#endif /* DSP_H_ */