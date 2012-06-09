/*
 * CircularBufferTest.cpp
 *
 *  Created on: Jun 2, 2012
 *      Author: drb
 */

#include <iostream>
#include <string>
#include <stdlib.h>

#include "WavetableTest.h"
#include "osc/oscillator.h"
#include <malloc.h>
#include <buf/basic.h>

using namespace CppUnit;

namespace synergi {
namespace test {

void WavetableTest::new_is_empty()
{
  using synergi::engine::rawbuffer_t;
  struct mallinfo old = mallinfo();

  synergi::engine::oscillator::wavetable* t = new synergi::engine::oscillator::wavetable;

  //allocate a new rawbuffer
  rawbuffer_t* pBuf = new rawbuffer_t(1024);
  rawbuffer_t* pBuf2 = new rawbuffer_t(1024);
  t->add(7,*pBuf);
  t->add(7,*pBuf2);


  delete t;

  struct mallinfo now = mallinfo();
  CPPUNIT_ASSERT_EQUAL(old.uordblks,now.uordblks);

}

}
}
