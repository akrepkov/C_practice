#include "Warlock.hpp"

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