/*
 * sink.h
 *
 *  Created on: Jun 15, 2012
 *      Author: drb
 */

#ifndef SINK_H_
#define SINK_H_

#include "inlet.h"

namespace synergi
{
namespace engine
{

class sink : public inlet
{
public:
	sink();
	virtual ~sink();
};

} /* namespace engine */
} /* namespace synergi */
#endif /* SINK_H_ */
