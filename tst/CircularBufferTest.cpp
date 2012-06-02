/*
 * CircularBufferTest.cpp
 *
 *  Created on: Jun 2, 2012
 *      Author: drb
 */

#include <iostream>
#include <string>
#include <stdlib.h>

#include "CircularBufferTest.h"
#include <buf/circularbuffer.h>

using namespace CppUnit;

namespace synergi {
namespace test {

typedef synergi::engine::circularbuffer<synergi::byte_t> circularbuffer;

void CircularBufferTest::new_is_empty()
{
	circularbuffer b;
	CPPUNIT_ASSERT_MESSAGE("is_empty() returns empty on new buffer", b.is_empty());
}

void CircularBufferTest::new_not_full()
{
	circularbuffer b;
	CPPUNIT_ASSERT_MESSAGE("is_full() returns true on new buffer", !b.is_full());
}

void CircularBufferTest::partial_not_empty()
{
	circularbuffer b;
	b.insert(0);
	CPPUNIT_ASSERT_MESSAGE("is_empty() returns true on non-empty buffer", !b.is_empty());
}

void CircularBufferTest::partial_not_full()
{
	circularbuffer b;
	b.insert(0);
	CPPUNIT_ASSERT_MESSAGE("is_full() returns true on partially populated buffer", !b.is_full());
}

void CircularBufferTest::insert_remove_is_empty()
{
	const byte_t testBytes[] = {0xAA,0xBB};
	circularbuffer b;
	b.insert(testBytes[0]);
	b.insert(testBytes[1]);
	CPPUNIT_ASSERT_MESSAGE("emptied buffer returned wrong contents", b.extract()==testBytes[0]);
	CPPUNIT_ASSERT_MESSAGE("emptied buffer returned wrong contents", b.extract()==testBytes[1]);
	CPPUNIT_ASSERT_MESSAGE("emptied buffer does not report empty", b.is_empty());
}

void CircularBufferTest::underrun()
{
	circularbuffer b;
	CPPUNIT_ASSERT_THROW_MESSAGE("No exception on extraction from empty buffer",b.extract(),circularbuffer::underrun);
}

void CircularBufferTest::overrun()
{
	const uint32_t sz = 5;
	circularbuffer b(44100,5);

	CPPUNIT_ASSERT(b.capacity()==sz);

	uint32_t count=0;
	do
	{
		b.insert(0xFF);
	} while (++count<sz);

	CPPUNIT_ASSERT(b.length()==b.capacity());
	CPPUNIT_ASSERT_THROW_MESSAGE("No exception on buffer overrun",b.insert(0xAA),circularbuffer::overrun);
	CPPUNIT_ASSERT(b.length()==b.capacity());
}

void CircularBufferTest::simple_wrap()
{
	typedef std::auto_ptr<byte_t> byte_ptr;

	const uint32_t sz = 6;
	circularbuffer b(44100,sz);
	byte_ptr data((byte_t*)malloc(sz));

	uint32_t c = 0;

	// Populate a local buffer with some data
	for( byte_t* ptr = data.get(); c<sz ; *(ptr++)=c++ );

	b.insert(0xAA);
	b.insert(0xAA);
	b.insert(0xAA);

	b.extract();
	b.extract();
	b.extract();

	// Insert said data into the buffer under test, wrapping it
	for ( byte_t* ptr = data.get(), c=0; c < sz ; b.insert(ptr[c++]) );
	CPPUNIT_ASSERT(b.is_full());

	// Check that you can't add any more
	CPPUNIT_ASSERT_THROW(b.insert(0xAA),circularbuffer::overrun);

	// Now check that each byte returned from the buffer matches the original data
	for ( byte_t* ptr = data.get(), c=0 ; c<sz; CPPUNIT_ASSERT(ptr[c]==b.extract()),c++ );

	// Now we should be empty again
	CPPUNIT_ASSERT(b.is_empty());
}

}
}
