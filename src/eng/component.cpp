/*
 * component.cpp
 *
 *  Created on: Jul 1, 2012
 *      Author: drb
 */

#include "component.h"

namespace synergi {
namespace engine {

component::component()
{
	construct("<Unnamed component>");
}

component::component( const std::string& friendlyName )
{
	construct(friendlyName);
}

void component::construct( const std::string& friendlyName )
{
	name = friendlyName;
}

component::~component() {
	// TODO Auto-generated destructor stub
}

} /* namespace engine */
} /* namespace synergi */
