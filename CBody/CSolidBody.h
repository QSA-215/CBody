#pragma once
#include "CBody.h"

class CSolidBody : public CBody
{
public:
	double GetDensity() const override;
protected:
	double m_density;
};