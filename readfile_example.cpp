#include <iostream>
#include <fstream>

double calculateForce(double, double);
double calculateAcceleration(double, double);

int main()
{
	std::ifstream scienceData("science.txt", std::ios::in);

	if (!scienceData) {
		std::cout << "can not open file" << std::endl;
		return 1;
	}

	double velocity;
	double delta_time;
	double acceleration;
	double mass;
	double force;

	while (scienceData >> velocity >> delta_time >> mass) {
		acceleration = calculateAcceleration(velocity, delta_time);
		force = calculateForce(mass, acceleration);

		std::cout << "calculated acceleration: " << acceleration << std::endl;
		std::cout << "calculated force: " << force << std::endl;

	}

	return 0;
}

double calculateForce(double mass, double acceleration)
{
	return mass * acceleration;
}

double calculateAcceleration(double velocity, double delta_time)
{
	return velocity / delta_time;
}
