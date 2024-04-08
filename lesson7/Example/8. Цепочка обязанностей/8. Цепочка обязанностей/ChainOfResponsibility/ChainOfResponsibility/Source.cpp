#include <iostream>

using namespace std;

/*
		������� Chain of Responsibility (������� ������������) ��������� �������� ����������� ������� �� ��� ����������,
		������������ ����������� ���������� ������������������� ����������, ��� �� ��� ����� ������ ������ ����������.
		���, ��� ���������� ������, ��� �������, �� �������� ����������� � ���, ��� ������ �� �������, ������������ �������
		����� �����������, ������ ������ � �������� ����� ����������.
		� ����� ����� ���������� ��������� ������� � Handler-�� (������������), ������ �� ������� ������ ������ �������������
		������������� ��������� �������� ��������. ������ ��� ������� - Handler-� ������������� � ������� (�� ����� ������ �� ����� �������)
		� ������ �� ��� �����, ���� �� ���������� ������ � ��� ������, ���� ��� �� ������ ���������� � ��� ����������.
		��������� � ������� Handler, ��� �������, ���������� ������ �������� �������������, ���� ��� �� ����� ���������� ������,
		������������� �����-�� ��������� �� ��������� ��� ���������� ����������.
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
