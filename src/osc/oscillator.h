/*
 * oscillator.h
 *
 *  Created on: May 31, 2012
 *      Author: drb
 */

#ifndef OSCILLATOR_H_
#define OSCILLATOR_H_

#include "common/ns.h"
#include "common/types.h"
#include "buf/circularbuffer.h"
#include <exception>
#include <map>
#include "eng/midi.h"
#include <iostream>
#include "osc/wavetable.h"
#include "eng/source.h"

namespace synergi
{
namespace test
{
class WavetableTest;
}
}

s_namespace_2(synergi,engine)

class oscillator : public source
{

public:

	class synthesis : public std::exception
	{
	};

	oscillator(double f=440.0, double a=1.0);

	virtual ~oscillator();

	private:
	double freq;
	double amplitude;

	protected:


	protected:
	wavetable waveTable;
};

s_namespace_end_2

#endif /* OSCILLATOR_H_ */
