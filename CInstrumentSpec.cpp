#include "CInstrumentSpec.h"

bool CInstrumentSpec::matches(CInstrumentSpec& ptr_iSpec)
{
  if (m_builder != ptr_iSpec.m_builder)
    return false;
  if (m_str_model != ptr_iSpec.m_str_model)
    return false;
  if (m_type != ptr_iSpec.m_type)
    return false;
  if (m_backWood != ptr_iSpec.m_backWood)
    return false;
  if (m_topWood != ptr_iSpec.m_topWood)
    return false;

  return true;

}
