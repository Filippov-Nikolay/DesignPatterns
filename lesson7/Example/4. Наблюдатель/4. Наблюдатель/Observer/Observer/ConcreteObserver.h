#pragma once
#include "Observer.h"
#include "Clock.h"
#include <string>

/*
 ConcreteObserver - ���������� �����������:
	 - ������ ������ �� ������ ������ ConcreteSubject;
	 - ��������� ������, ������� ������ ���� ����������� � ������� ��������;
	 - ��������� ��������� ����������, ������������ � ������ Observer, ����� ������������ ��������������� � ���������.
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