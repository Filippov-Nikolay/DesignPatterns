#include "ConcreteObserver.h"
#include <iostream>
#include <string>

using namespace std;

ConcreteObserver::ConcreteObserver(Clock* clock, string name)
{
	this->clock = clock;
	this->name = name;
}
void ConcreteObserver::Update()
{
	char buffer[20];
	sprintf_s(buffer, " - %2d:%2d:%2d", clock->GetHours(), clock->GetMinutes(), clock->GetSeconds());
	cout << name << buffer << endl;
}
Clock* ConcreteObserver::GetClock()
{
	return this->clock;
}
void ConcreteObserver::SetClock(Clock* clock)
{
	this->clock = clock;
}