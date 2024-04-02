#include <iostream>
#include <string>
using namespace std;

// паттерн Decorator динамически добавляет объекту новые обязанности. 
// Является гибкой альтернативой порождению подклассов с целью расширения функциональности.

// Component (Pizza) - компонент определяет интерфейс для объектов, на которые могут быть динамически возложены дополнительные обязанности
class Pizza abstract
{	
protected:
	string Name;
public:
	Pizza(string n)
	{
		Name = n;
	}
	string GetName()
	{
		return Name;
	}
	virtual int GetCost()abstract;
};

// ConcreteComponent (ItalianPizza) - конкретный компонент определяет объект, на который возлагаются дополнительные обязанности
class ItalianPizza: public Pizza
{
public:
	ItalianPizza(): Pizza("Italian pizza")
	{ }
	int GetCost() override
	{
		return 10;
	}
};
// ConcreteComponent (BulgarianPizza) - конкретный компонент определяет объект, на который возлагаются дополнительные обязанности
class BulgarianPizza: public Pizza
{
public:
	BulgarianPizza(): Pizza("Bulgarian pizza")
	{ }
	int GetCost() override
	{
		return 8;
	}
};

// Decorator (PizzaDecorator) хранит ссылку на объект Component и определяет интерфейс, соответствующий интерфейсу Component
class PizzaDecorator abstract: public Pizza
{
protected:
	Pizza *pizza;
public:
	PizzaDecorator(string n, Pizza* pizza): Pizza(n)
	{
		this->pizza = pizza;
	}
};

// ConcreteDecorator (TomatoPizza) - конкретный декоратор возлагает дополнительные обязанности на компонент.
class TomatoPizza: public PizzaDecorator
{
public:
	TomatoPizza(Pizza* p): PizzaDecorator(p->GetName() + " with tomatoes", p){ }
	int GetCost() override
	{
		return pizza->GetCost() + 3;
	}
};

// ConcreteDecorator (CheesePizza) - конкретный декоратор возлагает дополнительные обязанности на компонент.
class CheesePizza: public PizzaDecorator
{
public:
	CheesePizza(Pizza* p): PizzaDecorator(p->GetName() + " with cheese", p){ }
	int GetCost() override
	{
		return pizza->GetCost() + 5;
	}
};

class PineapplesPizza : public PizzaDecorator
{
public:
	PineapplesPizza(Pizza* p) : PizzaDecorator(p->GetName() + " with pineapples", p) { }
	int GetCost() override
	{
		return pizza->GetCost() + 8;
	}
};

class HotPeppersPizza : public PizzaDecorator
{
public:
	HotPeppersPizza(Pizza* p) : PizzaDecorator(p->GetName() + " with hot peppers", p) { }
	int GetCost() override
	{
		return pizza->GetCost() + 4;
	}
};


void client(Pizza * p)
{
	char s[100];
	sprintf_s(s, "Name: %s  Cost: %d", p->GetName().c_str(), p->GetCost());
	cout << s << endl;
}

int main()
{
	Pizza *p = new ItalianPizza();
	p = new TomatoPizza(p); // итальянская пицца с томатами
	client(p);

	p = new ItalianPizza();
	p = new CheesePizza(p);// итальянская пицца с сыром
	client(p);

	p = new BulgarianPizza();
	p = new TomatoPizza(p);
	p = new CheesePizza(p);// болгарская пицца с томатами и сыром
	client(p);

	p = new ItalianPizza();
	p = new TomatoPizza(p);
	p = new CheesePizza(p);
	p = new PineapplesPizza(p);
	p = new HotPeppersPizza(p);
	client(p);

	delete p;

	system("pause");
}