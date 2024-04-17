#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <memory>
#include "CFigures.h"

std::shared_ptr<CBody> GetMostMassBody(const std::vector<std::shared_ptr<CBody>>& bodies)
{
	std::shared_ptr<CBody> mostMassBody = bodies[0];
	for (const auto& body : bodies)
		if (body->GetMass() > mostMassBody->GetMass())
			mostMassBody = body;
	return mostMassBody;
};

std::shared_ptr<CBody> GetLeastMassBodyInWater(const std::vector<std::shared_ptr<CBody>>& bodies)
{
	const double G = 9.8;
	const double WaterDensity = 1000;

	std::shared_ptr<CBody> LessMassBodyInWater = bodies[0];
	for (const auto& body : bodies)
		if (((body->GetDensity() - WaterDensity) * body->GetVolume()) < 
			((LessMassBodyInWater->GetDensity() - WaterDensity) * LessMassBodyInWater->GetVolume()))
			LessMassBodyInWater = body;

	return LessMassBodyInWater;
};

void GetInfo(const std::vector<std::shared_ptr<CBody>>& bodies)
{
	for (const auto& body : bodies)
		std::cout << body->ToString() << std::endl;
};

void AddBody(std::istringstream& lineStream, std::vector<std::shared_ptr<CBody>>& bodies)
{
	std::string command;
	lineStream >> command;
	if ((command == "compound") || (command == "}"))
	{
		CCompound compoundBody;
		


		bodies.push_back(std::make_shared<CBody>(compoundBody));
	}
	else if (command == "cone")
	{
		double density, height, baseRadius;
		lineStream >> density >> height >> baseRadius;
		bodies.push_back(std::make_shared<CBody>(CCone(density, height, baseRadius)));
	}
	else if (command == "cylinder")
	{
		double density, height, baseRadius;
		lineStream >> density >> height >> baseRadius;
		bodies.push_back(std::make_shared<CBody>(CCylinder(density, height, baseRadius)));
	}
	else if (command == "parallelepiped")
	{
		double density, width, height, depth;
		lineStream >> density >> width >> height >> depth;
		bodies.push_back(std::make_shared<CBody>(CParallelepiped(density, width, height, depth)));
	}
	else if (command == "sphere")
	{
		double density, radius;
		lineStream >> density >> radius;
		bodies.push_back(std::make_shared<CBody>(CSphere(density, radius)));
	}
};

int main()
{
	std::vector<std::shared_ptr<CBody>> bodies;
	std::string line;
	std::istringstream lineStream(line);

	while (std::getline(std::cin, line))
	{
		lineStream.clear();
		lineStream.str(line);
		AddBody(lineStream, bodies);
	}
	if (bodies.empty())
		return 0;

	GetInfo(bodies);
	std::cout << "The body with the highest mass is:" << std::endl << GetMostMassBody(bodies)->ToString() << std::endl;
	std::cout << "The body that will weigh the least when completely submerged in water:" 
		<< std::endl << GetLeastMassBodyInWater(bodies)->ToString() << std::endl;

	return 0;
}