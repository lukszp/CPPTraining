#pragma once
#include <iostream>
#include <list>
#include "CBark.h"

#define DEBUG

using namespace std;

class CDogDoor{
 private:
  bool m_open;
  list<CBark> m_lstOfAllowedBarks;

 public:
  CDogDoor() { m_open = false; }

  CDogDoor(CDogDoor& orig)
    {
      m_open = orig.m_open;
      m_lstOfAllowedBarks = orig.m_lstOfAllowedBarks;
    }

  void addAllowedBark(CBark bark)
  {
    m_lstOfAllowedBarks.push_back(bark);
    #ifdef DEBUG
    std::cout << "Dodałem szczekniecie: " << bark.getSound() << std::endl;
    #endif
  }

  list<CBark>& getAllowedBarks()
    {
      return m_lstOfAllowedBarks;
    }

  void open() {
    std::cout << "Otwieramy drzwi!" << std::endl;
    m_open = true;
  }

  void close() {
    std::cout << "Zamykamy drzwi!" << std::endl;
    m_open = false;
  }

  bool isOpen() {
    return m_open;
  }

};
