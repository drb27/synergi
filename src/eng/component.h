/*
 * component.h
 *
 *  Created on: Jul 1, 2012
 *      Author: drb
 */

#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <string>
#include "midi.h"
#include "midilistener.h"

namespace synergi {
namespace engine {

class component : public midilistener
{
public:
	component();
	component( const std::string& friendlyName );
	virtual ~component();
	inline const std::string& get_name() const { return name; }
	void set_name(const std::string& newName) { name = newName; }

	virtual void rx_midi_event( const midi::msg_t& msg) const;

private:
	std::string name;
	void construct(const std::string& friendlyName);
};

} /* namespace engine */
} /* namespace synergi */
#endif /* COMPONENT_H_ */
