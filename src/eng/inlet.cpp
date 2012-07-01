/*
 * inlet.cpp
 *
 *  Created on: Jul 1, 2012
 *      Author: drb
 */

#include "common/types.h"
#include "component.h"
#include "inlet.h"

namespace synergi {
namespace engine {

inlet::inlet(outlet* parentSource) : component()
{
	datasource = parentSource;
}

} /* namespace engine */
} /* namespace synergi */
