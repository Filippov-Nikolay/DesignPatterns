#include "Aggregate.h"
#include <iostream>
using namespace std;

void client(Aggregate* a)
{
	Iterator* i = a->CreateIterator();
	cout << "Iterating over array:\n";
	int item = i->First();
	while (!i->IsDone())
	{
		cout << item << endl;
		item = i->Next();
	}
	cout << item << endl;
	delete i;
}