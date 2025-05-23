
#pragma once

#include <iostream>
#include <string>
#include "ASpell.hpp"

class ASpell;
class ATarget {
	protected:
		std::string _type;
	public:
		ATarget(){};
		ATarget(std::string type): _type(type){};
		virtual ~ATarget(){};
		ATarget& operator=(const ATarget &a);
		std::string getType() const;
		virtual const ATarget& clone() = 0;
		void getHitBySpell(const ASpell& spell) const ;
};

