#include "Dummy.hpp"

Dummy::Dummy(){
	this->_type = "Target Practice Dummy";
}

Dummy& Dummy::operator=(const	Dummy &a){
	if (this != &a){
		this->_type = a._type;
	}
	return *this;
}
std::string Dummy::getType() const{
	return (this->_type);
}
Dummy& Dummy::clone() {
	return (*new Dummy ());
}
void Dummy::getHitBySpell(const ASpell& spell) const {
	std::cout << this->_type << " has been " << spell.getEffects() << std::endl;
}