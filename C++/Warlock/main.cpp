#include "Warlock.hpp"


int main()
{
  Warlock const richard("Richard", "Mistress of Magma");
  richard.introduce();
  std::cout << richard.getname() << " - " << richard.gettitle() << std::endl;

  Warlock* jack = new Warlock("Jack", "the Long");
  jack->introduce();
  jack->settitle("the Mighty");
  jack->introduce();

  delete jack;

  return (0);
}