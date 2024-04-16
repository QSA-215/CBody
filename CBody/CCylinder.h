#pragma once
#include "CSolidBody.h"

class CCylinder : public CSolidBody
{
public:
	CCylinder(double density, double height, double baseRadius);
	double GetBaseRadius() const;
	double GetHeight() const;
	double GetVolume() const override;
private:
	double m_baseRadius;
	double m_height;
};