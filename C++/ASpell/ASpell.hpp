
#pragma once

#include <iostream>
#include <string>
#include "ATarget.hpp"


class ATarget;

class ASpell {
	protected:
		std::string _name;
		std::string _effects;
	public:
		ASpell();
		virtual ~ASpell(){};
		virtual const ASpell& clone() = 0;
		ASpell& operator=(const ASpell &a);
		std::string getName() const { return (this->_name);};
		std::string getEffects() const { return (this->_effects);};
		void launch(const ATarget& target) const ;
};

