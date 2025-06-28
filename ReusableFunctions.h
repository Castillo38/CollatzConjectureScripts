#pragma once
#include <iostream>
#include <format>
#include <cstdint>
#include <vector>
#include <numeric>

/****************************************************************
* Functions that apply Collatz to a number
* Return are in form pass-by-reference
*****************************************************************/
// Returns Collatz applied once to a given number
void collatzFunctionStep(uint64_t* p_number);
// Returns Collatz applied N times to a given number
void collatzFunctionStep(uint64_t* p_number, const uint64_t n);
// Returns Collatz mod M applied N times to a given number
void collatzFunctionStep(uint64_t* p_number, const uint64_t n, const uint64_t m);

/****************************************************************
* Functions that return meaningful info when applying Collatz functions
* Return are in form pass-by-value
*****************************************************************/
// Returns the amount of Collatz steps a given number takes to reach to 1
uint64_t collatzStepsToReachToOne(const uint64_t number);
// Returs true if mod-M-Collatz reaches to 1 in a finite amount of steps, returns false if not
bool modMcollatzReachesToOne(const uint64_t number, const uint64_t m);
// Returns the amount of mod-M-Collatz steps a given number takes to reach to 1
uint64_t modMcollatzStepsToReachToOne(const uint64_t number, const uint64_t m);

/****************************************************************
* General use vector functions
*****************************************************************/
// Prints a vector on console
void printVectorOnConsole(const std::vector<uint64_t>& items);
// Returns a vector with the natural numbers from 1 to N
std::vector<uint64_t> listOfNaturalNumbersUpToN(const uint64_t n);
// Returns a vector with the non-negative integers from 0 to N
std::vector<uint64_t> listOfNonNegativeIntegersUpToN(const uint64_t n);

/****************************************************************
* Functions that return vector of Collatz values
* Return are in form pass-by-value
*****************************************************************/
// Returns a vector of values when applying Collatz steps to a given number up to reaching 1
// First vector element is such given number
std::vector<uint64_t> collatzValuesUpToReachingToOne(const uint64_t p_number);
// Returns a vector of values when applying mod-M-Collatz steps to a given number up to reaching 1
// First vector element is such given number
// Returns a vector of size 1 with value 0 if it never reaches to one
std::vector<uint64_t> modMcollatzValuesUpToReachingToOne(const uint64_t p_number, const uint64_t m);