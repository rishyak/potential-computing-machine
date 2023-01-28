#include "name.hpp"
#include <iostream>

std::string ask_user_name() {
  std::string name;

  std::cout << "Enter name: ";
  std::cin >> name;

  return name;
}
