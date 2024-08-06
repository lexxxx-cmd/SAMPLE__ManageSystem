#include "Manager.h"
#include "Person.h"
#include "Contestant.h"
#include <random>
#include <fstream>
#include <iostream>
#define FILENAME "historyInfo.txt"

Manager::Manager()
{
	//初始化总人数以及每位选手的信息
	this->numOfPerson = 12;
	//初始化每位选手的信息(姓名，性别，年龄，编号)并加到Pool里
	this->playerPool.reserve(this->numOfPerson);
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> u(15, 50);
	int t_age = 0;
	std::string t_gender = "男";
	std::string t_name = "";
	std::string nameFirst = "Person";
	std::string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0;i < this->numOfPerson;i++)
	{
		//产生随机数
		t_age = u(gen);
		if (t_age % 2 == 0)
		{
			t_gender = "女";
		}
		else
		{
			t_gender = "男";
		}
		t_name = nameFirst + nameSeed[i];
		this->playerPool.push_back(Contestant(t_name,t_gender, t_age, 10001 + i));
	}
	//创建文件或重写文件
	std::ofstream ofs;
	ofs.open(FILENAME, std::ios::out);
	if (!ofs.is_open())
	{
		std::cout << "文件不存在！现在创建……" << std::endl;
		this->hisFileEmpty = true;
		ofs.close();
	}
	else
	{
		//判断是否为空
		std::ifstream ifs;
		ifs.open(FILENAME, std::ios::in);
		char c;
		ifs >> c;
		if (ifs.eof())
		{
			std::cout << "文件为空，无历史记录!" << std::endl;
			this->hisFileEmpty = true;
			ifs.close();
		}
		else
		{
			std::cout << "文件存在可查看的历史记录!" << std::endl;
			this->hisFileEmpty = false;
			ifs.close();
		}
	}

}
Manager::~Manager()
{

}
void Manager::showMenu()
{
	
	std::cout << "*************************" << std::endl;
	std::cout << "****** 1、开始比赛 ******" << std::endl;
	std::cout << "****** 2、查看历史数据 **" << std::endl;
	std::cout << "****** 3、清空历史数据 **" << std::endl;
	std::cout << "****** 4、退出系统 ******" << std::endl;
	std::cout << "*************************" << std::endl;

}
void Manager::ctrlWorkFlow()
{
	int temp=0;
	while (temp != 4)
	{
		std::cout << "输入操作：" << std::endl;
		std::cin >> temp;
		switch (temp)
		{
		case 1:
			startContest();
			break;
		case 2:
			checkHistoryFile();
			break;
		case 3:
			clearHistoryFile();
			break;
		case 4:
			break;
		default:
			std::cout << "请按屏幕上的选项进行输入！" << std::endl;
			break;
		}
	}
	exit(0);
	
}
void Manager::reviseHistoryFile()
{

}
void Manager::startContest()
{
	this->showCurrentContestant();
}
void Manager::checkHistoryFile()
{

}
void Manager::clearHistoryFile()
{

}
void Manager::showCurrentContestant()
{
	for (std::vector<Contestant>::iterator it = this->playerPool.begin();it != this->playerPool.end();it++)
	{
		it->showInfo();
	}
}
