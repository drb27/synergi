/*
 * CircularBufferTest.cpp
 *
 *  Created on: Jun 2, 2012
 *      Author: drb
 */

#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>


#include "buf/basic.h"
#include "eng/midi.h"
#include "WavetableTest.h"
#include "osc/wavetable.h"
#include "osc/oscillator.h"
#include <malloc.h>

using namespace CppUnit;

namespace synergi {
namespace test {

void WavetableTest::contains_empty()
{
	  using synergi::engine::wavetable;
	  using synergi::engine::midi::note_t;

	  //allocate a new wavetable and rawbuffer
	  wavetable* t = new wavetable;

	  // Make sure it doesn't contain any midi note
	  for ( uint16_t n = 0 ; n <= 255; CPPUNIT_ASSERT(!t->contains((note_t)(n++))) );

	  // Dispose
	  delete t;
}

void WavetableTest::contains_wrong()
{
	  using synergi::engine::rawbuffer_t;
	  using synergi::engine::wavetable;
	  using synergi::engine::midi::note_t;

	  const note_t wrongNote = 0xBA;
	  const note_t testNote = 0xAD;

	  //allocate a new wavetable and rawbuffer
	  wavetable* t = new wavetable;
	  rawbuffer_t* pBuf = new rawbuffer_t(1024);

	  t->add(wrongNote,*pBuf);

	  CPPUNIT_ASSERT( !t->contains(testNote) );

	  // Dispose
	  delete t;

}

void WavetableTest::contains_right_solo()
{
	  using synergi::engine::rawbuffer_t;
	  using synergi::engine::wavetable;
	  using synergi::engine::midi::note_t;

	  const note_t testNote = 0xAD;

	  //allocate a new wavetable and rawbuffer
	  wavetable* t = new wavetable;
	  rawbuffer_t* pBuf = new rawbuffer_t(1024);

	  t->add(testNote,*pBuf);

	  CPPUNIT_ASSERT( t->contains(testNote) );

	  // Dispose
	  delete t;
}

void WavetableTest::contains_right_multi()
{
	  using synergi::engine::rawbuffer_t;
	  using synergi::engine::wavetable;
	  using synergi::engine::midi::note_t;

	  const note_t alternativeNote = 0xBA;
	  const note_t testNote = 0xAD;

	  //allocate a new wavetable and rawbuffer
	  wavetable* t = new wavetable;
	  rawbuffer_t* pBuf = new rawbuffer_t(1024);
	  rawbuffer_t* pBuf2 = new rawbuffer_t(1024);

	  t->add(alternativeNote,*pBuf);
	  t->add(testNote,*pBuf2);

	  CPPUNIT_ASSERT( t->contains(testNote) );
	  CPPUNIT_ASSERT( t->contains(alternativeNote) );

	  // Dispose
	  delete t;

}

void WavetableTest::mem_dispose()
{
  using synergi::engine::rawbuffer_t;
  struct mallinfo old = mallinfo();

  synergi::engine::wavetable* t = new synergi::engine::wavetable;

  //allocate a new rawbuffer
  rawbuffer_t* pBuf = new rawbuffer_t(1024);
  rawbuffer_t* pBuf2 = new rawbuffer_t(1024);
  t->add(7,*pBuf);
  t->add(7,*pBuf2);


  delete t;

  struct mallinfo now = mallinfo();
  CPPUNIT_ASSERT_EQUAL(old.uordblks,now.uordblks);

}

void WavetableTest::lookup_empty()
{
	  using synergi::engine::rawbuffer_t;
	  using synergi::engine::wavetable;
	  using synergi::engine::midi::note_t;

	  const note_t testNote = 0xAD;

	  // Allocate a wavetable
	  wavetable* t = new wavetable;

	  CPPUNIT_ASSERT( t->lookup(testNote)==NULL );

	  // Dispose
	  delete t;

}

void WavetableTest::lookup_present()
{
	  using synergi::engine::rawbuffer_t;
	  using synergi::engine::wavetable;
	  using synergi::engine::midi::note_t;

	  const note_t alternativeNote = 0xBA;
	  const note_t testNote = 0xAD;

	  //allocate a new wavetable and rawbuffer
	  wavetable* t = new wavetable;
	  rawbuffer_t* pBuf = new rawbuffer_t(1024);
	  rawbuffer_t* pBuf2 = new rawbuffer_t(1024);

	  t->add(alternativeNote,*pBuf);
	  t->add(testNote,*pBuf2);

	  CPPUNIT_ASSERT( t->lookup(alternativeNote)==pBuf );
	  CPPUNIT_ASSERT( t->lookup(testNote)==pBuf2 );

	  // Dispose
	  delete t;
}

void WavetableTest::lookup_notpresent()
{
	  using synergi::engine::rawbuffer_t;
	  using synergi::engine::wavetable;
	  using synergi::engine::midi::note_t;

	  const note_t alternativeNote = 0xBA;
	  const note_t testNote = 0xAD;

	  //allocate a new wavetable and rawbuffer
	  wavetable* t = new wavetable;
	  rawbuffer_t* pBuf = new rawbuffer_t(1024);

	  t->add(testNote,*pBuf);

	  CPPUNIT_ASSERT( t->lookup(alternativeNote)==NULL );

	  // Dispose
	  delete t;
}

}
}
