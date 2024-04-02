#include<windows.h>
#include <iostream>
#include <string>
using namespace std;

/*
 * Proxy �������� ���������� ������� ������� � ������������ ������ � ����.
 * ������� ��������� �������� � �������, ��������� ����� ����� �������� ������� �� �������� � ������������� �� �������,
 * ����� ������ ������������� �����������.
 */

 // Subject (IMath) ���������� ����� ��� RealSubject � Proxy ���������, 
// ��� ��� ����� Proxy ����� ������������ �����, ��� ��������� RealSubject.

class IMath
{
public:
	virtual double Add(double x, double y) abstract;
	virtual double Sub(double x, double y) abstract;
	virtual double Mult(double x, double y) abstract;
	virtual double Div(double x, double y) abstract;
};

// RealSubject (Math) - ���������� �������� ������, �������������� ������������.
class Math : public IMath
{
public:
	Math()
	{
		cout << "Create object Math. Wait...\n";
		Sleep(3000);
	}
	double Add(double x, double y) override
	{ 
		return x + y; 
	}
	double Sub(double x, double y) override
	{ 
		return x - y; 
	}
	double Mult(double x, double y) override
	{ 
		return x * y; 
	}
	double Div(double x, double y) override
	{ 
		return x / y; 
	}
};

/*
 * Proxy (MathProxy) - �����������:
- ������ ������, ������� ��������� ����������� ���������� � ��������� ��������.
  ������ ������ Proxy ����� ���������� � ������� ������ Subject, ���� ���������� ������� RealSubject � Subject ���������;
- ������������� ���������, ���������� ���������� Subject, ��� ��� ����������� ������ ����� ���� ���������� ������ ��������� ��������;
- ������������ ������ � ��������� �������� � ����� �������� �� ��� �������� � ��������;
 */

class MathProxy : public IMath
{
	Math *math;
public:
	MathProxy()
	{
		math = nullptr;
	}
	~MathProxy()
	{
		delete math;
	}
	// ������� �������� - �� ������� ��������� ��������
	double Add(double x, double y)
	{
		return x + y;
	}
	// ������� �������� - �� ������� ��������� ��������
	double Sub(double x, double y)
	{
		return x - y;
	}
	// ��������� �������� - ������� �������� ��������� ��������
	double Mult(double x, double y)
	{
		if (math == nullptr)
			math = new Math();
		return math->Mult(x, y);
	}
	// ��������� �������� - ������� �������� ��������� ��������
	double Div(double x, double y)
	{
		if (math == nullptr)
			math = new Math();
		return math->Div(x, y);
	}
};

void client(IMath *p)
{
	char s[20];
	sprintf_s(s, "4 + 2 = %f\n", p->Add(4, 2));
	cout << s;
	sprintf_s(s, "4 - 2 = %f\n", p->Sub(4, 2));
	cout << s;
	sprintf_s(s, "4 * 2 = %f\n", p->Mult(4, 2));
	cout << s;
	sprintf_s(s, "4 / 2 = %f\n", p->Div(4, 2));
	cout << s;
}
int main()
{
	IMath *p = new MathProxy();
	client(p);

	system("pause");
	return 0;
}


