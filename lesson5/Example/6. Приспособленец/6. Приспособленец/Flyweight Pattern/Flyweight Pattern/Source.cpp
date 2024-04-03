#include <iostream>
#include <map>
#include <string>
using namespace std;

/*
Паттерн используется для уменьшения затрат при работе с большим количеством мелких объектов.
Следует применять этот паттерн, когда выполнены все нижеперечисленные условия:
- в приложении используется большое число объектов;
- из-за этого накладные расходы на хранение высоки;
- большую часть состояния объектов можно вынести вовне;
- многие группы объектов можно заменить относительно небольшим количеством разделяемых объектов, поскольку внешнее состояние вынесено.
*/

// Flyweight (House) - объявляет интерфейс, с помощью которого приспособленцы могут получать внешнее состояние.

class House abstract
{
protected:
	int stages; // количество этажей
public:
	virtual void Build(double longitude, double latitude) abstract;
};

/*
ConcreteFlyweight (PanelHouse) - конкретный приспособленец.
Реализует интерфейс класса Flyweight и добавляет при необходимости внутреннее состояние.
Объект класса ConcreteFlyweight должен быть разделяемым.
Любое сохраняемое им состояние должно быть внутренним, то есть не зависящим от контекста.
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
ConcreteFlyweight (BrickHouse) - конкретный приспособленец.
Реализует интерфейс класса Flyweight и добавляет при необходимости внутреннее состояние.
Объект класса ConcreteFlyweight должен быть разделяемым.
Любое сохраняемое им состояние должно быть внутренним, то есть не зависящим от контекста.
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
FlyweightFactory - фабрика приспособленцев:
- создает объекты-приспособленцы и управляет ими;
- обеспечивает должное разделение приспособленцев. Когда клиент запрашивает приспособленца,
объект FlyweightFactory предоставляет существующий экземпляр.
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
	 Client - клиент:
		- хранит ссылки на одного или нескольких приспособленцев;
		- вычисляет или хранит внешнее состояние приспособленцев.
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