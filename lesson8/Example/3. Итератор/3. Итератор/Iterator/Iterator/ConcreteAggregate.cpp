#include "ConcreteIterator.h"

Iterator* ConcreteAggregate::CreateIterator()
{
	return new ConcreteIterator(this);
}

int ConcreteAggregate::GetCount()
{
	return items.size();
}
int& ConcreteAggregate::operator[](int index)
{
	if (index < 0 || index >= items.size())
		throw exception("Incorrect the index!\n");
	return items[index];
}
void ConcreteAggregate::AddItem(int value)
{
	items.push_back(value);
}