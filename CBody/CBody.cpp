#include "CBody.h"

double CBody::GetMass() const
{
	return GetDensity() * GetVolume();
};

std::string CBody::ToString() const
{
	std::string allInfo = "Density: " + std::to_string(GetDensity()) + "\n" +
						  "Volume: " + std::to_string(GetVolume()) + "\n" +
						  "Mass: " + std::to_string(GetMass()) + "\n";
	return allInfo;
};