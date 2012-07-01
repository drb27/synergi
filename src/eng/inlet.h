/*
 * inlet.h
 *
 *  Created on: Jul 1, 2012
 *      Author: drb
 */

#ifndef INLET_H_
#define INLET_H_

#include "component.h"

namespace synergi {
namespace engine {

class outlet;

class inlet : public virtual component
{
public:

protected:
	inlet(outlet* sourceOutlet = NULL);
	inline outlet* get_src() const { return datasource; }
private:
	outlet* datasource;

};

} /* namespace engine */
} /* namespace synergi */
#endif /* INLET_H_ */
