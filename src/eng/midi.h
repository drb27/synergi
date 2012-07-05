/*
 * midi.h
 *
 *  Created on: Jun 9, 2012
 *      Author: drb
 */

#ifndef MIDI_H_
#define MIDI_H_

#include "common/ns.h"
#include "common/types.h"

s_namespace_2(synergi,engine)

namespace midi
{

  typedef uint8_t note_t;

  enum msgtype_t
  {
	  MSG_NOTEON,
	  MSG_NOTEOFF
  };

  struct msg_t
  {
	  msgtype_t msg;
	  note_t paramA;
	  note_t paramB;
  };

}

s_namespace_end_2

#endif /* MIDI_H_ */
