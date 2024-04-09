#pragma once
#include "Iterator.h"

class Aggregate abstract
{
public:
	virtual Iterator* CreateIterator() abstract;
};
