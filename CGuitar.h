#pragma once
#include <stdlib.h>
#include <iostream>
#include "CGuitarSpec.h"

class CGuitar{
  
 private:
  std::string m_str_serialNumber;
  double m_price;
  CGuitarSpec* m_ptr_guitarSpec;

 public:
 CGuitar(std::string str_serialNumber, 
         double d_price, 
         CGuitarSpec& guitar_spec)
    : m_str_serialNumber(str_serialNumber),
    m_price(d_price) { 
      m_ptr_guitarSpec = new CGuitarSpec();
      *m_ptr_guitarSpec = guitar_spec;
    }

  CGuitar(const CGuitar& orig)
    {
      std::cout << "Kopiuje!";
      m_str_serialNumber = orig.m_str_serialNumber;
      m_price = orig.m_price;
      m_ptr_guitarSpec = new CGuitarSpec();
      *m_ptr_guitarSpec = *orig.m_ptr_guitarSpec;
    }
  
  virtual ~CGuitar() { delete m_ptr_guitarSpec; }

  CGuitarSpec& getGuitarSpec() { return *m_ptr_guitarSpec; }
 
  double getPrice() { return m_price; }
  void setPrice(double price) { m_price = price; }
  std::string getSerialNumber() { return m_str_serialNumber; }
};

