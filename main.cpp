#include <iostream>
#include <format>
#include <cstdint>

#include "ReusableFunctions.h"
#include <matplot/matplot.h>


int main()
{
	using namespace matplot;

	uint64_t number = 27;
	uint64_t modM = 64;
	std::vector<uint64_t> myVector1;
	std::vector<uint64_t> myVector2;

	myVector1 = collatzValuesUpToReachingToOne(number);
	printVectorOnConsole(myVector1);
	std::cout << '\n';
	myVector2 = modMcollatzValuesUpToReachingToOne(number, modM);
	printVectorOnConsole(myVector2);
	
	plot(myVector1);
	show();

	/*
	uint64_t num = 27;
	uint64_t boundN = 3;
	uint64_t boundM = 18;
	num = 27;
	collatzFunctionStep(&num, boundN, boundM);
	std::cout << std::format("{} ", num) << '\n';
	*/

	/*
	uint64_t num = 27;
	uint64_t boundM = 256;

	bool result;
	boundM = modMcollatzStepsToReachToOne(num, boundM);
	std::cout << std::format("{} ", boundM) << '\n';
	*/
	return 0;
}