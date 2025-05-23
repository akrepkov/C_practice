#include "Warlock.hpp"
#include <algorithm>

const std::string& Warlock::getname() const{
	return (_name);
}
const std::string& Warlock::gettitle() const{
	return (_title);
}

Warlock::Warlock(std::string name, std::string title): _name(name), _title(title) {
	std::cout << this->getname() << " This looks like another boring day." << std::endl;
};

Warlock::Warlock(){
};

Warlock::~Warlock(){
	std::cout << this->getname() << " DONE." << std::endl;

};
Warlock& Warlock::operator=(const Warlock &original){
	if (this != &original){
		this->_name = original._name;
		this->_title = original._title;
	}
	return (*this);
}

Warlock::Warlock(const Warlock& original){
	this->_name = original._name;
	this->_title = original._title;	
}

void Warlock::settitle(const std::string title){
	this->_title = title;
}

void Warlock::introduce() const{
	std::cout << this->getname() << " I'm " << this->getname() << " " << this->gettitle() << std::endl;
}

void Warlock::learnSpell(ASpell *spell){
/*Iteration by Value: When you iterate by value (for (std::string s : spells)), 
s is a copy of each element. */
	for (std::string s : spells){
		if (s == spell->getName()){
			return ;
		}
	}
	spells.push_back(spell->getName());
	std::cout << "Learned spell : " << spell->getName() << std::endl;
}
void Warlock::forgetSpell(std::string spell){
/*Method: Uses std::remove and erase to remove the spell name from the spells 
vector. std::remove shifts all the elements that do not match spell 
to the beginning of the range and returns an iterator to the new end. 
erase then removes the elements from the vector.*/
	auto it = std::remove(spells.begin(), spells.end(), spell);
	if (it != spells.end()){
		std::cout << spell << " was erased" << std::endl;
		spells.erase(it, spells.end());
	}
}
void Warlock::launchSpell(std::string spell, ATarget& target){
	for (std::string s : spells){
		std::cout << "Launch " << s << std::endl;
		if (s == spell){
			std::cout << (&target)->getType() << " has been Fwooshed"<< std::endl;
			return ;
		}
	}
}
