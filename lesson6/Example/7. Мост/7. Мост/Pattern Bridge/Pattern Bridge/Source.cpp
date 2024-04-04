#include <iostream>
using namespace std;

/*
 ������� Bridge ��������� �������� ���������� �� �� ���������� ���, 
 ����� �� � ������ ����� ���� �������� ����������.

������ ������� ������������ �����:
- ����� �������� ���������� �������� ���������� � ����������. 
���, ��������, ������, ����� ���������� ���������� �������� �� ����� ���������� ���������.
- � ����������, � ���������� ������ ����������� ������ �����������. 
� ����� ������ ������� ���� ��������� ������������� ������ ���������� � ���������� � �������� �� ����������;
- ��������� � ���������� ���������� �� ������ ����������� �� ��������, �� ���� ���������� ��� �� ������ �������������������;

����������:
- ��������� ���������� �� ����������;
- ��������� ������� �������������;
- �������� ������� ���������� �� ��������.
*/

/* 
Implementor - ���������� ���������� ��������� ��� ������� ����������. 
*/
class Implementor abstract
{
public:
	virtual void Operation() abstract;
};

// Concretelmplementor  - ���������� ����������  �������� ���������� ���������� ���������� ������ Implementor.
class DrawFigureInLinux: public Implementor
{
public:
	void Operation() override
	{
		cout << "\nFeatures of drawing a shape in the system Linux\n";
	}
};

// Concretelmplementor  - ���������� ����������  �������� ���������� ���������� ���������� ������ Implementor.
class DrawFigureInWindows: public Implementor
{
public:
	void Operation() override
	{
		cout << "\nFeatures of drawing a shape in the system Windows\n";
	}
};

// Abstraction (figure) - ���������� ��������� ���������� � ������ ������ �� ������ ���������� ���� Implementor
class figure abstract
{
protected:
	double x;
	double y;
	Implementor* implementor;
public:
	void setDimension(double i, double j)
	{
		x = i;
		y = j;
	}
	
	Implementor* GetImplementor()
	{
		return implementor;
	}
	void SetImplementor(Implementor* implementor)
	{
		this->implementor = implementor;
	}
	
	virtual void AreaFigure() abstract;
	virtual void DrawFigure() abstract;
};

// RefinedAbstraction  - ���������� ���������� ��������� ���������, ������������ ����������� Abstraction
class triangle: public figure
{
public:
	void AreaFigure() override
	{
		cout << "\nArea of the triangle: " << x * 0.5 * y << endl;
	}
	void DrawFigure() override
	{
		implementor->Operation();
		cout << "\nDraw the triangle" << endl;
	}
};

// RefinedAbstraction  - ���������� ���������� ��������� ���������, ������������ ����������� Abstraction
class rectangle : public figure
{
public:
	void AreaFigure() override
	{
		cout << "\nArea of the rectangle: " << x * y << endl;
	}
	void DrawFigure() override
	{
		implementor->Operation();
		cout << "\nDraw the rectangle" << endl;
	}
};

// RefinedAbstraction  - ���������� ���������� ��������� ���������, ������������ ����������� Abstraction
class circle : public figure
{
public:
	void AreaFigure() override
	{
		cout << "\nArea of the circle: " << 3.14 * x * x << endl;
	}
	void DrawFigure() override
	{
		implementor->Operation();
		cout << "\nDraw the circle" << endl;
	}
};

void Draw(figure* p, Implementor * impl)
{
	// ������ Abstraction (figure) �������������� ������ ������� Implementor ������� �������.
	p->DrawFigure();
	p->AreaFigure();
}

int main()
{
	figure* p = nullptr;
	cout << "1. Area of the triangle\n2. Area of the rectangle\n3. Area of the circle\n";
	cout << "Make your choice: ";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		p = new triangle();
		p->setDimension(5.5, 10.0);
		break;
	case 2:
		p = new rectangle();
		p->setDimension(5.5, 10.0);
		break;
	case 3:
		p = new circle();
		p->setDimension(10.0, 0);
		break;
	default:
		cout << "Incorrect the choice!" << endl;
		return 0;
	}
	cout << "\n1. Linux\n2. Windows\n";
	cout << "Make your choice: ";
	cin >> choice;
	Implementor * impl = nullptr;
	if (choice == 1)
	{
		impl = new DrawFigureInLinux();
		p->SetImplementor(impl);
	}
	else if (choice == 2)
	{
		impl = new DrawFigureInWindows();
		p->SetImplementor(impl);
	}
	else
	{
		cout << "Incorrect the choice!" << endl;
		return 0;
	}
	Draw(p, impl);
	delete p;
	delete impl;
	system("pause");
	return 0;
}


