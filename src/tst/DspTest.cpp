/*
 * DspTest.cpp
 *
 *  Created on: Jul 13, 2012
 *      Author: drb
 */

#include "DspTest.h"
#include "buf/rawbuffer.h"
#include "dsp/dsp.h"
#include "dsp/unitygain.h"

namespace synergi {
namespace test {

DspTest::DspTest() {
	// TODO Auto-generated constructor stub

}

DspTest::~DspTest() {
	// TODO Auto-generated destructor stub
}

void DspTest::broken_chain()
{
	using synergi::dsp::unitygain;

	// Create a unity gain DSP component
	unitygain u;
	CPPUNIT_ASSERT_THROW_MESSAGE("No exception on broken DSP chain",u.pull(16),synergi::engine::brokenchain);

}

} /* namespace test */
} /* namespace synergi */
