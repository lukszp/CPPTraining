/* 
 * File:   main.cpp
 * Author: lukasz
 *
 * Created on November 17, 2010, 10:18 PM
 */

#include <stdlib.h>
#include <map>
#include "CPPTraining/CInstrumentSpec.h"
#include "CPPTraining/CInstrument.h"
#include "CPPTraining/CInventory.h"
#include <iostream>
using namespace std;

void initializeInvbentory(CInventory& inventory)
{
  //temporary map
  map<string, string> addedSpec;
  //instrument
  addedSpec["instrumentType"] = "GUITAR";
  addedSpec["builder"] = "COLLINGS";
  addedSpec["model"] = "CJ";
  addedSpec["type"] = "ACOUSTIC";
  addedSpec["numStrings"] = "6";
  addedSpec["topWood"] = "INDIAN_ROSEWOOD";
  addedSpec["backWood"] = "SITKA";
  inventory.addInstrument("11277", 3999.95, CInstrumentSpec(addedSpec));
  //instrument
  //addedSpec.erase(addedSpec.begin(), addedSpec.end());
  addedSpec["builder"] = "MARTIN";
  addedSpec["model"] = "D-18";
  addedSpec["topWood"] = "MAHOGANY";
  addedSpec["backWood"] = "ADIRONDACK";
  inventory.addInstrument("122784", 5495.95, CInstrumentSpec(addedSpec));
  //instrument
  //addedSpec.erase(addedSpec.begin(), addedSpec.end());
  addedSpec["builder"] = "FENDER";
  addedSpec["model"] = "Stratocastor";
  addedSpec["type"] = "ELECTRIC";
  addedSpec["topWood"] = "ALDER";
  addedSpec["backWood"] = "ALDER";
  inventory.addInstrument("V95693", 1499.95, CInstrumentSpec(addedSpec));
  inventory.addInstrument("V9512", 1549.95, CInstrumentSpec(addedSpec));
  //instrument
  //addedSpec.erase(addedSpec.begin(), addedSpec.end());
  addedSpec["builder"] = "GIBSON";
  addedSpec["model"] = "Les Paul";
  addedSpec["topWood"] = "MAPLE";
  addedSpec["backWood"] = "MAPLE";
  inventory.addInstrument("70108276", 2295.95, CInstrumentSpec(addedSpec));
  //instrument
  //addedSpec.erase(addedSpec.begin(), addedSpec.end());
  addedSpec["model"] = "SG '61 Reissue";
  addedSpec["topWood"] = "MAHOGANY";
  addedSpec["backWood"] = "MAHOGANY";
  inventory.addInstrument("82765501", 1890.95, CInstrumentSpec(addedSpec));
  //instrument
  addedSpec["instrumentType"] = "MANDOLIN";
  addedSpec["model"] = "F-5G";
  addedSpec["type"] = "ACOUSTIC";
  addedSpec.erase("numStrings"); 
  addedSpec["topWood"] = "MAPLE";
  addedSpec["backWood"] = "MAPLE";
  inventory.addInstrument("9019920", 5496.99, CInstrumentSpec(addedSpec));
  //instrument
  addedSpec["instrumentType"] = "BANJO";
  addedSpec["model"] = "RB-3 Wreath";
  addedSpec.erase("topWood"); 
  addedSpec["numStrings"] = "5";
  inventory.addInstrument("8900231", 2945.95, CInstrumentSpec(addedSpec));


}

/*
 * 
 */
int main(int argc, char** argv) {

  CInventory inv;
  initializeInvbentory(inv);

  map<string,string> searchedSpec;
  searchedSpec["builder"] = "GIBSON";
  searchedSpec["backWood"] = "MAPLE";
  CInstrumentSpec searchedInsSpec(searchedSpec);

  list<CInstrument> matchingInstruments;
  matchingInstruments = inv.search(searchedInsSpec);

  if (matchingInstruments.empty())
    cout << "Nie znaleziono niczego";
  else
    {
      list<CInstrument>::iterator it;
      cout << "Znalezione instrumenty: " << endl;
      for(it=matchingInstruments.begin(); it != matchingInstruments.end(); it++)
        {
          string s = "instrumentType";
          string property;
          it->getSpec().getProperty(s, property);
          cout << "Na przykład " << property            << endl << endl;
          map<string,string> properities(*it->getSpec().getProperties());
          map<string,string>::iterator it_prop;
          for(it_prop=properities.begin(); it_prop != properities.end(); it_prop++ )
            {
              cout << it_prop->first << " ma wartość " << it_prop->second << endl;
            }
          cout << endl << "Cena: " << it->getPrice() << endl;
          cout << "===========================================" << endl;
          
        }
    }

  /*
  inv.addInstrument("12345", 122.21, spec1);
  string s = "12345";
  CInstrument* empty;
  cout<< "Mam" << inv.get(s, empty) << endl;

  spec["type"] = "electric";
  spec["wood"] = "brown";
  spec["producer"] = "morex";
  CInstrumentSpec spec2(spec);

  spec.empty();
  spec["type"] = "electric";
  spec["wood"] = "brown";
  spec["producer"] = "morex";

  CInstrumentSpec search(spec);
  cout << spec2.matches(search) << endl;



    // map<string, string> spec;
    // spec["janusz"] = "test";

    // CInstrumentSpec spec2(spec);
    // string j = "janusz";
    // string res;
    // spec2.getProperty(j, res);
    // cout << res << endl;
    
    // //spec = spec2.getProperties();

    */
    return 0;

}

