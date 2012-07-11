/*
 * oscillator.cpp
 *
 *  Created on: May 31, 2012
 *      Author: drb
 */

#include "common/types.h"
#include "common/ns.h"
#include "buf/rawbuffer.h"
#include "eng/source.h"
#include "oscillator.h"

namespace synergi
{
namespace engine
{

oscillator::oscillator(double f, double a) : freq(f), amplitude(a)
{

}

oscillator::~oscillator()
{
}
}
}

