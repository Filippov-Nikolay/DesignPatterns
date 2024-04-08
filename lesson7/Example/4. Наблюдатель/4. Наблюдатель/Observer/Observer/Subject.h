#pragma once
#include "Observer.h"
#include <vector>

using namespace std;

/* Subject
- субъект: располагает информацией о своих наблюдателях. За субъектом может «следить» любое число наблюдателей;
- предоставляет интерфейс для присоединения и отделения наблюдателей;
*/
class Subject abstract
{
	vector<Observer*> observers;
public:
	void Attach(Observer* observer);
	void Detach(Observer* observer);
	void Notify();
};
