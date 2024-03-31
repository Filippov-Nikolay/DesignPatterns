#include <iostream>
#include <string>
using namespace std;

/*
Абстрактная фабрика - порождающий паттерн проектирования,
который предоставляет интерфейс для создания семейств взаимосвязанных или взаимозависимых объектов,
не специфицируя их конкретных классов.

Применимость
- система не должна зависеть от того, как создаются, компонуются и представляются входящие в нее объекты;
- входящие в семейство взаимосвязанные объекты должны использоваться вместе и необходимо обеспечить выполнение этого ограничения;
- система должна конфигурироваться одним из семейств составляющих ее объектов;
- необходимо предоставить библиотеку объектов, раскрывая только их интерфейсы, но не реализацию.

Паттерн абстрактная фабрика обладает следующими плюсами и минусами:
 * изолирует конкретные классы.
 * упрощает замену семейств продуктов.
 * гарантирует сочетаемость продуктов.
 * поддержать новый вид продуктов трудно.
*/

// AbstractProductA(Box) - объявляет интерфейс(абстрактный класс) для типа объекта-продукта
class Box abstract
{
public:
	virtual string GetName() abstract;
};

// AbstractProductB(Hdd) - объявляет интерфейс(абстрактный класс) для типа объекта-продукта
class Hdd abstract
{
public:
	virtual string GetName() abstract;
};

// AbstractProductC(MainBoard) - объявляет интерфейс(абстрактный класс) для типа объекта-продукта
class MainBoard abstract
{
public:
	virtual string GetName() abstract;
};

// AbstractProductD(Processor) - объявляет интерфейс(абстрактный класс) для типа объекта-продукта
class Processor abstract
{
public:
	virtual string GetName() abstract;
};

// AbstractProductE(Memory) - объявляет интерфейс(абстрактный класс) для типа объекта-продукта
class Memory abstract
{
public:
	virtual string GetName() abstract;
};

// ConcreteProductA1(SilverBox)  - определяет объект-продукт, создаваемый соответствующей конкретной фабрикой, 
// а также реализует интерфейс Abstract Product
class SilverBox : public Box
{
public:
	string GetName() override
	{
		return "SilverBox";
	}
};

// ConcreteProductB1(SamsungHDD)  - определяет объект-продукт, создаваемый соответствующей конкретной фабрикой, 
// а также реализует интерфейс Abstract Product
class SamsungHDD: public Hdd
{
public:
	string GetName() override
	{
		return "Samsung hdd";
	}
};

// ConcreteProductC1(MSIMainBord)  - определяет объект-продукт, создаваемый соответствующей конкретной фабрикой, 
// а также реализует интерфейс Abstract Product
class MSIMainBord: public MainBoard
{
public:
	string GetName() override
	{
		return "MSIMainBord";
	}
};

// ConcreteProductD1(IntelProcessor)  - определяет объект-продукт, создаваемый соответствующей конкретной фабрикой, 
// а также реализует интерфейс Abstract Product
class IntelProcessor: public Processor
{
public:
	string GetName() override
	{
		return "IntelProcessor";
	}
};

// ConcreteProductE1(Ddr3Memory)  - определяет объект-продукт, создаваемый соответствующей конкретной фабрикой, 
// а также реализует интерфейс Abstract Product
class Ddr3Memory: public Memory
{
public:
	string GetName() override
	{
		return "Ddr3Memory";
	}
};

// ConcreteProductA2(BlackBox)  - определяет объект-продукт, создаваемый соответствующей конкретной фабрикой, 
// а также реализует интерфейс Abstract Product
class BlackBox : public Box
{
public:
	string GetName() override
	{
		return "BlackBox";
	}
};

// ConcreteProductB2(LGHDD)  - определяет объект-продукт, создаваемый соответствующей конкретной фабрикой, 
// а также реализует интерфейс Abstract Product
class LGHDD: public Hdd
{
public:
	string GetName() override
	{
		return "LG hdd";
	}
};

// ConcreteProductC2(AsusMainBord)  - определяет объект-продукт, создаваемый соответствующей конкретной фабрикой, 
// а также реализует интерфейс Abstract Product
class AsusMainBord: public MainBoard
{
public:
	string GetName() override
	{
		return "AsusMainBord";
	}
};

// ConcreteProductD2(AmdProcessor)  - определяет объект-продукт, создаваемый соответствующей конкретной фабрикой, 
// а также реализует интерфейс Abstract Product
class AmdProcessor: public Processor
{
public:
	string GetName() override
	{
		return "AmdProcessor";
	}
};

// ConcreteProductE2(Ddr2Memory)  - определяет объект-продукт, создаваемый соответствующей конкретной фабрикой, 
// а также реализует интерфейс Abstract Product
class Ddr2Memory: public Memory
{
public:
	string GetName() override
	{
		return "Ddr2Memory";
	}
};

/*
* Класс персонального компьютера
*/

class Pc
{
	Box *box;
	Processor *processor;
	MainBoard *mainboard;
	Hdd *hdd;
	Memory *memory;
	
public:
	Box* GetBox()
	{
		return box;
	}
	void SetBox(Box* box)
	{
		this->box = box;
	}
	Processor* GetProcessor()
	{
		return processor;
	}
	void SetProcessor(Processor* processor)
	{
		this->processor = processor;
	}
	MainBoard* GetMainBoard()
	{
		return mainboard;
	}
	void SetMainBoard(MainBoard* mainboard)
	{
		this->mainboard = mainboard;
	}
	Hdd* GetHdd()
	{
		return hdd;
	}
	void SetHdd(Hdd* hdd)
	{
		this->hdd = hdd;
	}
	Memory* GetMemory()
	{
		return memory;
	}
	void SetMemory(Memory* memory)
	{
		this->memory = memory;
	}
};

/* AbstractFactory(IPcFactory) - объявляет интерфейс для операций, создающих абстрактные объекты-продукты
	 * Интерфейс фабрики для создания конфигурации системного блока персонального компьютера
	 */
class IPcFactory abstract
{
public:
	virtual Box* CreateBox() abstract;
	virtual Processor* CreateProcessor() abstract;
	virtual MainBoard* CreateMainBoard() abstract;
	virtual Hdd* CreateHdd() abstract;
	virtual Memory* CreateMemory() abstract;
};

/* ConcreteFactory1(HomePcFactory) - реализует операции, создающие конкретные объекты-продукты
 * Фабрика для создания "домашней" конфигурации системного блока персонального компьютера
 */
class HomePcFactory : public IPcFactory 
{
public:
	Box* CreateBox() override
	{
		return new SilverBox();
	}
	Processor* CreateProcessor() override
	{
		return new IntelProcessor();
	}
	MainBoard* CreateMainBoard() override
	{
		return new MSIMainBord();
	}
	Hdd* CreateHdd() override
	{
		return new SamsungHDD();
	}
	Memory* CreateMemory() override
	{
		return new Ddr3Memory();
	}
};

/* ConcreteFactory2(OfficePcFactory) - реализует операции, создающие конкретные объекты-продукты
 * Фабрика для создания "офисной" конфигурации системного блока персонального компьютера
 */
class OfficePcFactory: public IPcFactory 
{
public:
	Box* CreateBox() override
	{
		return new BlackBox();
	}
	Processor* CreateProcessor() override
	{
		return new AmdProcessor();
	}
	MainBoard* CreateMainBoard() override
	{
		return new AsusMainBord();
	}
	Hdd* CreateHdd() override
	{
		return new LGHDD();
	}
	Memory* CreateMemory() override
	{
		return new Ddr2Memory();
	}
};

/*
Класс, производящий конфигурирование системного блока персонального компьютера.
*/
class PcConfigurator
{
	/*
	 *  Фабрика составляющих персонального компьютера
	 */
	IPcFactory* PcFactory;
public:
	IPcFactory* GetFactory()
	{
		return PcFactory;
	}
	void SetFactory(IPcFactory* pFactory)
	{
		PcFactory = pFactory;
	}
	void Configure(Pc &pc) // Метод конфигурирования системного блока
	{
		pc.SetBox(PcFactory->CreateBox());
		pc.SetMainBoard(PcFactory->CreateMainBoard());
		pc.SetHdd(PcFactory->CreateHdd());
		pc.SetMemory(PcFactory->CreateMemory());
		pc.SetProcessor(PcFactory->CreateProcessor());
	}
};

void PrintPcConfiguration(string configName, IPcFactory* PcFactory)
{
	Pc pc;
	PcConfigurator configurator;
	configurator.SetFactory(PcFactory);
	configurator.Configure(pc);
	cout << "======== " + configName + " ========" << endl;
	cout << "Box: " + pc.GetBox()->GetName() << endl;
	cout << "MainBoard: " + pc.GetMainBoard()->GetName() << endl;
	cout << "Processor: " + pc.GetProcessor()->GetName() << endl;
	cout << "HDD: " + pc.GetHdd()->GetName() << endl;
	cout << "Memory: " + pc.GetMemory()->GetName() << endl;
}

void main()
{		
	IPcFactory* PcFactory = new HomePcFactory();
	PrintPcConfiguration("Home configuration", PcFactory);
	delete PcFactory;
	PcFactory = new OfficePcFactory();
	PrintPcConfiguration("Office configuration", PcFactory);
	delete PcFactory;

	system("pause");
}
