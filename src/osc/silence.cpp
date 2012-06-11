/*
 * silence.cpp
 *
 *  Created on: Jun 1, 2012
 *      Author: drb
 */

#include "common/ns.h"
#include "common/types.h"
#include "buf/circularbuffer.h"
#include "silence.h"

s_namespace_2(synergi,engine)

silence::silence() {
	// TODO Auto-generated constructor stub

}

silence::~silence() {
	// TODO Auto-generated destructor stub
}

void silence::synthesize(circularbuffer<uint16_t>& buffer, uint32_t samples)
{
	oscillator::synthesis x;
	throw x;
}

s_namespace_end_2
