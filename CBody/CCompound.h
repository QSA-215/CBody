#pragma once
#include "CBody.h"
#include <vector>
#include <memory>
// зацикливание может быть теоретическим, надо просто тесты на это
class CCompound : public CBody
{
public:
	double GetDensity() const override;
	double GetVolume() const override;
	double GetMass() const override;
	bool AddChildBody(const std::shared_ptr<CBody>& child);
private:
	std::vector<std::shared_ptr<CBody>> m_compoundBody;
};