#pragma once
//�������ṩ�˵��������û�����
//�����ݽ���������
//�ļ��Ķ�д����
#include <vector>
class Contestant;
class Manager
{
	int numOfPerson;
	std::vector<Contestant> playerPool;
	bool hisFileEmpty;
public:
	Manager();
	~Manager();
	void showMenu();
	void ctrlWorkFlow();
	void startContest();
	void checkHistoryFile();
	void reviseHistoryFile();
	void clearHistoryFile();

	void showCurrentContestant();
	void Group();

};

