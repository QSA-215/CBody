#include "CSphere.h"

const double Pi = 3.14;

CSphere::CSphere(double density, double radius)
{
	m_density = density;
	m_radius = radius;
};

double CSphere::GetRadius() const
{
	return m_radius;
};

double CSphere::GetVolume() const
{
	return (4 * Pi * m_radius * m_radius * m_radius) / 3;
};