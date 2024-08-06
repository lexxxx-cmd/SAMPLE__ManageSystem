#include "Manager.h"
#include "Person.h"
#include "Contestant.h"
#include <random>
#include <fstream>
#include <iostream>
#define FILENAME "historyInfo.txt"

Manager::Manager()
{
	//��ʼ���������Լ�ÿλѡ�ֵ���Ϣ
	this->numOfPerson = 12;
	//��ʼ��ÿλѡ�ֵ���Ϣ(�������Ա����䣬���)���ӵ�Pool��
	this->playerPool.reserve(this->numOfPerson);
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> u(15, 50);
	int t_age = 0;
	std::string t_gender = "��";
	std::string t_name = "";
	std::string nameFirst = "Person";
	std::string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0;i < this->numOfPerson;i++)
	{
		//���������
		t_age = u(gen);
		if (t_age % 2 == 0)
		{
			t_gender = "Ů";
		}
		else
		{
			t_gender = "��";
		}
		t_name = nameFirst + nameSeed[i];
		this->playerPool.push_back(Contestant(t_name,t_gender, t_age, 10001 + i));
	}
	//�����ļ�����д�ļ�
	std::ofstream ofs;
	ofs.open(FILENAME, std::ios::out);
	if (!ofs.is_open())
	{
		std::cout << "�ļ������ڣ����ڴ�������" << std::endl;
		this->hisFileEmpty = true;
		ofs.close();
	}
	else
	{
		//�ж��Ƿ�Ϊ��
		std::ifstream ifs;
		ifs.open(FILENAME, std::ios::in);
		char c;
		ifs >> c;
		if (ifs.eof())
		{
			std::cout << "�ļ�Ϊ�գ�����ʷ��¼!" << std::endl;
			this->hisFileEmpty = true;
			ifs.close();
		}
		else
		{
			std::cout << "�ļ����ڿɲ鿴����ʷ��¼!" << std::endl;
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
	std::cout << "****** 1����ʼ���� ******" << std::endl;
	std::cout << "****** 2���鿴��ʷ���� **" << std::endl;
	std::cout << "****** 3�������ʷ���� **" << std::endl;
	std::cout << "****** 4���˳�ϵͳ ******" << std::endl;
	std::cout << "*************************" << std::endl;

}
void Manager::ctrlWorkFlow()
{
	int temp=0;
	while (temp != 4)
	{
		std::cout << "���������" << std::endl;
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
			std::cout << "�밴��Ļ�ϵ�ѡ��������룡" << std::endl;
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
