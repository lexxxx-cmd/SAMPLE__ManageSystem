#include "Person.h"

Person::Person(std::string n, std::string g, int a)
{
	this->name = n;
	this->gender = g;
	this->age = a;
}
Person::~Person() {

}
std::string Person::getName() {
	return this->name;
}
std::string Person::getgender() {
	return this->gender;
}
int Person::getAge() {
	return this->age;
}
void Person::showInfo()
{
	std::cout 
		<< " Name: " << this->getName() 
		<< " Gender: " << this->getgender() 
		<< " age is: " << this->getAge() 
		<< " years old!" 
		<< std::endl;
}
