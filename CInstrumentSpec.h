#pragma once
#include <iostream>
#include <map>
using namespace std;

class CInstrumentSpec {
 
 private:
  map<string, string>* m_ptr_properities;
 
 public:

  CInstrumentSpec(map<string, string> properities) 
    {
      m_ptr_properities = new map<string,string>(properities);
    }
  
  CInstrumentSpec(const CInstrumentSpec& orig) 
    { 
      m_ptr_properities = new map<string,string>(*(orig.m_ptr_properities));      
    }

  ~CInstrumentSpec() {
    delete m_ptr_properities;
  }

  //return selected property
  bool getProperty(string property, string& propertyValue) {
    //prepare iterator
    map<string, string>::iterator it;
    //find selected property
    it = m_ptr_properities->find(property);    
    //if property has not been found then iterator points
    //to the end
    if(it  == m_ptr_properities->end())
    {
      return false;
    }
    else
    {
      //return property
      propertyValue = it->second;
      return true;
    }
  }

  //return map of properties
  map<string,string>* getProperties() {
    return m_ptr_properities;
  }

  bool matches(CInstrumentSpec spec)
  {
    //prepare iterators
    map<string, string>::iterator it;
    map<string, string>::iterator m_it;
    
    //get map of properties
    map<string, string>* map_ptr;
    map_ptr = spec.getProperties();
   
    //current property
    string currentPropertyKey;
    string currentPropertyValue;

    //go through all properties of spec
    for (it=map_ptr->begin(); it != map_ptr->end(); it++)
      {
        //load property name and value into temp variables
        currentPropertyKey = it->first;
        currentPropertyValue = it->second;
        //iterate through current spec
        for (m_it=m_ptr_properities->begin(); m_it != m_ptr_properities->end(); m_it++)
          {
            //if property name is different than searched one leave this iteration
            if (m_it->first != currentPropertyKey) continue;
            //property name is the same but value is different - return false
            if (m_it->second != currentPropertyValue) return false;
          }
        
      }
    //it seems that all properties of spec are the same in the current one
    return true;
  }
};
