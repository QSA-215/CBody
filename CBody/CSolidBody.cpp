#include "CSolidBody.h"

double CSolidBody::GetDensity() const
{
	return m_density;
};

double CSolidBody::GetMass() const
{
	return GetDensity() * GetVolume();
};