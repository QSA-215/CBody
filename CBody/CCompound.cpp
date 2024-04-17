#include "CCompound.h"

double CCompound::GetDensity() const
{
	if (m_compoundBody.empty())
		return NAN;

	double totalDensity = 0;
	for (const auto& body : m_compoundBody)
		totalDensity += body->GetDensity();
	return totalDensity / m_compoundBody.size();
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

double CCompound::GetMass() const
{
	if (m_compoundBody.empty())
		return NAN;

	double totalMass = 0;
	for (const auto& body : m_compoundBody)
		totalMass += body->GetVolume() * body->GetDensity();
	return totalMass;
};

bool CCompound::AddChildBody(const std::shared_ptr<CBody>& child) //надо проверку на добавление самого себя
{
	m_compoundBody.push_back(child);
	return true;
};