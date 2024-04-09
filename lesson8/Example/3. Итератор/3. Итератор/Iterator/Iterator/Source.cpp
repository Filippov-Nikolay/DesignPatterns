#include <iostream>
#include "ConcreteAggregate.h"
using namespace std;

void client(Aggregate* a);

int main()
{
	try {
		ConcreteAggregate *a = new ConcreteAggregate();
		for (int i = 0; i < 5; i++)
			a->AddItem(i);
		client(a);
		for (int i = 0; i < 5; i++)
			a->AddItem(i + 5);
		client(a);
		delete a;
	}
	catch (exception ex)
	{
		cout << ex.what();
	}

	system("pause");
	return 0;
}


	
