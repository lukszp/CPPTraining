//new branch
#include "CRemote.h"
#include "CDogDoor.h"
#include <stdlib.h>
#include <iostream>

int main(int argc, char** argv) {

  CDogDoor dogDoor;
  CRemote remote(dogDoor);
  
  std::cout << "Azor szczeka by wyjść na spacer..." << std::endl;
  remote.pressButton();
  std::cout << "Azor wyszedł na zewnątrz..." << std::endl;
  std::cout << "Azor postawił kloca :)" << std::endl;
  std::cout << "Azor wrócił do domu." << std::endl;

  return (EXIT_SUCCESS);
}

