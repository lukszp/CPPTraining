#include <stdlib.h>
#include "CInventory.h"
#include <iostream>
#include "CGuitar.h"
#include "CGuitarSpec.h"

int main(int argc, char** argv) {

  //CGuitar g1("12345", 1565, FENDER, "Zuzek", ACOUTSIC, INDIAN_ROSEWOOD,
  //          INDIAN_ROSEWOOD);

  CInventory inv;

  CGuitarSpec* gspec = new CGuitarSpec(FENDER, "Zuzek", ACOUTSIC, INDIAN_ROSEWOOD,
                           INDIAN_ROSEWOOD,12);
  inv.AddGuitar("12345", 1565, *gspec);
  delete gspec;

  CGuitarSpec* gspec1 = new CGuitarSpec(FENDER, "Kuzek", ACOUTSIC, INDIAN_ROSEWOOD,
                           INDIAN_ROSEWOOD,12);
  inv.AddGuitar("1234567", 165, *gspec1);
  delete gspec1;

  CGuitarSpec* gspec2 = new CGuitarSpec(OLSON, "Wuzek", ACOUTSIC, INDIAN_ROSEWOOD,
                           INDIAN_ROSEWOOD,12);
  inv.AddGuitar("12222345", 15265, *gspec2);
  delete gspec2;

  CGuitarSpec* gspec3 = new CGuitarSpec(FENDER, "Kuzek", ACOUTSIC, INDIAN_ROSEWOOD,
                           INDIAN_ROSEWOOD,12);
  inv.AddGuitar("111112345", 15, *gspec3);
  delete gspec3;

  CGuitarSpec search_guitar(FENDER, "Kuzek", ACOUTSIC, INDIAN_ROSEWOOD, INDIAN_ROSEWOOD, 12);

  list<CGuitar> lst_of_guitars;
  inv.search2(search_guitar, lst_of_guitars);
  inv.printGuitarList(lst_of_guitars);

  /*
  CGuitar g1;
  if (inv.getGuitar("12345", g1))
    std::cout << "Price: " << g1.getSerialNumber() << std::endl;  

  //CGuitarSpec* cgs;
  //cgs = g1.getGuitarSpec();
  */
  
  
   
  return (EXIT_SUCCESS);
}

