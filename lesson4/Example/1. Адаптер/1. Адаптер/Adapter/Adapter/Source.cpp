#include <iostream>
using namespace std;

// ������� ������� ����������� ��������� ������ ������ � ��������� �������, ������� ������� �������.
// ������� ������������ ���������� ������ ������� � �������������� ������������, ������� ��� ���� ���� �� ����������.

// ITarget - ���������� ��������� �� ���������� ������� ���������, ������� ���������� Client.
// ��������� ������������� ��������
class ITransport abstract
{
public:
	virtual void Drive() abstract;
};

// ����� ����������, ����������� ��������� Adaptee (ITransport), ������� ������� �������.
class Auto : public ITransport
{
public:
	void Drive() override
	{
		cout << "The car drive on the road.\n";
	}
};

// Client - �������� �� ��������������� � ���������, ���������������� ���������� Target (ITransport).
// ����� ��������������� (��������)
class Driver
{
public:
	void Travel(ITransport * transport)
	{
		transport->Drive();
	}
};

// Adaptee - ���������� ������������ ���������, ������� ��������� � ���������.
// ��������� ���������
class IAnimal abstract
{
public:
	virtual void Move() abstract;
};

// ����� ��������, ����������� ��������� Adaptee (IAnimal)
class Camel : public IAnimal
{
public:
	void Move() override
	{
		cout << "Camel rides on the sands of the desert.\n";
	}
};
// ����� ������, ����������� ��������� Adaptee (IAnimal)
class Horse : public IAnimal
{
public:
	void Move() override
	{
		cout << "Horse rides on the sands of the desert.\n";
	}
};

// Adapter - ���������� ��������� Adaptee � ���������� Target.
// ������� �� Camel � ITransport
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
	// ��������������
	Driver driver;
	// ����������
	Auto car;
	ITransport * transport = &car;
	// ������������ � �����������
	driver.Travel(transport);
	// ����������� �����, ���������� ������������ ��������
	IAnimal* animal = new Camel();
	// ���������� �������, ������� ����������� ������ � ���� ��� ��������� ������� � ������������� �������.
	AnimalToTransportAdapter adapter;
	adapter.SetAnimalToTransportAdapter(animal);
	transport = &adapter;
	// ���������� ���� �� ������ �������
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
	
	

