/*
 * PuresineTest.cpp
 *
 *  Created on: Jul 7, 2012
 *      Author: drb
 */

#include <iostream>
#include <string>
#include <stdlib.h>
#include "common/types.h"

#include "PuresineTest.h"

#include "buf/rawbuffer.h"
#include "osc/puresine.h"
#include <malloc.h>

using namespace CppUnit;

namespace synergi {
namespace test {

PuresineTest::PuresineTest() {
	// TODO Auto-generated constructor stub

}

PuresineTest::~PuresineTest() {
	// TODO Auto-generated destructor stub
}

void PuresineTest::synthesize_onehour()
{
	const uint32_t Iterations = 44100*60*60/8000;



	// Create a puresine
	synergi::engine::puresine o(440.0,2000,32000);

	struct mallinfo old = mallinfo();

	for (uint32_t i = 0 ; i < Iterations ; i++)
	{
		// Synthesize a chunk
		engine::rawbuffer_t* pBuf = o.pull(4000);

		// Check the offset
		const double& offset = o.tOffset;

		CPPUNIT_ASSERT_MESSAGE("Offset buildup detected",offset < 1000.0);

		delete pBuf;
	}

	  struct mallinfo now = mallinfo();
	  CPPUNIT_ASSERT_EQUAL(old.uordblks,now.uordblks);

}

} /* namespace test */
} /* namespace synergi */
