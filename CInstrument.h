#pragma once 
#include <iostream>

class CInstrument{
 private:
  std::string m_str_serialNumber;
  double m_price;
 public:  
  CInstrument(std::string str_serialNumber, 
         double d_price) 
    : m_str_serialNumber(str_serialNumber),
    m_price(d_price) { 
    }
  CInstrument(const CInstrument& orig) { 
    m_str_serialNumber = orig.m_str_serialNumber;
    m_price = orig.m_price;
  }
  virtual ~CInstrument() { }
  double getPrice() { return m_price; }
  void setPrice(double price) { m_price = price; }
  std::string getSerialNumber() { return m_str_serialNumber; }
};
