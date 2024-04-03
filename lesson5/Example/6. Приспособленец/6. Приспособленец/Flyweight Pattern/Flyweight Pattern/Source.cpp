#include <iostream>
#include <map>
#include <string>
using namespace std;

/*
������� ������������ ��� ���������� ������ ��� ������ � ������� ����������� ������ ��������.
������� ��������� ���� �������, ����� ��������� ��� ����������������� �������:
- � ���������� ������������ ������� ����� ��������;
- ��-�� ����� ��������� ������� �� �������� ������;
- ������� ����� ��������� �������� ����� ������� �����;
- ������ ������ �������� ����� �������� ������������ ��������� ����������� ����������� ��������, ��������� ������� ��������� ��������.
*/

// Flyweight (House) - ��������� ���������, � ������� �������� �������������� ����� �������� ������� ���������.

class House abstract
{
protected:
	int stages; // ���������� ������
public:
	virtual void Build(double longitude, double latitude) abstract;
};

/*
ConcreteFlyweight (PanelHouse) - ���������� ��������������.
��������� ��������� ������ Flyweight � ��������� ��� ������������� ���������� ���������.
������ ������ ConcreteFlyweight ������ ���� �����������.
����� ����������� �� ��������� ������ ���� ����������, �� ���� �� ��������� �� ���������.
*/
class PanelHouse: public House
{
public:
	PanelHouse()
	{
		stages = 16;
	}
	void Build(double longitude, double latitude) override
	{
		char buffer[100];
		sprintf_s(buffer, "Panel house of 16 floors; \ncoordinates: %f - latitude   %f - longitude", latitude, longitude);
		cout << buffer << endl;
	}
};

/*
ConcreteFlyweight (BrickHouse) - ���������� ��������������.
��������� ��������� ������ Flyweight � ��������� ��� ������������� ���������� ���������.
������ ������ ConcreteFlyweight ������ ���� �����������.
����� ����������� �� ��������� ������ ���� ����������, �� ���� �� ��������� �� ���������.
*/
class BrickHouse: public House
{
public:
	BrickHouse()
	{
		stages = 5;
	}
	void Build(double longitude, double latitude) override
	{
		char buffer[100];
		sprintf_s(buffer, "Brick house of 5 floors; \ncoordinates: %f - latitude   %f - longitude", latitude, longitude);
		cout << buffer << endl;
	}
};

/*
FlyweightFactory - ������� ���������������:
- ������� �������-�������������� � ��������� ���;
- ������������ ������� ���������� ���������������. ����� ������ ����������� ��������������,
������ FlyweightFactory ������������� ������������ ���������.
*/
class HouseFactory
{
	map<string, House*> houses;
public:
	HouseFactory()
	{
		houses["Panel"] = new PanelHouse();
		houses["Brick"] = new BrickHouse();
	}
	~HouseFactory()
	{
		delete houses["Panel"];
		delete houses["Brick"];
		houses.clear();
	}
	House* GetHouse(string key)
	{
		if (houses[key]!= nullptr)
			return houses[key];
		else
			return nullptr;
	}
};

int main()
{
	/*
	 Client - ������:
		- ������ ������ �� ������ ��� ���������� ���������������;
		- ��������� ��� ������ ������� ��������� ���������������.
	 */

	double longitude = 37.61;
	double latitude = 55.74;

	HouseFactory *houseFactory = new HouseFactory();

	for (int i = 0; i < 5; i++)
	{
		House *panelHouse = houseFactory->GetHouse("Panel");
		if (panelHouse != nullptr)
			panelHouse->Build(longitude, latitude);
		longitude += 0.1;
		latitude += 0.1;
	}

	for (int i = 0; i < 5; i++)
	{
		House *brickHouse = houseFactory->GetHouse("Brick");
		if (brickHouse != nullptr)
			brickHouse->Build(longitude, latitude);
		longitude += 0.1;
		latitude += 0.1;
	}

	delete houseFactory;
	system("pause");
}