#pragma once
#include <iostream>
class Person
{
	std::string name;
	std::string gender;
	int age;
public:
	Person(std::string n, std::string g, int age);
	~Person();
	std::string getName();
	std::string getgender();
	int getAge();
	void showInfo();
};

