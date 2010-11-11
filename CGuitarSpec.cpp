#include "CGuitarSpec.h"

bool CGuitarSpec::compareGuitarSpecs(CGuitarSpec& ptr_guitar)
{
  if (m_builder != ptr_guitar.m_builder)
    return false;
  if (m_str_model != ptr_guitar.m_str_model)
    return false;
  if (m_type != ptr_guitar.m_type)
    return false;
  if (m_backWood != ptr_guitar.m_backWood)
    return false;
  if (m_topWood != ptr_guitar.m_topWood)
    return false;
  if (m_numStrings != ptr_guitar.m_numStrings)
    return false;

  return true;

}
