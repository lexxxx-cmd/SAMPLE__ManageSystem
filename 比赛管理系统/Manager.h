#pragma once
//在这里提供菜单界面与用户互动
//控制演讲比赛流程
//文件的读写交互
#include <vector>
class Contestant;
class Manager
{
	int numOfPerson;
	//初始
	std::vector<Contestant> playerPool;
	//第一轮分两组分别比赛排序
	std::vector<Contestant> stageOnePool1;
	std::vector<Contestant> stageOnePool2;
	//决赛组
	std::vector<Contestant> finalPool;
	bool hisFileEmpty;
public:
	friend void pull(std::vector<Contestant>& P);
	Manager();
	~Manager();
	void showMenu();
	void ctrlWorkFlow();
	void startContest();
	void checkHistoryFile();
	void reviseHistoryFile(std::vector<Contestant>& P);
	void clearHistoryFile();

	void showCurrentContestant(std::vector<Contestant>& P);
	void Group();

	double Score();
	void advanceToNextRound(std::vector<Contestant>& P);
	void save();
	void teamSpeech(std::vector<Contestant>& P,int round);



};

