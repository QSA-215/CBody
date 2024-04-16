#pragma once
#include "CBody.h"
#include <vector>
#include <memory>
// ������������ ����� ���� �������������, ���� ������ ����� �� ���
class CCompound : public CBody
{
public:
	double GetDensity() const override;
	double GetVolume() const override;
	bool AddChildBody(CBody child);
private:
	std::vector<std::unique_ptr<CBody>> m_compoundBody;
};