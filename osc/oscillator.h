/*
 * oscillator.h
 *
 *  Created on: May 31, 2012
 *      Author: drb
 */

#ifndef OSCILLATOR_H_
#define OSCILLATOR_H_

#include <common/ns.h>
#include <common/types.h>
#include <buf/circularbuffer.h>
#include <exception>
#include <map>
#include <eng/midi.h>
#include <iostream>

namespace synergi
{
  namespace test
  {
    class WavetableTest;
  }
}

s_namespace_2(synergi,engine)

class oscillator
{
  friend class synergi::test::WavetableTest;

public:

	  class synthesis : public std::exception
	    {
	    };

  oscillator(double f=440.0, double a=1.0);

  virtual ~oscillator();

  // Fills an audio buffer with the requested number of samples
  virtual void synthesize(circularbuffer<uint16_t>& buffer, uint32_t samples)=0;

private:
  double freq;
  double amplitude;

protected:

  class wavetable : protected std::map<synergi::engine::midi::note_t,const rawbuffer_t*>
  {
  protected:
    typedef std::map<synergi::engine::midi::note_t,const rawbuffer_t*> parent;

  public:
    virtual void clear()
    {

      // Free all buffers
      for ( parent::iterator i = begin(); i!=end(); i++)
        {
          delete (*i).second;
        }
      parent::clear();
    }

    virtual ~wavetable()
    {
      clear();
    }

    virtual void add(midi::note_t note, const rawbuffer_t& buf)
    {
      (*this)[note] = &buf;
    }
  };

  wavetable waveTable;
};

s_namespace_end_2

#endif /* OSCILLATOR_H_ */
