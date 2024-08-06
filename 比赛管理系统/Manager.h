#pragma once
//�������ṩ�˵��������û�����
//�����ݽ���������
//�ļ��Ķ�д����
#include <vector>
class Contestant;
class Manager
{
	int numOfPerson;
	//��ʼ
	std::vector<Contestant> playerPool;
	//��һ�ַ�����ֱ��������
	std::vector<Contestant> stageOnePool1;
	std::vector<Contestant> stageOnePool2;
	bool hisFileEmpty;
public:
	friend void pull(std::vector<Contestant>& P);
	Manager();
	~Manager();
	void showMenu();
	void ctrlWorkFlow();
	void startContest();
	void checkHistoryFile();
	void reviseHistoryFile();
	void clearHistoryFile();

	void showCurrentContestant(std::vector<Contestant> P);
	void Group();



};

