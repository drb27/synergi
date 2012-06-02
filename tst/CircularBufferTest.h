/*
 * CircularBufferTest.h
 *
 *  Created on: Jun 2, 2012
 *      Author: drb
 */

#ifndef CIRCULARBUFFERTEST_H_
#define CIRCULARBUFFERTEST_H_

#include "TestCase.h"
#include "TestSuite.h"
#include "TestCaller.h"
#include "TestRunner.h"

#include <extensions/TestFactoryRegistry.h>
#include <ui/text/TextTestRunner.h>
#include <extensions/HelperMacros.h>

using namespace CppUnit;

namespace synergi {
namespace test {

class CircularBufferTest : public TestCase
{

public:

	CircularBufferTest() {}
	virtual ~CircularBufferTest() {}

	void testSomething();

	CPPUNIT_TEST_SUITE( CircularBufferTest );
	CPPUNIT_TEST( testSomething );
	CPPUNIT_TEST_SUITE_END();
};




}
}
#endif /* CIRCULARBUFFERTEST_H_ */
