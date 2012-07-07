/*
 * main.cpp
 *
 *  Created on: May 31, 2012
 *      Author: drb
 */

#include <iostream>
#include <string>

#include "common/ns.h"
#include "common/types.h"
#include "CircularBufferTest.h"
#include "WavetableTest.h"
#include "PuresineTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(synergi::test::CircularBufferTest);
CPPUNIT_TEST_SUITE_REGISTRATION(synergi::test::WavetableTest);
CPPUNIT_TEST_SUITE_REGISTRATION(synergi::test::PuresineTest);

/********************************************************************************
 * FN: main()
 *
 * DS: Runs the unit tests
 *
 * RT: null
 */
int main(int argc, char** argv)
{
	CppUnit::Test *test =
			CppUnit::TestFactoryRegistry::getRegistry().makeTest();

	CppUnit::TextTestRunner runner;
	runner.addTest(test);
	runner.run();
	return 0;
}
