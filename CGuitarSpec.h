#pragma once
#include <stdlib.h>
#include <iostream>

enum TYPE { T_NONE, ACOUTSIC, ELECTRIC };
enum BUILDER { B_NONE, FENDER, MARTIN, GIBSON, COLLINGS, OLSON, RYAN, PRS, ANY };
enum WOOD { W_NONE, INDIAN_ROSEWOOD, BRAZILIAN_ROSEWOOD };

class CGuitarSpec{
  
 private:
  BUILDER m_builder;
  std::string m_str_model;
  TYPE m_type;
  WOOD m_backWood;
  WOOD m_topWood;
  int m_numStrings;

 public:
  CGuitarSpec(BUILDER builder = B_NONE, std::string str_model = "", 
              TYPE type = T_NONE,
              WOOD backWood = W_NONE, 
              WOOD topWood = W_NONE,
              int numStrings = 4)
    : m_builder(builder), m_str_model(str_model), m_type(type),
    m_backWood(backWood), m_topWood(topWood), m_numStrings(numStrings) { }

  CGuitarSpec(const CGuitarSpec& orig)
    {
      m_builder = orig.m_builder;
      m_str_model = orig.m_str_model;
      m_type = orig.m_type;
      m_backWood = orig.m_backWood;
      m_topWood = orig.m_topWood;
      m_numStrings = orig.m_numStrings;
    }

  virtual ~CGuitarSpec() { }

  BUILDER getBuilder() { return m_builder; }
  std::string getModel() { return m_str_model; }
  TYPE getType() { return m_type; }
  WOOD getTopWood() { return m_topWood; }
  WOOD getBackWood() { return m_backWood; }
  int getNumStrings() { return m_numStrings; }
  
  bool compareGuitarSpecs(CGuitarSpec&);

};
