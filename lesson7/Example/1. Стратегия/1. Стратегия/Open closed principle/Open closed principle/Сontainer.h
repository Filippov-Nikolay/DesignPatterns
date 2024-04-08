#pragma once
#include "Human.h"
#include "ILog.h"
#include "IStream.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

/*
  * Принцип открытости/закрытости — принцип объектно-ориентированного программирования,
  * устанавливающий следующее положение: «программные сущности (классы, модули, функции и т.п.)
  * должны быть открыты для расширения, но закрыты для изменения»; это означает, что такие
  * сущности могут позволять менять свое поведение без изменения их исходного кода.
  */

class Сontainer
{
	vector<Human> human;
	// Поскольку класс Container зависит от фиксированной абстракции, то он закрыт от модификации.
	// Однако поведение класса можно расширять, создавая новые производные классы от абстракции.
	ILog * pILog;
	IStream * pIStream;

public:
	void SetSerializer(IStream * pIStream)
	{
		this->pIStream = pIStream;
	}
	void SetLog(ILog * pILog)
	{
		this->pILog = pILog;
	}

	void Add(Human human);
	
	void Remove(int index);
	
	void RemoveAll();
	
	void Print();
	
	void Save();
	
	void Load();
};
