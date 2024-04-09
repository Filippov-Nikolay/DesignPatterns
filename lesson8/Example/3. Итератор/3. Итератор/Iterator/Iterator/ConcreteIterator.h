#pragma once
#include "ConcreteAggregate.h"

class ConcreteIterator : public Iterator
{
	ConcreteAggregate* aggregate;
	int current = 0;

public:
	ConcreteIterator(ConcreteAggregate* aggregate);
	int First() override;
	int Next() override;
	int CurrentItem() override;
	bool IsDone() override;
};
