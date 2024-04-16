#include "CCylinder.h"

const double Pi = 3.14;

CCylinder::CCylinder(double density, double height, double baseRadius)
{
	m_density = density;
	m_height = height;
	m_baseRadius = baseRadius;
};

double CCylinder::GetBaseRadius() const
{
	return m_baseRadius;
};

double CCylinder::GetHeight() const
{
	return m_height;
};

double CCylinder::GetVolume() const
{
	return Pi * m_baseRadius * m_baseRadius * m_height;
};