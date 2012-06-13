/*
 * wavetable.cpp
 *
 *  Created on: Jun 11, 2012
 *      Author: drb
 */

#include "buf/basic.h"
#include "eng/midi.h"
#include <map>
#include "wavetable.h"

namespace synergi {
namespace engine {

void wavetable::clear()
{

	// Free all buffers
	for ( parent::iterator i = begin(); i!=end(); i++)
	{
		delete (*i).second;
	}
	parent::clear();
}

void wavetable::add(midi::note_t note, const rawbuffer_t& buf)
{
	if (find(note)!=end())
	{
		const rawbuffer_t* pBuf = (*find(note)).second;
		delete pBuf;
		erase(note);
	}
	(*this)[note] = &buf;
}

bool wavetable::contains(midi::note_t note) const
{
	return (find(note)!=end());
}

} /* namespace engine */
} /* namespace synergi */
