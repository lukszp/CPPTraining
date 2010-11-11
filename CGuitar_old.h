#pragma once
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>

enum TYPE { ACOUTSIC, ELECTRIC };
enum BUILDER { FENDER, MARTIN, GIBSON, COLLINGS, OLSON, RYAN, PRS, ANY };
enum WOOD { INDIAN_ROSEWOOD, BRAZILIAN_ROSEWOOD };

class CGuitar {

private:
    std::string m_str_serialNumber, m_str_model;
    TYPE m_type;
    BUILDER m_builder;
    WOOD m_topWood;
    WOOD m_backWood;
    double m_dPrice;

public:
    CGuitar(std::string str_serialNumber = "",
            double d_price = 0.0,
            std::string str_model = "",
            TYPE type = ACOUTSIC,
            BUILDER builder = FENDER,
            WOOD topWood = INDIAN_ROSEWOOD,
            WOOD backWood = INDIAN_ROSEWOOD
            )
    :
            m_str_serialNumber(str_serialNumber),
            m_dPrice(d_price),
            m_str_model(str_model),
            m_type(type),
            m_builder(builder),
            m_backWood(backWood),
            m_topWood(topWood)
            
    { }

    CGuitar(const CGuitar& orig);
    virtual ~CGuitar();

    std::string getSerialNumber() { return m_str_serialNumber; }

    double getPrice() { return m_dPrice; }
    
    void setPrice(double d_newPrice) { m_dPrice = d_newPrice; }

    BUILDER getBuilder() { return m_builder; }
    std::string getModel() {
        std::transform(m_str_model.begin(), m_str_model.end(), m_str_model.begin(), ::tolower);
        return m_str_model;
    }
    TYPE getType() { return m_type; }
    WOOD getbackWood() { return m_backWood; }
    WOOD gettopWood() { return m_topWood; }

private:

};
