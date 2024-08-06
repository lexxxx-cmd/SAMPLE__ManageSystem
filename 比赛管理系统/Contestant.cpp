#include "Contestant.h"

Contestant::Contestant(std::string n, std::string g, int a, int i):Person(n,g,a)
{
	this->index = i;
	this->team = 0;
	this->scores[0] = 0;
	this->scores[1] = 0;
}
Contestant::~Contestant()
{

}
int Contestant::getIndex()
{
	return this->index;
}
int Contestant::getTeam() {
	return this->team;
}
void Contestant::setTeam(int i)
{
	this->team = i;
}
double* Contestant::getScore() {
	return this->scores;
}
void Contestant::setScore(double i)
{
	this->scores[0] = i;
}
void Contestant::showInfo()
{
	std::cout
		<< " Index: " << this->getIndex()
		<< " Name: " << this->getName()
		<< " Gender: " << this->getgender()
		<< " Age is: " << this->getAge()
		<< " years old!"
		<< " Team is: " << this->getTeam()
		<< " Score(stage 1) is: " << this->getScore()[0] << " Score(stage 2) is: " << this->getScore()[1]
		<< std::endl;
}
void Contestant::speech()
{
	std::cout << this->getName() << "is speaking......." << std::endl;
}
