#include "Subject.h"

void Subject::Attach(Observer* observer)
{
	observers.push_back(observer);
}
void Subject::Detach(Observer* observer)
{
	auto iter = find(observers.begin(), observers.end(), observer);
	if (iter != observers.end())
		observers.erase(iter);
}
void Subject::Notify()
{
	for (Observer* o : observers)
	{
		o->Update();
	}
}