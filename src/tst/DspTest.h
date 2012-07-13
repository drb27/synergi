/*
 * DspTest.h
 *
 *  Created on: Jul 13, 2012
 *      Author: drb
 */

#ifndef DSPTEST_H_
#define DSPTEST_H_

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

class DspTest: public CppUnit::TestCase
{
public:
	DspTest();
	virtual ~DspTest();

	void broken_chain();

	CPPUNIT_TEST_SUITE( DspTest );
	CPPUNIT_TEST( broken_chain );
	CPPUNIT_TEST_SUITE_END();
};

} /* namespace test */
} /* namespace synergi */
#endif /* PURESINETEST_H_ */
