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

	virtual void mem_dispose();
	virtual void contains_empty();
	virtual void contains_wrong();
	virtual void contains_right_solo();
	virtual void contains_right_multi();

	CPPUNIT_TEST_SUITE( WavetableTest );
	CPPUNIT_TEST( mem_dispose );
	CPPUNIT_TEST( contains_empty );
	CPPUNIT_TEST( contains_wrong );
	CPPUNIT_TEST( contains_right_solo );
	CPPUNIT_TEST( contains_right_multi );
	CPPUNIT_TEST_SUITE_END();
};




}
}
#endif /* WAVETABLETEST_H_ */
