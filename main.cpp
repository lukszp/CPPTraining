#include "CRemote.h"
#include "CDogDoor.h"
#include "CBark.h"
#include "CBarkRecognizer.h"
#include <stdlib.h>
#include <iostream>

int main(int argc, char** argv) {

  CDogDoor dogDoor;
  CBark bark1("hauu");
  CBark bark2("Hrauu");
  CBark bark3("hauhauu");
  CBark bark4("hauuuuu");

  dogDoor.addAllowedBark(bark1);
  dogDoor.addAllowedBark(bark2);
  dogDoor.addAllowedBark(bark3);
  dogDoor.addAllowedBark(bark4);

  CBarkRecognizer recognizer(dogDoor);
  CRemote remote(dogDoor);

  std::cout << "Brus szczeka!" << std::endl;
  CBark bark_brus("hauu");
  recognizer.recognize(bark_brus);

  std::cout << "Brus wyszedł!" << std::endl;
  std::cout << "Postawił kloca!" << std::endl;  

  dogDoor.close();

  std::cout << "Ale utknął na zewnątrz!" << std::endl;  

  CBark other_dog("wrauuu");
  std::cout << "Inny pies szczeka!" << std::endl;  
  recognizer.recognize(other_dog);

  std::cout << "Brus znowu szczeka!" << std::endl;  
  recognizer.recognize(bark_brus);

  std::cout << "Brus wszedł!" << std::endl;
  
  dogDoor.close();

  /*
  CRemote remote(dogDoor);
  
  std::cout << "Azor szczeka by wyjść na spacer..." << std::endl;
  remote.pressButton();
  std::cout << "Azor wyszedł na zewnątrz..." << std::endl;
  std::cout << "Azor postawił kloca :)" << std::endl;
  std::cout << "Azor wrócił do domu." << std::endl;
  */

  return (EXIT_SUCCESS);
}

