#include <iostream>
#include "CBark.h"

class CBarkRecognizer{
 private:
  CDogDoor m_dogDoor;
 public:
  CBarkRecognizer(CDogDoor& dogDoor)
    {
      m_dogDoor = dogDoor;
    }
  bool recognize(CBark bark)
  {
    std::cout << "Usłyszałem szczekanie: " << bark.getSound() << std::endl;

    list<CBark>* ptr_lstOfAllowedBarks;
    list<CBark>::iterator it;

    ptr_lstOfAllowedBarks = &m_dogDoor.getAllowedBarks();
    
    for ( it=ptr_lstOfAllowedBarks->begin() ; it != ptr_lstOfAllowedBarks->end(); it++ )
      {
        if (it->getSound() == bark.getSound())
          {
            return true;
          }
      }
    std::cout << "Ten pies nie może wejść!" << std::endl;
    return false; 
  }
  

};
