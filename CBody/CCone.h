#pragma once
#include "CSolidBody.h"

class CCone : public CSolidBody
{
public:
	CCone(double density, double height, double baseRadius);
	double GetBaseRadius() const;
	double GetHeight() const;
	double GetVolume() const override;
private:
	double m_baseRadius;
	double m_height;
};