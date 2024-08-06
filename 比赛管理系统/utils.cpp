#pragma once
#include <iostream>
#include <random>
#include "utils.h"
#include "Contestant.h"

void pull(std::vector<Contestant>& P)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::shuffle(P.begin(),P.end(), gen);
}