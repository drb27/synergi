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
#include "osc/silence.h"

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

bool DspTest::test_silence(synergi::engine::rawbuffer_t* pBuf, const uint16_t Offset) {
	// Check that each sample is equal to the offset
	bool dodgy = false;
	uint16_t* pSample = (uint16_t*) (pBuf->buffer);
	for (int i = 0; i < 512; i++) {
		if ((*(pSample++)) != Offset) {
			dodgy = true;
			break;
		}
	}

	return dodgy;
}

void DspTest::silence() {
	const uint16_t Offset = 32000;
	// Tests to see if the silence oscillator generates the correct output
	using synergi::engine::silence;
	using synergi::engine::rawbuffer_t;
	{
		silence oscSilence(Offset);
		// Ask for n samples
		rawbuffer_t* pBuf = oscSilence.pull(1024);
		CPPUNIT_ASSERT(pBuf->size == 1024);
		// Check that each sample is equal to the offset
		bool dodgy = test_silence(pBuf, Offset);

		delete pBuf;

		CPPUNIT_ASSERT(!dodgy);
	}

}

void DspTest::populate()
{
	// Use a silence oscillator and a unitygain to check the populate method of dsp
	using synergi::engine::silence;
	using synergi::dsp::unitygain;
	using synergi::engine::rawbuffer_t;

	// Set up the DSP chain
	silence osc(32000);
	unitygain ugblock(osc);

	// Pull some samples from the unity gain block
	rawbuffer_t* pBuf = ugblock.pull(1024);

	// Check that they are the same as expected from the silence oscillator
	bool dodgy = test_silence(pBuf,32000);

	// Free the buffer
	delete pBuf;

	CPPUNIT_ASSERT(!dodgy);
}

} /* namespace test */
} /* namespace synergi */
