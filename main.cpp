/*
 * main.cpp
 *
 *  Created on: May 31, 2012
 *      Author: drb
 */

#include <common/ns.h>
#include <common/types.h>
#include <osc/oscillator.h>
#include <buf/circularbuffer.h>
#include <iostream>

#define GREEN(X) "\33[32;40m" << X << "\33[0m"
#define RED(X) "\33[0;31m" << X << "\33[0m"

using namespace std;

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

	// Create an audio buffer at 44.1kHz and 5 bytes long
	circularbuffer x(44100,5);

	//////////////////////////////////// EMPTY BUFFER /////////////////////////////
	cout << "Empty buffer ------> is_empty() ... ";
	// test that it is, in fact, empty
	if (x.is_empty())
	{
		cout << GREEN("PASS") << endl;
	}
	else
	{
		cout << RED("FAIL")  << endl;
	}

	cout << "Empty buffer ------> is_full() ... ";
	// test that it is, in fact, empty
	if (x.is_full())
	{
		cout << RED("FAIL") << endl;
	}
	else
	{
		cout << GREEN("PASS") << endl;
	}

	//////////////////////////////////// PARTIAL BUFFER /////////////////////////////
	x.insert(0xFF);
	x.insert(0xFF);

	cout << "Partial buffer ------> is_full() ... ";

	if (!x.is_empty())
	{
		cout << GREEN("PASS") << endl;
	}
	else
	{
		cout << RED("FAIL")  << endl;
	}

	cout << "Partial buffer ------> is_full() ... ";
	if (x.is_full())
	{
		cout << RED("FAIL") << endl;
	}
	else
	{
		cout << GREEN("PASS") << endl;
	}

	//////////////////////////////////// FULL BUFFER (a) //////////////////////////
	x.insert(0xFF);
	x.insert(0xFF);
	x.insert(0xFF);
	cout << "Full buffer ------> is_empty() ... ";

	if (!x.is_empty())
	{
		cout << GREEN("PASS") << endl;
	}
	else
	{
		cout << RED("FAIL")  << endl;
	}

	cout << "Full buffer ------> is_full() ... ";

	if (!x.is_full())
	{
		cout << RED("FAIL") << endl;
	}
	else
	{
		cout << GREEN("PASS") << endl;
	}
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

      // Create an oscillator ptr
      synergi::engine::oscillator* pO=NULL;
      return 0;
  }
  catch(...)
  {
      std::cout << RED("EXCEPTION CAUGHT: ABORTING TEST") << std::endl;
  }
}
