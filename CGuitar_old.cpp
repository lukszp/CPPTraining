/* 
 * File:   CGuitar.cpp
 * Author: lukasz
 * 
 * Created on November 7, 2010, 7:20 PM
 */

#include "CGuitar.h"

CGuitar::CGuitar(const CGuitar& orig) {

    m_str_serialNumber = orig.m_str_serialNumber;
    m_builder = orig.m_builder;
    m_str_model = orig.m_str_model;
    m_type = orig.m_type;
    m_backWood = orig.m_backWood;
    m_topWood = orig.m_topWood;
    m_dPrice = orig.m_dPrice;

}

CGuitar::~CGuitar() {
}

