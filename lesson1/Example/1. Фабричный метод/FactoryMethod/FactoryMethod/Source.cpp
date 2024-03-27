#include <iostream>
using namespace std;

/*
��������� ����� (Factory Method) � ����������� ������ ��������������, ��������������� ���������� ��������� ��� �������� ����������� ���������� ������.
� ������ �������� ���������� ����� ����������, ����� ����� ���������������. ����� �������, ������� ���������� �������� �������� ����������� ������������� ������.
��� ��������� ������������ � ���� ��������� �� ������������� ������, � �������������� ������������ ��������� �� ����� ������� ������.
��������� �����  ���������� ��������� ��� �������� �������, �� ��������� ���������� ������� � ���, ����� ����� ���������������.

������������
-	������ ������� ����������, ������� ����� ���������� ��� ����� ���������.
-	����� ������������� ���, ����� �������, ������� �� ������, ����������������� �����������.
-	����� ���������� ���� ����������� ������ �� ���������� ��������������� ����������, � ����������� ������������ ������ � ���, ����� ����� ��������� ��� ����������� �� ����.

�����������
��������� ������ ��������� �������������� �� ������������� ���������� � ��� ��������� �� ���������� ������. ��� ����� ���� ������ � �����������
������ Product, ������� �� ����� �������� � ������ ������������� �������������� �������� ���������� ���������.
����������
������������� ���������� ���������� ������ ������� � ���, ��� ��������, ��������, �������� ��������� �������� ������ Creator ��� �������� ���� ������ ������� ConcreteProduct.
*/

//������� (House) ���������� ��������� ��������, ����������� ��������� �������
class House abstract
{ 
};

// ���������� ������� ��������� ��������� Product (� ����� ������, House)
class PanelHouse : public House
{
public:
	PanelHouse()
	{
		cout << "Panel house built\n";
	}
};

// ���������� ������� ��������� ��������� Product (� ����� ������, House)
class WoodHouse : public House
{
public:
	WoodHouse()
	{
		cout << "Wooden house built\n";
	}
};

// ���������� ������� ��������� ��������� Product (� ����� ������, House)
class BrickHouse : public House
{
public:
	BrickHouse()
	{
		cout << "Brick house built\n";
	}
};


// Creator ��������� ��������� �����, ������������ ������ ���� Product.
// ����������� ����� ������������ ��������
class Developer abstract
{
	// ��������� �����
public:
	virtual House* Create() = 0;
};

// ���������� ��������� �������� ��������� �����, ������������ ������ ConcreteProduct.
// ������ ��������� ����
class PanelDeveloper : public Developer
{
public:
	House* Create() override
	{
		return new PanelHouse;
	}
};

// ���������� ��������� �������� ��������� �����, ������������ ������ ConcreteProduct.
// ������ ���������� ����
class WoodDeveloper : public Developer
{
public:
	House* Create() override
	{
		return new WoodHouse;
	}
};

// ���������� ��������� �������� ��������� �����, ������������ ������ ConcreteProduct.
// ������ ���������� ����
class BrickDeveloper : public Developer
{
public:
	House* Create() override
	{
		return new BrickHouse;
	}
};

// ������� ��������� ������������ � ���������� ���� ��������� �� ������������� ������, � �������������� ������������ ��������� �� ����� ������� ������.
House * Client(Developer *pDev)
{
	return pDev->Create();
}

void main()
{
	Developer *pDev = new PanelDeveloper();
	House * pHouse = Client(pDev);
	delete pHouse;
	delete pDev;

	pDev = new WoodDeveloper();
	pHouse = Client(pDev);
	delete pHouse;
	delete pDev;

	pDev = new BrickDeveloper();
	pHouse = Client(pDev);
	delete pHouse;
	delete pDev;

	system("pause");
}
