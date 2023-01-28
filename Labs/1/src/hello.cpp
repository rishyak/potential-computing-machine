#include "name.hpp"
#include <iostream>

int main() {
  std::string username = ask_user_name();
  std::cout << "Hello " << username << std::endl;
}
