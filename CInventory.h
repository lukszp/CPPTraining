#pragma once
#include "CGuitar.h"
#include <list>


//#define DEBUG

using namespace std;

class CInventory {
 private:
  list<CGuitar> lst_Guitars;

 public:
  CInventory() { };
  CInventory(const CInventory& orig);
  virtual ~CInventory();
  
  void AddGuitar(std::string str_serialNumber,
                 double d_price,
                 CGuitarSpec& guitar_spec)
  {
    CGuitar* pn_guitar = new CGuitar(str_serialNumber,
                                     d_price,
                                     guitar_spec);

    lst_Guitars.push_back(*pn_guitar);
    delete pn_guitar;
  }

  bool getGuitar(string str_Serial, CGuitar& guitar)
  {
    list<CGuitar>::iterator it;
    for ( it=lst_Guitars.begin() ; it != lst_Guitars.end(); it++ )
      {
        if (it->getSerialNumber() == str_Serial)
          {
            //std::cout << it->getPrice();
            //std::cout << &*it;
            //CGuitar g1;
            guitar = *it;
            //pn_guitar = &*it;
            //std::cout << pn_guitar->getSerialNumber();
            return true;
          }
      }  
    return false;        
  }

  bool search2(CGuitarSpec& searchGuitar, list<CGuitar>& lst_of_guitars);
  void printGuitarList(list<CGuitar>& lst_of_guitars);

};
