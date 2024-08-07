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
	//ͨ����Ȩ�ַ��أ���һ������ֻ��һ�ַ���������Ҳ�ǰ���һ���������������㣬���һ����ڵڶ���ʱ���ã���ʱ���Ǽ�Ȩ��
	return 0.3*P1.getScore()[0]+ 0.7*P1.getScore()[1] > 0.3*P2.getScore()[0]+ 0.7*P2.getScore()[1];
}
