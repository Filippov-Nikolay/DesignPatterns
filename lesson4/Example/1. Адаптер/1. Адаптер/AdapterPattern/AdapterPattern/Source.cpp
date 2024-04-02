#include <iostream>
using namespace std;

// Паттерн Адаптер преобразует интерфейс одного класса в интерфейс другого, который ожидают клиенты.
// Адаптер обеспечивает совместную работу классов с несовместимыми интерфейсами, которая без него была бы невозможна.

// ITarget - определяет зависящий от предметной области интерфейс, которым пользуется Client.
class ITarget abstract
{
public:
	virtual void Request() abstract;
};

// Adaptee - определяет существующий интерфейс, который нуждается в адаптации.
class Adaptee
{
public:
	void SpecificRequest()
	{
		cout << "Called SpecificRequest()";
	}
};

// Adapter - адаптирует интерфейс Adaptee к интерфейсу Target.
class Adapter: public ITarget
{
	Adaptee adaptee;
public:
	void Request() override
	{
		adaptee.SpecificRequest();
	}
};



// Client - вступает во взаимоотношения с объектами, удовлетворяющими интерфейсу Target.
int main()
{
	ITarget * target = new Adapter();
	// Клиент обращается с запросом к адаптеру, вызывая его метод через целевой интерфейс.
	// Адаптер преобразует запрос в один или несколько вызовов к адаптируемому объекту.
	// Клиент получает результаты вызова, даже не подозревая о преобразованиях, выполненных адаптером.
	target->Request();
	system("pause");
	return 0;
}


	

