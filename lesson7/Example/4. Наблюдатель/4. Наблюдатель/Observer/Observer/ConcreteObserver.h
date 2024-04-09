#pragma once
#include "Observer.h"
#include "Clock.h"
#include <string>

/*
 ConcreteObserver - конкретный наблюдатель:
	 - хранит ссылку на объект класса ConcreteSubject;
	 - сохраняет данные, которые должны быть согласованы с данными субъекта;
	 - реализует интерфейс обновления, определенный в классе Observer, чтобы поддерживать согласованность с субъектом.
*/

class ConcreteObserver: public Observer
{
	Clock* clock;
	string name;

public:
	ConcreteObserver(Clock* clock, string name);
	void Update() override;
	Clock* GetClock();
	void SetClock(Clock* clock);
};