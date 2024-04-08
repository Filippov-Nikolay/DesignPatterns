#include <iostream>
#include "ConcreteObserver.h"
using namespace std;

	/*
	 * Паттерн Наблюдатель позволяет определить взаимоотношения между объектами таким образом,
	 * что если один из них меняет своё состояние, остальные тут же об этом оповещаются.
	 * Благодаря слабой связанности между объектами классов Subject и Observer, можно менять их независимо друг от друга.
	 */

int main()
{
	Clock* pClock = new Clock();

	Observer* o1 = new ConcreteObserver(pClock, "Observer #1");
	Observer* o2 = new ConcreteObserver(pClock, "Observer #2");
	Observer* o3 = new ConcreteObserver(pClock, "Observer #3");

	pClock->Attach(o1);
	pClock->Attach(o2);
	pClock->Attach(o3);

	pClock->SetHours(10);
	pClock->SetMinutes(20);
	pClock->SetSeconds(30);
	pClock->Notify();

	pClock->Detach(o2);
	pClock->Notify();

	pClock->Detach(o1);
	pClock->Notify();

	delete pClock;
	delete o1;
	delete o2;
	delete o3;

	system("pause");
	return 0;
}