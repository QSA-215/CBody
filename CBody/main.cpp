#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "CCompound.h"
#include "CCone.h"
#include "CCylinder.h"
#include "CParallelepiped.h"
#include "CSphere.h"

void GetInfo(const std::vector<std::unique_ptr<CBody>>& bodies)
{
	for (const auto& body : bodies)
		std::cout << body->ToString() << std::endl;
};

void AddBody(std::istringstream& lineStream, std::vector<std::unique_ptr<CBody>>& bodies)
{
	std::string command;
	lineStream >> command;
	if (command == "compound")
	{
	}
	else if (command == "cone")
	{
		double density, height, baseRadius;
		lineStream >> density >> height >> baseRadius;
		bodies.push_back(std::make_unique<CBody>(CCone(density, height, baseRadius)));
	}
	else if (command == "cylinder")
	{
		double density, height, baseRadius;
		lineStream >> density >> height >> baseRadius;
		bodies.push_back(std::make_unique<CBody>(CCylinder(density, height, baseRadius)));
	}
	else if (command == "parallelepiped")
	{
		double density, width, height, depth;
		lineStream >> density >> width >> height >> depth;
		bodies.push_back(std::make_unique<CBody>(CParallelepiped(density, width, height, depth)));
	}
	else if (command == "sphere")
	{
		double density, radius;
		lineStream >> density >> radius;
		bodies.push_back(std::make_unique<CBody>(CSphere(density, radius)));
	}
};

int main()
{
	std::vector<std::unique_ptr<CBody>> bodies;
	std::string line;
	std::istringstream lineStream(line);

	while (std::getline(std::cin, line))
	{
		lineStream.clear();
		lineStream.str(line);
		AddBody(lineStream, bodies);
	}
	GetInfo(bodies);

	return 0;
}