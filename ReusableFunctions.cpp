#include "ReusableFunctions.h"

// Returns Collatz applied once to a given number
void collatzFunctionStep(uint64_t* p_number)
{
	*p_number = (*p_number % 2 == 0) ? *p_number >> 1 : *p_number * 3 + 1;
}
// Returns Collatz applied N times to a given number
void collatzFunctionStep(uint64_t* p_number, const uint64_t n)
{
	for (uint64_t i = 1; i <= n; i++)
	{
		collatzFunctionStep(p_number);
	}
}
// Returns Collatz mod M applied N times to a given number
void collatzFunctionStep(uint64_t* p_number, const uint64_t n, const uint64_t m)
{
	for (uint64_t i = 1; i <= n; i++)
	{
		collatzFunctionStep(p_number);
		if (*p_number > m)
		{
			*p_number = *p_number % m;
		}
		if (*p_number == 0)
		{
			*p_number = m;
		}
	}
}

// Returns the amount of Collatz steps a given number takes to reach to 1
uint64_t collatzStepsToReachToOne(const uint64_t number)
{
	uint64_t auxVal = number;
	uint64_t counter = 0;

	while (!(auxVal == 1 || auxVal == 0))
	{
		collatzFunctionStep(&auxVal);
		counter++;
	}

	return counter;
}
// Returs true if mod-M-Collatz reaches to 1 in a finite amount of steps, returns false if not
bool modMcollatzReachesToOne(const uint64_t number, const uint64_t m)
{
	uint64_t auxVal = number;
	uint64_t counter = m;

	while (auxVal != 1 && counter != 0)
	{
		collatzFunctionStep(&auxVal,1,m);
		counter--;
	}
	
	return ((auxVal != 1) ? false : true);
}
// Returns the amount of mod-M-Collatz steps a given number takes to reach to 1
uint64_t modMcollatzStepsToReachToOne(const uint64_t number, const uint64_t m)
{
	// Check first if it ever reaches to one
	bool doesItReachToOne = modMcollatzReachesToOne(number, m);
	if (!doesItReachToOne)
	{
		return 0;
	}

	uint64_t auxVal = number;
	uint64_t counter = 0;

	while (!(auxVal == 1 || auxVal == 0))
	{
		collatzFunctionStep(&auxVal,1,m);
		counter++;
	}

	return counter;
}

// Prints a vector on console
void printVectorOnConsole(const std::vector<uint64_t>& items)
{
	for (const uint64_t& item : items)
	{
		std::cout << item << " ";
	}
	std::cout << '\n';
}
// Returns a vector with the natural numbers from 1 to N
std::vector<uint64_t> listOfNaturalNumbersUpToN(const uint64_t n)
{
	uint64_t one = 1;
	std::vector<uint64_t> vectorValues(n);
	std::iota(vectorValues.begin(), vectorValues.end(), one);

	return vectorValues;
}
// Returns a vector with the non-negative integers from 0 to N
std::vector<uint64_t> listOfNonNegativeIntegersUpToN(const uint64_t n)
{
	uint64_t zero = 0;
	std::vector<uint64_t> vectorValues(n);
	std::iota(vectorValues.begin(), vectorValues.end(), zero);

	return vectorValues;
}

// Returns a vector of values when applying Collatz steps to a given number up to reaching 1
// First vector element is such given number
std::vector<uint64_t> collatzValuesUpToReachingToOne(const uint64_t number)
{
	std::vector<uint64_t> vectorValues{ number };
	uint64_t auxVal = number;

	while (auxVal != 1)
	{
		collatzFunctionStep(&auxVal);
		vectorValues.push_back(auxVal);
	}

	return vectorValues;
}
// Returns a vector of values when applying mod-M-Collatz steps to a given number up to reaching 1
// First vector element is such given number
// Returns a vector of size 1 with value 0 if it never reaches to one
std::vector<uint64_t> modMcollatzValuesUpToReachingToOne(const uint64_t number, const uint64_t m)
{
	uint64_t zero = 0;
	std::vector<uint64_t> vectorValues{ zero };

	// Check first if it ever reaches to one
	bool doesItReachToOne = modMcollatzReachesToOne(number, m);
	if (!doesItReachToOne)
	{
		return vectorValues;
	}

	vectorValues.at(0) = number;
	uint64_t auxVal = number;

	while (auxVal != 1)
	{
		collatzFunctionStep(&auxVal,1,m);
		vectorValues.push_back(auxVal);
	}

	return vectorValues;
}