
#include "CInventory.h"

CInventory::CInventory(const CInventory& orig) {
}

CInventory::~CInventory() {
}

bool CInventory::search2(CGuitarSpec& searchGuitar, 
                         list<CGuitar>& lst_of_guitars)
{
  list<CGuitar>::iterator it;
  bool b_found = false;
  for ( it=lst_Guitars.begin() ; it != lst_Guitars.end(); it++ )
    {
      if (searchGuitar.compareGuitarSpecs(it->getGuitarSpec()))
        {
          lst_of_guitars.push_back(*it);
          b_found = true;
        }
    }
  return b_found;
}


void CInventory::printGuitarList(list<CGuitar>& lst_of_guitars)
{
  list<CGuitar>::iterator it;
  for ( it=lst_of_guitars.begin() ; it != lst_of_guitars.end(); it++ )
    {
      std::cout << "Serial number: " << it->getSerialNumber() << std::endl;
      std::cout << "Price: " << it->getPrice() << std::endl;
      std::cout << "Model: " << it->getGuitarSpec().getModel() << std::endl;
      std::cout << "Type: " << it->getGuitarSpec().getModel() << std::endl;
      std::cout << "Top wood: " << it->getGuitarSpec().getTopWood() << std::endl;
      std::cout << "Bottom wood: " << it->getGuitarSpec().getBackWood() << std::endl;      
      std::cout << std::endl;
    }
  
}
