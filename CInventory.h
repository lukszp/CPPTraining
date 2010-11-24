#pragma once 
#include <iostream>
#include "CInstrument.h"
#include "CInstrumentSpec.h"
#include <list>

using namespace std;

class CInventory {
 private:
  list<CInstrument> m_instruments;
 public:
  CInventory() {};
  CInventory(const CInventory& orig) { }

  void addInstrument(string serialNumber, double price, CInstrumentSpec instrumentSpec)
  {
    CInstrument* ptr_Instrument;
    ptr_Instrument = new CInstrument(serialNumber, price, instrumentSpec);
    m_instruments.push_back(*ptr_Instrument);
    delete ptr_Instrument;    
  }

  bool get(string serialNumber, CInstrument* ptr_instrument)
  {
    list<CInstrument>::iterator it;
    for (it=m_instruments.begin(); it != m_instruments.end(); it++)
      {
        if (it->getSerialNumber() == serialNumber) { ptr_instrument =  &(*it); return true; } 
      }
    return false;
  }

  list<CInstrument> search(CInstrumentSpec searchedSpec)
    {
      list<CInstrument>::iterator it;
      list<CInstrument> results;

      for (it=m_instruments.begin(); it != m_instruments.end(); it++)
        {

          if (it->getSpec().matches(searchedSpec)) results.push_back(*it);
        }

      return results;
    }

};
