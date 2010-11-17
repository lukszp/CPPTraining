#pragma once
#include <stdlib.h>
#include <iostream>

enum TYPE { T_NONE, ACOUTSIC, ELECTRIC };
enum BUILDER { B_NONE, FENDER, MARTIN, GIBSON, COLLINGS, OLSON, RYAN, PRS, ANY };
enum WOOD { W_NONE, INDIAN_ROSEWOOD, BRAZILIAN_ROSEWOOD };

class CInstrumentSpec{
 private:
  BUILDER m_builder;
  std::string m_str_model;
  TYPE m_type;
  WOOD m_backWood;
  WOOD m_topWood;
 public:
 CInstrumentSpec(BUILDER builder = B_NONE, std::string str_model = "", 
              TYPE type = T_NONE,
              WOOD backWood = W_NONE, 
              WOOD topWood = W_NONE)
    : m_builder(builder), m_str_model(str_model), m_type(type),
    m_backWood(backWood), m_topWood(topWood) { }

  CInstrumentSpec(const CInstrumentSpec& orig)
    {
      m_builder = orig.m_builder;
      m_str_model = orig.m_str_model;
      m_type = orig.m_type;
      m_backWood = orig.m_backWood;
      m_topWood = orig.m_topWood;
    }

  virtual ~CInstrumentSpec() { }

  BUILDER getBuilder() { return m_builder; }
  std::string getModel() { return m_str_model; }
  TYPE getType() { return m_type; }
  WOOD getTopWood() { return m_topWood; }
  WOOD getBackWood() { return m_backWood; }
  
  bool matches(CInstrumentSpec&);

};
