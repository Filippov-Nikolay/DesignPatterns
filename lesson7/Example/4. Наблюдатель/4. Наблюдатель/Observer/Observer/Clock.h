#pragma once
#include "Subject.h"

/*
  ConcreteSubject - конкретный субъект:
	 - сохраняет состояние, представляющее интерес для конкретного наблюдателя ConcreteObserver;
	 - посылает информацию своим наблюдателям, когда происходит изменение;
*/
class Clock : public Subject
{
	int hours;
	int minutes;
	int seconds;
public:
	int GetHours()
	{
		return hours;
	}
	void SetHours(int h)
	{
		hours = h;
	}
	int GetMinutes()
	{
		return minutes;
	}
	void SetMinutes(int m)
	{
		minutes = m;
	}
	int GetSeconds()
	{
		return seconds;
	}
	void SetSeconds(int s)
	{
		seconds = s;
	}
};
