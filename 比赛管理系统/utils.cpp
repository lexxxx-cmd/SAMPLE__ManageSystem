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
bool CompByScore(Contestant& P1, Contestant& P2)
{
	//通过加权分返回，第一轮由于只有一轮分数，所以也是按第一个单独的排名来算，而且还能在第二轮时重用，此时就是加权了
	return 0.3*P1.getScore()[0]+ 0.7*P1.getScore()[1] > 0.3*P2.getScore()[0]+ 0.7*P2.getScore()[1];
}
