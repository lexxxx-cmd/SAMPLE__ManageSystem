#include "Manager.h"
#include "utils.h"
#include "Person.h"
#include "Contestant.h"
#include <random>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
#define FILENAME "historyInfo.txt"

Manager::Manager()
{
	//初始化总人数以及每位选手的信息
	this->numOfPerson = 12;
	//初始化每位选手的信息(姓名，性别，年龄，编号)并加到Pool里
	this->playerPool.reserve(this->numOfPerson);
	//第一轮组别先准备好两个
	this->stageOnePool1.reserve(6);
	this->stageOnePool2.reserve(6);
	this->finalPool.reserve(6);


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
	ofs.open(FILENAME, std::ios::out | std::ios::app);
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
void Manager::reviseHistoryFile(std::vector<Contestant>& P)
{
	std::ofstream ofs_temp;
	ofs_temp.open(FILENAME, std::ios::out | std::ios::app);
	if (!ofs_temp.is_open())
	{
		ofs_temp.close();
	}
	for (std::vector<Contestant>::iterator it = P.begin();it != P.begin() + 3;it++)
	{
		ofs_temp << (*it).getName() << " "
			<< it->getgender() << " "
			<< it->getAge() << " "
			<< 0.3 * (*it).getScore()[0] + 0.7 * (*it).getScore()[1]
			<< std::endl;
	}
	std::cout << "--------已记录--------" << std::endl;
	this->hisFileEmpty = false;
	ofs_temp.close();
}
void Manager::startContest()
{
	this->showCurrentContestant(this->playerPool);
	std::cout << "---------开始分组----------" << std::endl;
	this->Group();
	std::cout << "--------第一组--------" << std::endl;
	this->showCurrentContestant(this->stageOnePool1);
	std::cout << "--------第二组--------" << std::endl;
	this->showCurrentContestant(this->stageOnePool2);

	system("pause");
	system("cls");

	std::cout << "--------第一组按编号顺序抽签并排好序准备演讲--------" << std::endl;
	//咦为什么这个类可以使用这个函数呢，包含头文件后就相当于类内测成员函数了吗
	pull(this->stageOnePool1);
	std::cout << "--------第一组顺序如下--------" << std::endl;
	this->showCurrentContestant(this->stageOnePool1);
	std::cout << "--------第二组按编号顺序抽签并排好序准备演讲--------" << std::endl;
	pull(this->stageOnePool2);
	std::cout << "--------第二组顺序如下--------" << std::endl;
	this->showCurrentContestant(this->stageOnePool2);

	system("pause");
	system("cls");


	std::cout << "--------第一组开始演讲--------" << std::endl;
	this->teamSpeech(this->stageOnePool1, 1);
	std::cout << "--------第一组排名如下--------" << std::endl;
	sort(this->stageOnePool1.begin(), this->stageOnePool1.end(), CompByScore);
	advanceToNextRound(this->stageOnePool1);
	this->showCurrentContestant(this->stageOnePool1);

	system("pause");
	system("cls");

	std::cout << "--------第二组开始演讲--------" << std::endl;
	this->teamSpeech(this->stageOnePool2, 1);
	std::cout << "--------第二组排名如下--------" << std::endl;
	sort(this->stageOnePool2.begin(), this->stageOnePool2.end(), CompByScore);
	advanceToNextRound(this->stageOnePool2);
	this->showCurrentContestant(this->stageOnePool2);

	system("pause");
	system("cls");

	std::cout << "--------晋级决赛名单如下--------" << std::endl;
	this->showCurrentContestant(this->finalPool);
	std::cout << "--------决赛组按编号顺序抽签并排好序准备演讲--------" << std::endl;
	pull(this->finalPool);
	std::cout << "--------决赛组顺序如下--------" << std::endl;
	this->showCurrentContestant(this->finalPool);

	system("pause");
	system("cls");

	std::cout << "--------决赛组开始演讲--------" << std::endl;
	this->teamSpeech(this->finalPool, 2);
	std::cout << "--------决赛组排名如下--------" << std::endl;
	sort(this->finalPool.begin(), this->finalPool.end(), CompByScore);
	this->showCurrentContestant(this->finalPool);
	

	//将这次的比赛成绩写入文件
	this->reviseHistoryFile(this->finalPool);
	/*std::ofstream ofs_temp;
	ofs_temp.open(FILENAME, std::ios::out | std::ios::app);
	if (!ofs_temp.is_open())
	{
		ofs_temp.close();
	}
	for (std::vector<Contestant>::iterator it = this->finalPool.begin();it != this->finalPool.begin() + 3;it++)
	{
		ofs_temp << (*it).getName() << " "
			<< it->getgender() << " "
			<< it->getAge() << " "
			<< 0.3 * (*it).getScore()[0] + 0.7 * (*it).getScore()[1]
			<< std::endl;
	}
	std::cout << "--------已记录--------" << std::endl;
	this->hisFileEmpty = false;
	ofs_temp.close();*/
}
void Manager::checkHistoryFile()
{
	if (this->hisFileEmpty == false)
	{
		std::ifstream ifs;
		ifs.open(FILENAME, std::ios::in);
		std::string temp;
		while (getline(ifs, temp))
		{
			std::cout << temp << std::endl;
		}
		ifs.close();
	}
	else
	{
		std::cout << "文件为空！" << std::endl;
	}

}
void Manager::clearHistoryFile()
{
	std::ofstream file_writer(FILENAME, std::ios_base::out);
}
void Manager::showCurrentContestant(std::vector<Contestant>& P)
{
	for (std::vector<Contestant>::iterator it = P.begin();it != P.end();it++)
	{
		it->showInfo();
	}
}
void Manager::Group()
{
	//乱序打乱数组
	int a[12] = { 1,1,1,1,1,1,2,2,2,2,2,2 };
	int temp_index = 0;
	pull(this->playerPool);
	//std::random_device rd;
	//std::mt19937 gen(rd());
	//std::shuffle(this->playerPool.begin(), this->playerPool.end(), gen);

	for (std::vector<Contestant>::iterator it = this->playerPool.begin();it != this->playerPool.end();it++)
	{
		if (temp_index < 6)
		{
			(*it).setTeam(1);
		}
		else
		{
			(*it).setTeam(2);
		}
		temp_index++;
	}
	this->stageOnePool1.assign(this->playerPool.begin(), this->playerPool.begin() + 6);
	this->stageOnePool2.assign(this->playerPool.begin() + 6, this->playerPool.end());
}
double Manager::Score()
{
	//std::deque<int> temp;
	int t_score = 0;
	int t_max = 0;
	int t_min = 0;
	int t_total = 0;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> u(1, 10);
	//其实这里可以直接记录最大值最小值以及总值，完了直接算平均
	for (int i = 0;i < 10;i++)
	{
		t_score = u(gen);
		t_total += t_score;
		if (t_max < t_score)
		{
			t_max = t_score;
		}
		else if (t_min > t_score)
		{
			t_min = t_score;
		}
	}
	return (static_cast<double>(t_total) - t_max - t_min) / 8;
	//sort(temp.begin(), temp.end());
}
void Manager::advanceToNextRound(std::vector<Contestant>& P)
{
	for (std::vector<Contestant>::iterator it = P.begin();it != P.begin() + 3;it++)
	{
		this->finalPool.push_back((*it));
	}
}

void Manager::save()
{
	std::ofstream ofs_temp;
	ofs_temp.open(FILENAME, std::ios::out | std::ios::app);
	if (!ofs_temp.is_open())
	{
		ofs_temp.close();
	}
	for (std::vector<Contestant>::iterator it = this->finalPool.begin();it != this->finalPool.begin() + 3;it++)
	{
		ofs_temp << (*it).getName() << " "
			<< it->getgender() << " "
			<< it->getAge() << " "
			<< 0.3 * (*it).getScore()[0] + 0.7 * (*it).getScore()[1]
			<< std::endl;
	}
	std::cout << "--------已记录--------" << std::endl;
	this->hisFileEmpty = false;
	ofs_temp.close();
}
void Manager::teamSpeech(std::vector<Contestant>& P,int round)
{
	for (std::vector<Contestant>::iterator it = P.begin();it != P.end();it++)
	{
		(*it).speech();
		std::cout << "--------评委为该组 " << (*it).getIndex() << "选手打分--------" << std::endl;
		(*it).setScore(this->Score(), round);
	}
}
