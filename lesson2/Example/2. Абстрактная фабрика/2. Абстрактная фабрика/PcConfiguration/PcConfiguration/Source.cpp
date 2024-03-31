#include <iostream>
#include <string>
using namespace std;

/*
����������� ������� - ����������� ������� ��������������,
������� ������������� ��������� ��� �������� �������� ��������������� ��� ��������������� ��������,
�� ������������ �� ���������� �������.

������������
- ������� �� ������ �������� �� ����, ��� ���������, ����������� � �������������� �������� � ��� �������;
- �������� � ��������� ��������������� ������� ������ �������������� ������ � ���������� ���������� ���������� ����� �����������;
- ������� ������ ����������������� ����� �� �������� ������������ �� ��������;
- ���������� ������������ ���������� ��������, ��������� ������ �� ����������, �� �� ����������.

������� ����������� ������� �������� ���������� ������� � ��������:
 * ��������� ���������� ������.
 * �������� ������ �������� ���������.
 * ����������� ������������ ���������.
 * ���������� ����� ��� ��������� ������.
*/

// AbstractProductA(Box) - ��������� ���������(����������� �����) ��� ���� �������-��������
class Box abstract
{
public:
	virtual string GetName() abstract;
};

// AbstractProductB(Hdd) - ��������� ���������(����������� �����) ��� ���� �������-��������
class Hdd abstract
{
public:
	virtual string GetName() abstract;
};

// AbstractProductC(MainBoard) - ��������� ���������(����������� �����) ��� ���� �������-��������
class MainBoard abstract
{
public:
	virtual string GetName() abstract;
};

// AbstractProductD(Processor) - ��������� ���������(����������� �����) ��� ���� �������-��������
class Processor abstract
{
public:
	virtual string GetName() abstract;
};

// AbstractProductE(Memory) - ��������� ���������(����������� �����) ��� ���� �������-��������
class Memory abstract
{
public:
	virtual string GetName() abstract;
};

// ConcreteProductA1(SilverBox)  - ���������� ������-�������, ����������� ��������������� ���������� ��������, 
// � ����� ��������� ��������� Abstract Product
class SilverBox : public Box
{
public:
	string GetName() override
	{
		return "SilverBox";
	}
};

// ConcreteProductB1(SamsungHDD)  - ���������� ������-�������, ����������� ��������������� ���������� ��������, 
// � ����� ��������� ��������� Abstract Product
class SamsungHDD: public Hdd
{
public:
	string GetName() override
	{
		return "Samsung hdd";
	}
};

// ConcreteProductC1(MSIMainBord)  - ���������� ������-�������, ����������� ��������������� ���������� ��������, 
// � ����� ��������� ��������� Abstract Product
class MSIMainBord: public MainBoard
{
public:
	string GetName() override
	{
		return "MSIMainBord";
	}
};

// ConcreteProductD1(IntelProcessor)  - ���������� ������-�������, ����������� ��������������� ���������� ��������, 
// � ����� ��������� ��������� Abstract Product
class IntelProcessor: public Processor
{
public:
	string GetName() override
	{
		return "IntelProcessor";
	}
};

// ConcreteProductE1(Ddr3Memory)  - ���������� ������-�������, ����������� ��������������� ���������� ��������, 
// � ����� ��������� ��������� Abstract Product
class Ddr3Memory: public Memory
{
public:
	string GetName() override
	{
		return "Ddr3Memory";
	}
};

// ConcreteProductA2(BlackBox)  - ���������� ������-�������, ����������� ��������������� ���������� ��������, 
// � ����� ��������� ��������� Abstract Product
class BlackBox : public Box
{
public:
	string GetName() override
	{
		return "BlackBox";
	}
};

// ConcreteProductB2(LGHDD)  - ���������� ������-�������, ����������� ��������������� ���������� ��������, 
// � ����� ��������� ��������� Abstract Product
class LGHDD: public Hdd
{
public:
	string GetName() override
	{
		return "LG hdd";
	}
};

// ConcreteProductC2(AsusMainBord)  - ���������� ������-�������, ����������� ��������������� ���������� ��������, 
// � ����� ��������� ��������� Abstract Product
class AsusMainBord: public MainBoard
{
public:
	string GetName() override
	{
		return "AsusMainBord";
	}
};

// ConcreteProductD2(AmdProcessor)  - ���������� ������-�������, ����������� ��������������� ���������� ��������, 
// � ����� ��������� ��������� Abstract Product
class AmdProcessor: public Processor
{
public:
	string GetName() override
	{
		return "AmdProcessor";
	}
};

// ConcreteProductE2(Ddr2Memory)  - ���������� ������-�������, ����������� ��������������� ���������� ��������, 
// � ����� ��������� ��������� Abstract Product
class Ddr2Memory: public Memory
{
public:
	string GetName() override
	{
		return "Ddr2Memory";
	}
};

/*
* ����� ������������� ����������
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

/* AbstractFactory(IPcFactory) - ��������� ��������� ��� ��������, ��������� ����������� �������-��������
	 * ��������� ������� ��� �������� ������������ ���������� ����� ������������� ����������
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

/* ConcreteFactory1(HomePcFactory) - ��������� ��������, ��������� ���������� �������-��������
 * ������� ��� �������� "��������" ������������ ���������� ����� ������������� ����������
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

/* ConcreteFactory2(OfficePcFactory) - ��������� ��������, ��������� ���������� �������-��������
 * ������� ��� �������� "�������" ������������ ���������� ����� ������������� ����������
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
�����, ������������ ���������������� ���������� ����� ������������� ����������.
*/
class PcConfigurator
{
	/*
	 *  ������� ������������ ������������� ����������
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
	void Configure(Pc &pc) // ����� ���������������� ���������� �����
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
