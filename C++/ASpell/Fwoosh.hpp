#pragma once

#include <iostream>
#include <string>
#include "ASpell.hpp"


class Fwoosh : public ASpell{
/*since you're using the getName() method which returns _name from the base class (ASpell), 
and you've overridden _name and _effects in Fwoosh, 
the base class's _name is not being updated correctly to reflect the derived class's _name.*/
	public:
		Fwoosh();
		~Fwoosh(){};
		Fwoosh& clone();
		Fwoosh& operator=(const Fwoosh &a);
		void launch(const ATarget& target) const ;
};