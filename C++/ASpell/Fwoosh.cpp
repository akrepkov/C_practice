
#include "Fwoosh.hpp"
#include "ASpell.hpp"

Fwoosh::Fwoosh(){
	this->_name = "Fwoosh";
	this->_effects = "Fwooshed";
};

Fwoosh& Fwoosh::clone(){
	return (*(new Fwoosh()));
}
Fwoosh& Fwoosh::operator=(const Fwoosh &a){
	if (this != &a){
		this->_name = a._name;
		this->_effects = a._effects;
	}
	return *this;
}

void Fwoosh::launch(const ATarget& target) const {
	target.getHitBySpell(*this);

}