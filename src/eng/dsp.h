/*
 * dsp.h
 *
 *  Created on: Jun 15, 2012
 *      Author: drb
 */

#ifndef DSP_H_
#define DSP_H_

#include "buf/basic.h"
#include "component.h"
#include "inlet.h"
#include "outlet.h"

namespace synergi
{
namespace engine
{

extern const double PI;

class dsp : public inlet, public outlet
{
public:
	dsp();
	virtual ~dsp();
protected:
	virtual void populate(rawbuffer_t* pBuf);
	virtual rawbuffer_t* get_src_buffer(uint32_t sampleCount);
	virtual void transform(const rawbuffer_t& pSrc, rawbuffer_t* pDest)=0;

};

} /* namespace engine */
} /* namespace synergi */
#endif /* DSP_H_ */
