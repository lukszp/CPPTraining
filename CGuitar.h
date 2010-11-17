#pragma once
#include <stdlib.h>
#include <iostream>
#include "CInstrument.h"

class CGuitar : public CInstrument{
  
 private:
  //CGuitarSpec* m_ptr_guitarSpec;

 public:
 CGuitar(std::string str_serialNumber, 
         double d_price) : CInstrument(str_serialNumber, d_price)
   //CGuitarSpec& guitar_spec)
   {

     // m_ptr_guitarSpec = new CGuitarSpec();
     // *m_ptr_guitarSpec = guitar_spec;
    }
 /*
  CGuitar(const CGuitar& orig)
    {
      CInstrument(const CInstrument& )
      
      //m_ptr_guitarSpec = new CGuitarSpec();
      //*m_ptr_guitarSpec = *orig.m_ptr_guitarSpec;
    }
 */
  ~CGuitar() { 
    //delete m_ptr_guitarSpec; 
  }

  //CGuitarSpec& getGuitarSpec() { return *m_ptr_guitarSpec; }
 
 
 
 
};

