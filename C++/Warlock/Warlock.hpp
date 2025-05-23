#ifndef WARLOCK_HPP
#define WARLOCK_HPP


#include <string>
#include <iostream>


class Warlock{
	private:
		std::string _name;
		std::string _title;
		Warlock(); //can't be used
		Warlock(const Warlock& original);  //can't be used
		Warlock& operator=(const Warlock &original);  //can't be used

	public:
		Warlock(std::string name, std::string title);
		~Warlock();
		const std::string& getname() const;
		const std::string& gettitle() const;
		void settitle(const std::string title);
		void introduce() const;

};

#endif