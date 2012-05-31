/*
 * main.cpp
 *
 *  Created on: May 31, 2012
 *      Author: drb
 */

#include "oscillator.h"

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
      // Create an oscillator
      synergi::engine::oscillator o;
      return 0;
  }
  catch(...)
  {
      return -1;
  }
}
