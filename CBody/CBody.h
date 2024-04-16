#pragma once
#include <string>

class CBody
{
public:
	virtual double GetDensity() const;
	virtual double GetVolume() const;
	double GetMass() const;
	std::string ToString() const;
};