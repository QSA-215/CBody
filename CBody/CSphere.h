#pragma once
#include "CSolidBody.h"

class CSphere : public CSolidBody
{
public:
	CSphere(double density, double radius);
	double GetRadius() const;
	double GetVolume() const override;
private:
	double m_radius;
};