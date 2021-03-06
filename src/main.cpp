/*
 * main.cpp
 *
 *  Created on: May 31, 2012
 *      Author: drb
 */

#include "common/ns.h"
#include "common/types.h"
#include "buf/circularbuffer.h"
#include "osc/oscillator.h"
#include "osc/puresine.h"
#include <iostream>
#include <alsa/asoundef.h>
#include <alsa/asoundlib.h>
#include <fstream>

#define GREEN(X) "\33[32;40m" << X << "\33[0m"
#define RED(X) "\33[0;31m" << X << "\33[0m"

using namespace std;

/********************************************************************************
 * FN: alsa_init()
 *
 * DS: Tests the buffer class
 *
 * RT: null
 */
bool alsa_init(snd_pcm_t *pcm_handle, snd_pcm_uframes_t periodsize)
{
    snd_pcm_stream_t stream = SND_PCM_STREAM_PLAYBACK;
    snd_pcm_hw_params_t *hwparams;
    char* pcm_name;
    pcm_name=strdup("plughw:0,0");

    snd_pcm_hw_params_alloca(&hwparams);

    if (snd_pcm_open(&pcm_handle,pcm_name,stream,0) < 0)
    {
            std::cout << "Could not open PCM device " << pcm_name << std::endl;
            return false;
    }

    if (snd_pcm_hw_params_any(pcm_handle, hwparams) <0 )
    {
            std::cout << "Could not configure PCM device " << pcm_name << std::endl;
            return false;
    }

    int rate = 44100; /* Sample rate */
    unsigned int exact_rate;   /* Sample rate returned by */
                      /* snd_pcm_hw_params_set_rate_near */
    int dir;          /* exact_rate == rate --> dir = 0 */
                      /* exact_rate < rate  --> dir = -1 */
                      /* exact_rate > rate  --> dir = 1 */
    int periods = 2;       /* Number of periods */

     /* Set access type. This can be either    */
        /* SND_PCM_ACCESS_RW_INTERLEAVED or       */
        /* SND_PCM_ACCESS_RW_NONINTERLEAVED.      */
        /* There are also access types for MMAPed */
        /* access, but this is beyond the scope   */
        /* of this introduction.                  */
        if (snd_pcm_hw_params_set_access(pcm_handle, hwparams, SND_PCM_ACCESS_RW_INTERLEAVED) < 0) {
          std::cout << "Error setting access" << std::endl;
          return false;
        }

        /* Set sample format */
        if (snd_pcm_hw_params_set_format(pcm_handle, hwparams, SND_PCM_FORMAT_U16_LE) < 0) {
            std::cout << "Error setting format" << std::endl;
          return false;
        }

        /* Set sample rate. If the exact rate is not supported */
        /* by the hardware, use nearest possible rate.         */
        exact_rate = rate;
        if (snd_pcm_hw_params_set_rate_near(pcm_handle, hwparams, &exact_rate, 0) < 0) {
            std::cout << "Error setting rate" << std::endl;
          return false;
        }
        if (rate != exact_rate) {
            std::cout << "The rate " << rate << "Hz is not supported by your hardware. Using" << exact_rate << "Hz instead." << std::endl;
        }

        /* Set number of channels */
        if (snd_pcm_hw_params_set_channels(pcm_handle, hwparams, 2) < 0) {
            std::cout << "Error setting channels" << std::endl;
            return false;
        }

        /* Set number of periods. Periods used to be called fragments. */
        if (snd_pcm_hw_params_set_periods(pcm_handle, hwparams, periods, 0) < 0) {
            std::cout << "Error setting periods" << std::endl;
            return false;
        }

        /* Set buffer size (in frames). The resulting latency is given by */
        /* latency = periodsize * periods / (rate * bytes_per_frame)     */
        if (snd_pcm_hw_params_set_buffer_size(pcm_handle, hwparams, (periodsize * periods)>>2) < 0) {
            std::cout << "Error setting buffer size" << std::endl;
            return false;
        }

        /* Apply HW parameter settings to */
        /* PCM device and prepare device  */
        if (snd_pcm_hw_params(pcm_handle, hwparams) < 0) {
            std::cout << "Error setting HW params." << std::endl;
            return false;
        }

        return true;
}

/********************************************************************************
 * FN: test_buffer()
 *
 * DS: Tests the buffer class
 *
 * RT: null
 */
void test_buffer()
{
	using synergi::engine::circularbuffer;
	using synergi::engine::puresine;

	// Create an audio buffer at 44.1kHz and 100 stereo samples long
	circularbuffer<uint16_t> buffer(44100,8000,circularbuffer<uint16_t>::stereo);

	// Create a sine wave oscillator
	puresine o;

	std::cout << "Synthesizing ..." << std::endl;

	// Synthesize 40 whole waves
	o.synthesize(buffer,4000);

	std::cout << "Extracting ..." << std::endl;

	// Extract to a linear buffer
	synergi::engine::rawbuffer_t linearBuffer(16000);
	buffer >> linearBuffer;

	// Output to a CSV
	/*
	std::ofstream f;
	f.open("output.csv");

	for ( uint16_t* ptr = (uint16_t*)linearBuffer.buffer; ptr < (ptr+400); ptr+=2)
	{
		f << *ptr << "," << *(ptr+1) << std::endl;
	}

	f.close();
	*/

	// Play that damn mother!
	std::cout << "Playing ..." << std::endl;

	snd_pcm_uframes_t periodsize=8000;
	snd_pcm_t *pcm_handle;
	alsa_init(pcm_handle,periodsize);

	std::cout << "All good so far!" << std::endl;

	unsigned char *data;
	int pcmreturn;
	int frames = periodsize >> 2;

	do {
	    while ((pcmreturn = snd_pcm_writei(pcm_handle, linearBuffer.buffer, frames)) < 0) {
	        snd_pcm_prepare(pcm_handle);
	        std::cout <<  "<<<<<<<<<<<<<<< Buffer Underrun >>>>>>>>>>>>>>>" << std::endl;
	    }
	} while (true);

	std::cout << "Natural termination" << std::endl;
}



/********************************************************************************
 * FN: main()
 *
 * DS: The entry point for the application
 *
 * RT: 0 for success, another code otherwise
 */
int main (int argc, char** argv)
{
  try
  {
      test_buffer();
      return 0;
  }
  catch(...)
  {
      std::cout << RED("EXCEPTION CAUGHT: ABORTING TEST") << std::endl;
  }
}
