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

	void new_is_empty();
	void new_not_full();
	void partial_not_empty();
	void partial_not_full();
	void insert_remove_is_empty();
	void underrun();
	void overrun();
	void simple_wrap();
	void wrap_length();

	CPPUNIT_TEST_SUITE( CircularBufferTest );
	CPPUNIT_TEST( new_is_empty );
	CPPUNIT_TEST( new_not_full );
	CPPUNIT_TEST( partial_not_empty );
	CPPUNIT_TEST( partial_not_full );
	CPPUNIT_TEST( insert_remove_is_empty );
	CPPUNIT_TEST( underrun );
	CPPUNIT_TEST( overrun );
	CPPUNIT_TEST( simple_wrap );
	CPPUNIT_TEST( wrap_length );
	CPPUNIT_TEST_SUITE_END();
};




}
}
#endif /* CIRCULARBUFFERTEST_H_ */
