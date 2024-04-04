#include <iostream>
using namespace std;

/*
 Паттерн Bridge позволяет отделить абстракцию от ее реализации так, 
 чтобы то и другое можно было изменять независимо.

Данный паттерн используется когда:
- нужно избежать постоянной привязки абстракции к реализации. 
Так, например, бывает, когда реализацию необходимо выбирать во время выполнения программы.
- и абстракции, и реализации должны расширяться новыми подклассами. 
В таком случае паттерн мост позволяет комбинировать разные абстракции и реализации и изменять их независимо;
- изменения в реализации абстракции не должны сказываться на клиентах, то есть клиентский код не должен перекомпилироваться;

Результаты:
- отделение реализации от интерфейса;
- повышение степени расширяемости;
- сокрытие деталей реализации от клиентов.
*/

/* 
Implementor - реализатор определяет интерфейс для классов реализации. 
*/
class Implementor abstract
{
public:
	virtual void Operation() abstract;
};

// Concretelmplementor  - конкретный реализатор  содержит конкретную реализацию интерфейса класса Implementor.
class DrawFigureInLinux: public Implementor
{
public:
	void Operation() override
	{
		cout << "\nFeatures of drawing a shape in the system Linux\n";
	}
};

// Concretelmplementor  - конкретный реализатор  содержит конкретную реализацию интерфейса класса Implementor.
class DrawFigureInWindows: public Implementor
{
public:
	void Operation() override
	{
		cout << "\nFeatures of drawing a shape in the system Windows\n";
	}
};

// Abstraction (figure) - определяет интерфейс абстракции и хранит ссылку на объект реализации типа Implementor
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

// RefinedAbstraction  - утонченная абстракция расширяет интерфейс, определенный абстракцией Abstraction
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

// RefinedAbstraction  - утонченная абстракция расширяет интерфейс, определенный абстракцией Abstraction
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

// RefinedAbstraction  - утонченная абстракция расширяет интерфейс, определенный абстракцией Abstraction
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
	// Объект Abstraction (figure) перенаправляет своему объекту Implementor запросы клиента.
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


