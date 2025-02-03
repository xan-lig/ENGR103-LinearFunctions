#include <iostream>
#include <cmath>

void printNumber (int numberOfDevices)
{
	std::cout << "The number of devices needed to break even is: " << numberOfDevices << std::endl;
}

int calculateNumberOfDevices (double costPerDevice, double baseCost, double revenuePerDevice)
{
        double numberOfDevices = baseCost/(revenuePerDevice - costPerDevice);
        int finalNumber = ceil(numberOfDevices);
	return finalNumber;
}

int main ()
{
        double costPerDevice;
        double baseCost;
        double revenuePerDevice;
        int numberOfDevices;

        std::cout << "Enter the cost for each device: " << std::endl;
        std::cin >> costPerDevice;
        std::cout << "Enter the base cost: " << std::endl;
        std::cin >> baseCost;
        std::cout << "Enter the revenue for each device: " << std::endl;
        std::cin >> revenuePerDevice;

	numberOfDevices = calculateNumberOfDevices(costPerDevice, baseCost, revenuePerDevice);
	printNumber(numberOfDevices);

}
