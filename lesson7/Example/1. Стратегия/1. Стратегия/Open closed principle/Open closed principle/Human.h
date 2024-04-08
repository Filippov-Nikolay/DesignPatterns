#pragma once
#include <string>
using namespace std;

class Human
{
	string name;
	int age;

public:
	Human() = default;
	~Human() {}
	Human(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	int GetAge()
	{
		return this->age;
	}
	void SetAge(int age)
	{
		this->age = age;
	}
	string GetName()
	{
		return this->name;
	}
	void SetName(string name)
	{
		this->name = name;
	}
};
