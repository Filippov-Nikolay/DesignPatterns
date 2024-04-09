#include "ConcreteIterator.h"

ConcreteIterator::ConcreteIterator(ConcreteAggregate* aggregate)
{
	this->aggregate = aggregate;
}

bool ConcreteIterator::IsDone()
{
	bool result = current >= aggregate->GetCount() - 1;
	if (result)
		current = 0;
	return result;
}

int ConcreteIterator::First() 
{
	return (*aggregate)[0];
}

int ConcreteIterator::Next() 
{
	return	(*aggregate)[++current];
}

int ConcreteIterator::CurrentItem() 
{
	return (*aggregate)[current];
}