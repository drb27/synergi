/*
 * wavetable.h
 *
 *  Created on: Jun 11, 2012
 *      Author: drb
 */

#ifndef WAVETABLE_H_
#define WAVETABLE_H_

namespace synergi {
namespace engine {

class wavetable : protected std::map<midi::note_t,const rawbuffer_t*>
{
protected:
	typedef std::map<midi::note_t,const rawbuffer_t*> parent;

public:
	virtual void clear();

	virtual ~wavetable()
	{
		clear();
	}

	virtual void add(midi::note_t note, const rawbuffer_t& buf);

	bool contains (midi::note_t note) const;
};


} /* namespace engine */
} /* namespace synergi */
#endif /* WAVETABLE_H_ */
