#pragma once
#include "Person.h"
class Contestant :
    public Person
{
    int index;
    int team;
    double scores[2];
public:
    Contestant(std::string n, std::string g, int a, int i);
    ~Contestant();
    int getIndex();
    int getTeam();
    void setTeam(int i);
    double* getScore();
    void setScore(double i,int round);
    void showInfo();

    void speech();

};

