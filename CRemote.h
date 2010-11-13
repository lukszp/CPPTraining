#pragma once
#include <iostream>
#include "CDogDoor.h"

class CRemote {
 private:
  CDogDoor m_dogDoor;
 public:
  CRemote(CDogDoor& dogDoor)
    {
      m_dogDoor = dogDoor;
    }
  void pressButton()
  {
    std::cout << "Naciśnięto przycisk na pilocie..." << std::endl;
    if (m_dogDoor.isOpen())
      m_dogDoor.close();
    else
      {
        m_dogDoor.open();
        sleep(5);
        m_dogDoor.close();
      }
    
    
  }
};
