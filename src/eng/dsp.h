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

class dsp : public inlet, outlet
{
public:
	dsp();
	virtual ~dsp();
protected:
	virtual void populate(rawbuffer_t* pBuf);
};

} /* namespace engine */
} /* namespace synergi */
#endif /* DSP_H_ */
