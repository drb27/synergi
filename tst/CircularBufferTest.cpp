/*
 * CircularBufferTest.cpp
 *
 *  Created on: Jun 2, 2012
 *      Author: drb
 */

#include <iostream>
#include <string>

#include "CircularBufferTest.h"
#include <buf/circularbuffer.h>

using namespace CppUnit;
using synergi::engine::circularbuffer;

namespace synergi {
namespace test {

void CircularBufferTest::testSomething()
{
	circularbuffer b;
	CPPUNIT_ASSERT_MESSAGE("is_empty() returns empty on new buffer", !b.is_empty());
}



}
}
