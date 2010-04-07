#include <iostream>
#include <stdlib.h>

#include "media_types.h"


int main()
{
  char command;
  Medium* medium = NULL;
  command = 'q';

  while (true) {
    std::cout << "What do you want to do?" << std::endl
            << "m: new medium" << std::endl
            << "l: list media" << std::endl
            << "e: borrow last media" << std::endl
            << "r: return media" << std::endl
            << "q: quit" << std::endl
            << std::endl
            << "Command: ";
    std::cin >> command;
    std::cout << std::endl;
    
    switch (command) {
      case 'm':
        std::cout << "Please enter media information!" << std::endl;
        medium = new Medium();
        break;
      case 'l':
        if (medium != NULL) {
          std::cout << "Media" << std::endl;
          medium->print();
        }
        break;
      case 'e':
        if (medium != NULL) {
          medium->lendOut();
        } else {
          std::cout << "Please enter medium first!" << std::endl;
        }
        break;
      case 'r':
        if (medium != NULL) {
          medium->handIn();
        } else {
          std::cout << "Please enter medium first!" << std::endl;
        }
        break;
      case 'q':
        exit(EXIT_SUCCESS);
    }
    std::cout << std::endl;
  }
}
