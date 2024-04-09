#pragma once
#include <vector>
#include "Aggregate.h"
using namespace std;

class ConcreteAggregate : public Aggregate
{
	vector<int> items;
public:
	Iterator* CreateIterator() override;
	int GetCount();
	int& operator[](int index);
	void AddItem(int value);
};