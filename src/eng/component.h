/*
 * component.h
 *
 *  Created on: Jul 1, 2012
 *      Author: drb
 */

#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <string>

namespace synergi {
namespace engine {

class component {
public:
	component();
	component( const std::string& friendlyName );
	virtual ~component();
	inline const std::string& get_name() const { return name; }
	void set_name(const std::string& newName) { name = newName; }
private:
	std::string name;
	void construct(const std::string& friendlyName);
};

} /* namespace engine */
} /* namespace synergi */
#endif /* COMPONENT_H_ */
