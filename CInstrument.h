#pragma once 
#include <iostream>
#include "CInstrumentSpec.h"

using namespace std;

class CInstrument {
 private:
  string m_serialNumber;
  double m_price;
  CInstrumentSpec* m_ptr_instrumentSpec;

 public:

  CInstrument(string serialNumber, double price, CInstrumentSpec instrumentSpec)
   : m_serialNumber(serialNumber), m_price(price) {
    m_ptr_instrumentSpec = new CInstrumentSpec(instrumentSpec);
  }

  CInstrument(const CInstrument &orig)
    {
      m_serialNumber = orig.m_serialNumber;
      m_price = orig.m_price;
      m_ptr_instrumentSpec = new CInstrumentSpec(*orig.m_ptr_instrumentSpec);
      
    }

  ~CInstrument() 
    {
      delete m_ptr_instrumentSpec;
    }

  string getSerialNumber() { return m_serialNumber; }
  double getPrice() { return m_price; }
  void setPrice(double price) { m_price = price; }
  CInstrumentSpec& getSpec() { return *m_ptr_instrumentSpec; }
  
};
