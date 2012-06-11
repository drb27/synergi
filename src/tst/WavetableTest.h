/*
 * CircularBufferTest.h
 *
 *  Created on: Jun 2, 2012
 *      Author: drb
 */

#ifndef WAVETABLETEST_H_
#define WAVETABLETEST_H_

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

class WavetableTest : public TestCase
{

public:

	WavetableTest() {}
	virtual ~WavetableTest() {}

	virtual void new_is_empty();

	CPPUNIT_TEST_SUITE( WavetableTest );
	CPPUNIT_TEST( new_is_empty );
	CPPUNIT_TEST_SUITE_END();
};




}
}
#endif /* WAVETABLETEST_H_ */
