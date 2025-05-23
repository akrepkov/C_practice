#include "ASpell.hpp"

ASpell::ASpell(): _name("Test"), _effects("Test"){
}

ASpell& ASpell::operator=(const ASpell &a){
	if (this != &a){
		this->_name = a._name;
		this->_effects = a._effects;
	}
	return *this;
}

void ASpell::launch(const ATarget& target) const {
	target.getHitBySpell(*this);

}