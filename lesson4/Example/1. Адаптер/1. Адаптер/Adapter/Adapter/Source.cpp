#include <iostream>
using namespace std;

// Паттерн Адаптер преобразует интерфейс одного класса в интерфейс другого, который ожидают клиенты.
// Адаптер обеспечивает совместную работу классов с несовместимыми интерфейсами, которая без него была бы невозможна.

// ITarget - определяет зависящий от предметной области интерфейс, которым пользуется Client.
// интерфейс транспортного средства
class ITransport abstract
{
public:
	virtual void Drive() abstract;
};

// класс автомобиля, реализующий интерфейс Adaptee (ITransport), который ожидают клиенты.
class Auto : public ITransport
{
public:
	void Drive() override
	{
		cout << "The car drive on the road.\n";
	}
};

// Client - вступает во взаимоотношения с объектами, удовлетворяющими интерфейсу Target (ITransport).
// класс путешественника (водителя)
class Driver
{
public:
	void Travel(ITransport * transport)
	{
		transport->Drive();
	}
};

// Adaptee - определяет существующий интерфейс, который нуждается в адаптации.
// интерфейс животного
class IAnimal abstract
{
public:
	virtual void Move() abstract;
};

// класс верблюда, реализующий интерфейс Adaptee (IAnimal)
class Camel : public IAnimal
{
public:
	void Move() override
	{
		cout << "Camel rides on the sands of the desert.\n";
	}
};
// класс лошади, реализующий интерфейс Adaptee (IAnimal)
class Horse : public IAnimal
{
public:
	void Move() override
	{
		cout << "Horse rides on the sands of the desert.\n";
	}
};

// Adapter - адаптирует интерфейс Adaptee к интерфейсу Target.
// Адаптер от Camel к ITransport
class AnimalToTransportAdapter : public ITransport
{
	IAnimal* animal;
public:
	void SetAnimalToTransportAdapter(IAnimal* animal)
	{
		this->animal = animal;
	}
	void Drive()
	{
		animal->Move();
	}
};

int main()
{
	// путешественник
	Driver driver;
	// автомобиль
	Auto car;
	ITransport * transport = &car;
	// отправляемся в путешествие
	driver.Travel(transport);
	// встретились пески, необходимо использовать верблюда
	IAnimal* animal = new Camel();
	// Используем адаптер, который преобразует запрос в один или несколько вызовов к адаптируемому объекту.
	AnimalToTransportAdapter adapter;
	adapter.SetAnimalToTransportAdapter(animal);
	transport = &adapter;
	// продолжаем путь по пескам пустыни
	driver.Travel(transport);
	// driver.Travel(&adapter);

	delete animal;

	animal = new Horse();
	adapter.SetAnimalToTransportAdapter(animal);
	transport = &adapter;
	driver.Travel(transport);

	system("pause");
	return 0;
}
	
	

