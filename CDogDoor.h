#include <iostream>
#pragma once

class CDogDoor{
 private:
  bool m_open;
 public:
  CDogDoor() { m_open = false; }

  CDogDoor(CDogDoor& orig)
    {
      m_open = orig.m_open;
    }

  void open() {
    m_open = true;
    std::cout << "Drzwi zostały otwarte!" << std::endl;
  }

  void close() {
    m_open = false;
    std::cout << "Drzwi zostały zamknięte!" << std::endl;    
  }
  
  bool isOpen() {
    return m_open;
  }

};
