/*
 * PuresineTest.h
 *
 *  Created on: Jul 7, 2012
 *      Author: drb
 */

#ifndef PURESINETEST_H_
#define PURESINETEST_H_

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

class PuresineTest: public CppUnit::TestCase
{
public:
	PuresineTest();
	virtual ~PuresineTest();

	void synthesize_onehour();

	CPPUNIT_TEST_SUITE( PuresineTest );
	CPPUNIT_TEST( synthesize_onehour );
	CPPUNIT_TEST_SUITE_END();
};

} /* namespace test */
} /* namespace synergi */
#endif /* PURESINETEST_H_ */
