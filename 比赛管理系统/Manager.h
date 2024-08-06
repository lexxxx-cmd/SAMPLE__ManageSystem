#pragma once
//在这里提供菜单界面与用户互动
//控制演讲比赛流程
//文件的读写交互
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

