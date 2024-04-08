#include <iostream>

using namespace std;

/*
		ѕаттерн Chain of Responsibility (÷епочка ќб€занностей) позвол€ет отделить отправител€ запроса от его получател€,
		предоставл€€ возможность нескольким классамЦобработчикам определить, кто из них может данный запрос обработать.
		“от, кто инициирует запрос, как правило, не обладает информацией о том, кто именно из классов, потенциально имеющий
		такую возможность, данный запрос в конечном итоге обработает.
		¬ такой схеме существует несколько классов Ц Handler-ов (обработчиков), каждый из которых наделЄн своими ограниченными
		возможност€ми обработки подобных запросов. ѕричЄм эти объекты - Handler-ы выстраиваютс€ в цепочку (от самых слабых до самых сильных)
		и каждый из них знает, кому он перебросит запрос в том случае, если сам не сможет справитьс€ с его обработкой.
		ѕоследний в цепочке Handler, как правило, обладающий самыми высокими возможност€ми, если сам не может обработать запрос,
		предоставл€ет какое-то поведение по умолчанию или генерирует исключение.
*/

class Handler abstract
{
protected:
	Handler* successor;
public:
	void SetSuccessor(Handler* successor)
	{
		this->successor = successor;
	}
	virtual void HandleRequest(int request) abstract;
};

class ConcreteHandler1: public Handler
{
public:
	void HandleRequest(int request) override
	{
		if (request >= 0 && request < 10)
		{
			char buffer[100];
			sprintf_s(buffer, "%s handled request %d\n", typeid(*this).name(), request);
			cout << buffer;
		}
		else if (successor != nullptr)
		{
			successor->HandleRequest(request);
		}
	}
};

class ConcreteHandler2: public Handler
{
public:
	void HandleRequest(int request) override
	{
		if (request >= 10 && request < 20)
		{
			char buffer[100];
			sprintf_s(buffer, "%s handled request %d\n", typeid(*this).name(), request);
			cout << buffer;
		}
		else if (successor != nullptr)
		{
			successor->HandleRequest(request);
		}
	}
};

class ConcreteHandler3 : public Handler
{
public:
	void HandleRequest(int request) override
	{
		if (request >= 20 && request < 30)
		{
			char buffer[100];
			sprintf_s(buffer, "%s handled request %d\n", typeid(*this).name(), request);
			cout << buffer;
		}
		else if (successor != nullptr)
		{
			successor->HandleRequest(request);
		}
	}
};

class ConcreteHandler4 : public Handler
{
public:
	void HandleRequest(int request) override
	{
		if (request >= 30 && request <= 100)
		{
			char buffer[100];
			sprintf_s(buffer, "%s handled request %d\n", typeid(*this).name(), request);
			cout << buffer;
		}
		else if (successor != nullptr)
		{
			successor->HandleRequest(request);
		}
	}
};

class ConcreteHandler5 : public Handler
{
public:
	void HandleRequest(int request) override
	{
		if (request < 0)
		{
			char buffer[100];
			sprintf_s(buffer, "%s handled request %d\n", typeid(*this).name(), request);
			cout << buffer;
		}
		else if (successor != nullptr)
		{
			successor->HandleRequest(request);
		}
	}
};


void Request(Handler* h, int *requests, int size)
{
	for (int i = 0; i < size; i++)
	{
		h->HandleRequest(requests[i]);
	}
}

int main()
{
	Handler* h1 = new ConcreteHandler1();
	Handler* h2 = new ConcreteHandler2();
	Handler* h3 = new ConcreteHandler3();
	Handler* h4 = new ConcreteHandler4();
	Handler* h5 = new ConcreteHandler5();

	h1->SetSuccessor(h2);
	h2->SetSuccessor(h3);
	h3->SetSuccessor(h4);
	h4->SetSuccessor(h5);

	int requests[] = { 2, 5, 14, 22, 18, 3, 27, 20, 100, -19 };
	Request(h1, requests, 10);
	
	delete h1;
	delete h2;
	delete h3;

	system("pause");
	return 0;
}
