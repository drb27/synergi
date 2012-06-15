/*
 * oscillator.cpp
 *
 *  Created on: May 31, 2012
 *      Author: drb
 */

#include "common/types.h"
#include "common/ns.h"
#include "buf/basic.h"
#include "eng/source.h"
#include "oscillator.h"

s_namespace_2(synergi,engine)

oscillator::oscillator(double f, double a) : freq(f), amplitude(a)
{

}

oscillator::~oscillator()
{
}

s_namespace_end_2
