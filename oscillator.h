/*
 * oscillator.h
 *
 *  Created on: May 31, 2012
 *      Author: drb
 */

#ifndef OSCILLATOR_H_
#define OSCILLATOR_H_

#include "ns.h"
#include "audiobuffer.h"

s_namespace_2(synergi,engine)

class oscillator
{
public:

  oscillator();
  oscillator(double);

  virtual ~oscillator();

  virtual void synthesize(audiobuffer& buffer, uint32_t samples)=0;

private:
  double freq;
  double amplitude;
};

s_namespace_end_2

#endif /* OSCILLATOR_H_ */
