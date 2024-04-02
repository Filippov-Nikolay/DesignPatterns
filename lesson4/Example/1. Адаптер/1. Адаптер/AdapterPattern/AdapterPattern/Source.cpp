#include <iostream>
using namespace std;

// ������� ������� ����������� ��������� ������ ������ � ��������� �������, ������� ������� �������.
// ������� ������������ ���������� ������ ������� � �������������� ������������, ������� ��� ���� ���� �� ����������.

// ITarget - ���������� ��������� �� ���������� ������� ���������, ������� ���������� Client.
class ITarget abstract
{
public:
	virtual void Request() abstract;
};

// Adaptee - ���������� ������������ ���������, ������� ��������� � ���������.
class Adaptee
{
public:
	void SpecificRequest()
	{
		cout << "Called SpecificRequest()";
	}
};

// Adapter - ���������� ��������� Adaptee � ���������� Target.
class Adapter: public ITarget
{
	Adaptee adaptee;
public:
	void Request() override
	{
		adaptee.SpecificRequest();
	}
};



// Client - �������� �� ��������������� � ���������, ���������������� ���������� Target.
int main()
{
	ITarget * target = new Adapter();
	// ������ ���������� � �������� � ��������, ������� ��� ����� ����� ������� ���������.
	// ������� ����������� ������ � ���� ��� ��������� ������� � ������������� �������.
	// ������ �������� ���������� ������, ���� �� ���������� � ���������������, ����������� ���������.
	target->Request();
	system("pause");
	return 0;
}


	

