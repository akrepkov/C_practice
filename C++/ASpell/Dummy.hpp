#pragma once

#include <iostream>
#include <string>
#include "ATarget.hpp"

class Dummy : public ATarget{
	public:
		Dummy();
		~Dummy(){};
		Dummy& operator=(const Dummy &a);
		std::string getType() const;
		Dummy& clone();
		void getHitBySpell(const ASpell& spell) const ;
};
