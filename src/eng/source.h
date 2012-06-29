/*
 * source.h
 *
 *  Created on: Jun 15, 2012
 *      Author: drb
 */

#ifndef SOURCE_H_
#define SOURCE_H_

#include "outlet.h"

namespace synergi
{
namespace engine
{

/**
 * Acts as a multi-channel source of samples for a DSP chain.
 */
class source : public outlet
{
public:
	source();
	virtual ~source();

};

} /* namespace engine */
} /* namespace synergi */
#endif /* SOURCE_H_ */
