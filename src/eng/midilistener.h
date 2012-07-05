/*
 * midilistener.h
 *
 *  Created on: Jul 5, 2012
 *      Author: drb
 */

#ifndef MIDILISTENER_H_
#define MIDILISTENER_H_

#include "midi.h"

namespace synergi {
namespace engine {

class midilistener
{
public:
	midilistener();
	virtual ~midilistener();

public:

	virtual void rx_midi_event( const midi::msg_t& msg) const=0;
};

} /* namespace engine */
} /* namespace synergi */
#endif /* MIDILISTENER_H_ */
