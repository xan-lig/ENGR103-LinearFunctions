#include <iostream>
#include <cmath>

void printMix1 (double mix1)
{
	std::cout << "The proportion of Mix 1 is " << mix1 << "\% of the total." << std::endl;
}
void printMix2 (double mix2)
{
	std::cout << "The proportion of Mix 2 is " << mix2 << "\% of the total." << std::endl;
}
void printMix3 (double mix3)
{
	std::cout << "The proportion of Mix 3 is " << mix3 << "\% of the total." << std::endl;
}

void printNitrogen (double mix1, double mix2, double mix3, double nit1, double nit2, double nit3)
{
	std::cout << "The proportion of nitrogen in your mix is " << (mix1 * nit1 + mix2 * nit2 + mix3 * nit3) << "\%." << std::endl;
}

void printPotassium (double mix1, double mix2, double mix3, double pot1, double pot2, double pot3)
{
	std::cout << "The proportion of potassium in your mix is " << (mix1 * pot1 + mix2 * pot2 + mix3 * pot3) << "\%." << std::endl;
}

void printPhosphorus (double mix1, double mix2, double mix3, double phos1, double phos2, double phos3)
{
	std::cout << "The proprotion if phosphorus in your mix is " << (mix1 * phos1 + mix2 * phos2 + mix3 * phos3) << "\%." << std::endl;
}

double calcMix1 (double nit1, double nit2, double nit3, double pot1,  double pot2, double pot3, double phos1, double phos2, double phos3)
{
	double mix1;
        double step1 = (pot3 - nit3 + (nit3 - nit2 + pot2 - pot3) * ((phos3 - nit3) / (nit2 - nit3 + phos3 - phos2)));
        mix1 = step1 / (pot3 - nit3 + nit1 - pot1 + (nit3 - nit2 + pot2 - pot3) * ((nit1 - nit3 + phos3 - phos1) / (nit2 - nit3 + phos3 - phos2)));

        return mix1;
}

double calcMix2 (double mix1, double nit1, double nit2, double nit3, double phos1, double phos2, double phos3)
{
	double mix2;
	mix2 = ((phos3 - nit3 - (mix1 * (nit1 - nit3 + phos3 - phos1))) / (nit2 - nit3 + phos3 - phos2));

	return mix2;
}

double calcMix3 (double mix1, double mix2)
{
	double mix3 = 1 - mix1 - mix2;

	return mix3;
}

int main ()
{
	double mix1;
	double mix2;
	double mix3;

	double nit1;
	double nit2;
	double nit3;
	double pot1;
	double pot2;
	double pot3;
	double phos1;
	double phos2;
	double phos3;

	std::cout << "Enter the proportion of nitrogen in your first ingredient: " << std::endl;
	std::cin >> nit1;
	std::cout << "Enter the proportion of potassium in your first ingredient: " << std::endl;
	std::cin >> pot1;
	std::cout << "Enter the proportion of phosphorus in your first ingredient: " << std::endl;
	std::cin >> phos1;

	std::cout << "Enter the proportion of nitrogen in your second ingredient: " << std::endl;
        std::cin >> nit2;
        std::cout << "Enter the proportion of potassium in your second ingredient: " << std::endl;
        std::cin >> pot2;
        std::cout << "Enter the proportion of phosphorus in your second ingredient: " << std::endl;
        std::cin >> phos2;
	
	std::cout << "Enter the proportion of nitrogen in your third ingredient: " << std::endl;
        std::cin >> nit3;
        std::cout << "Enter the proportion of potassium in your third ingredient: " << std::endl;
        std::cin >> pot3;
        std::cout << "Enter the proportion of phosphorus in your third ingredient: " << std::endl;
        std::cin >> phos3;

	mix1 = calcMix1(nit1, nit2, nit3, pot1, pot2, pot3, phos1, phos2, phos3);
	mix2 = calcMix2(mix1, nit1, nit2, nit3, phos1, phos2, phos3);
	mix3 = calcMix3(mix1, mix2);

	printMix1(mix1);
	printMix2(mix2);
	printMix3(mix3);

	printNitrogen(mix1, mix2, mix3, nit1, nit2, nit3);
	printPotassium(mix1, mix2, mix3, pot1, pot2, pot3);
	printPhosphorus(mix1, mix2, mix3, phos1, phos2, phos3);
}
