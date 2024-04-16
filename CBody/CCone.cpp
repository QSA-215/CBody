#include "CCone.h"

const double Pi = 3.14;

CCone::CCone(double density, double height, double baseRadius)
{
	m_density = density;
	m_height = height;
	m_baseRadius = baseRadius;
};

double CCone::GetBaseRadius() const
{
	return m_baseRadius;
};

double CCone::GetHeight() const
{
	return m_height;
};

double CCone::GetVolume() const
{
	return (Pi * m_baseRadius * m_baseRadius * m_height) / 3;
};