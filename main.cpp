/*
 * main.cpp
 *
 *  Created on: May 31, 2012
 *      Author: drb
 */

#include <common/ns.h>
#include <common/types.h>
#include <osc/oscillator.h>
#include <buf/audiobuffer.h>

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
	  // Create an audio buffer at 44.1kHz
	  synergi::engine::audiobuffer buf;

	  // Pipe some stuff into it
	  synergi::byte_t b[128];
	  buf << b;

      // Create an oscillator ptr
      synergi::engine::oscillator* pO=NULL;
      return 0;
  }
  catch(...)
  {
      return -1;
  }
}
