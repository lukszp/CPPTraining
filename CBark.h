#pragma once  
#include <iostream>

class CBark{
 private:
  std::string m_str_bark;
 public:
  CBark(std::string str_bark) { m_str_bark = str_bark; }
  std::string getSound() { return m_str_bark; }
  bool equals(CBark bark)
  {
    return( bark.getSound() == m_str_bark ? true : false);
  }
};
