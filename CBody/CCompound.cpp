#include "CCompound.h"

double CCompound::GetDensity() const
{
	if (m_compoundBody.empty())
		return NAN;

	double totalDensity = 0;
	for (const auto& body : m_compoundBody)
		totalDensity += body->GetDensity();
	return totalDensity;
};

double CCompound::GetVolume() const
{
	if (m_compoundBody.empty())
		return NAN;

	double totalVolume = 0;
	for (const auto& body : m_compoundBody)
		totalVolume += body->GetVolume();
	return totalVolume;
};

bool CCompound::AddChildBody(CBody child) //надо проверку на добавление самого себя
{
	//std::unique_ptr<CBody> solidBody {std::make_unique<CBody>(child)};
	m_compoundBody.push_back(std::make_unique<CBody>(child));
	return true;
};