#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Processor;
class Hdd;
class RAM;
class GPU;

class IVisitor abstract
{
public:
	virtual void VisitProcessor(Processor* proc) abstract;
	virtual void VisitHdd(Hdd* hdd) abstract;
	virtual void VisitRAM(RAM* ram) abstract;
	virtual void VisitGPU(GPU* gpu) abstract;
};

class AbstractDevice abstract
{
	string Producer;
public:
	virtual void Accept(IVisitor* visitor)abstract;
	string GetProducer()
	{ 
		return Producer;
	}
	void SetProducer(string Producer)
	{
		this->Producer = Producer;
	}
};
class Processor: public AbstractDevice
{
	string Frequency;
	string CoreCount;
public:
	string GetFrequency()
	{
		return  Frequency;
	}
	void SetFrequency(string Frequency)
	{
		this->Frequency = Frequency;
	}
	string GetCoreCount()
	{
		return CoreCount;
	}
	void SetCoreCount(string CoreCount)
	{
		this->CoreCount = CoreCount;
	}
	void Accept(IVisitor* visitor) override
	{
		visitor->VisitProcessor(this);
	}
};
class Hdd: public AbstractDevice
{
	string Volume;
	string Type;
public:
	string GetVolume()
	{
		return Volume;
	}
	void SetVolume(string Volume)
	{
		this->Volume = Volume;
	}
	string GetType()
	{
		return Type;
	}
	void SetType(string Type)
	{
		this->Type = Type;
	}
	void Accept(IVisitor* visitor) override
	{
		visitor->VisitHdd(this);
	}
};
class RAM : public AbstractDevice {
	string model;
	string connectionInterface;

	int memory;
public:
	string GetModel() { return model; }
	void SetModel(string model) { this->model = model; }

	string GetConnectionInterface() { return connectionInterface; }
	void SetConnectionInterface(string connectionInterface) { this->connectionInterface = connectionInterface; }

	int GetMemory() { return memory; }
	void SetMemory(int memory) { this->memory = memory; }

	void Accept(IVisitor* visitor) override { visitor->VisitRAM(this); }
};
class GPU : public AbstractDevice {
	string model;
	string connectionInterface;

	int memory;
public:
	string GetModel() { return model; }
	void SetModel(string model) { this->model = model; }

	string GetConnectionInterface() { return connectionInterface; }
	void SetConnectionInterface(string connectionInterface) { this->connectionInterface = connectionInterface; }

	int GetMemory() { return memory; }
	void SetMemory(int memory) { this->memory = memory; }

	void Accept(IVisitor* visitor) override { visitor->VisitGPU(this); }
};

// сериализатор в HTML
class HtmlVisitor : public IVisitor
{
public:
	void VisitProcessor(Processor* proc) override
	{
		ofstream out("Processor.html", ios::binary | ios::trunc | ios::out);
		string result = "<html><head></head><body>";
		result += "<table><tr><td>Property<td><td>Value</td></tr>";
		result += "<tr><td>Producer<td><td>" + proc->GetProducer() + "</td></tr>";
		result += "<tr><td>Frequency<td><td>" + proc->GetFrequency() + "</td></tr>";
		result += "<tr><td>CoreCount<td><td>" + proc->GetCoreCount() + "</td></tr></table>";
		result += "</body></html>";
		out.write(result.c_str(), result.size());
		out.close();
	}
	void VisitHdd(Hdd* hdd) override
	{
		ofstream out("Hdd.html", ios::binary | ios::trunc | ios::out);
		string result = "<html><head></head><body>";
		result += "<table><tr><td>Property<td><td>Value</td></tr>";
		result += "<tr><td>Producer<td><td>" + hdd->GetProducer() + "</td></tr>";
		result += "<tr><td>Type<td><td>" + hdd->GetType() + "</td></tr>";
		result += "<tr><td>Volume<td><td>" + hdd->GetVolume() + "</td></tr></table>";
		result += "</body></html>";
		out.write(result.c_str(), result.size());
		out.close();
	}
	void VisitRAM(RAM* ram) override
	{
		ofstream out("RAM.html", ios::binary | ios::trunc | ios::out);
		string result = "<html><head></head><body>";
		result += "<table><tr><td>Property<td><td>Value</td></tr>";
		result += "<tr><td>Producer<td><td>" + ram->GetProducer() + "</td></tr>";
		result += "<tr><td>Model<td><td>" + ram->GetModel() + "</td></tr>";
		result += "<tr><td>Connection Interface<td><td>" + ram->GetConnectionInterface() + "</td></tr>";
		result += "<tr><td>Memory<td><td>" + to_string(ram->GetMemory()) + "</td></tr></table>";
		result += "</body></html>";
		out.write(result.c_str(), result.size());
		out.close();
	}
	void VisitGPU(GPU* gpu) override
	{
		ofstream out("GPU.html", ios::binary | ios::trunc | ios::out);
		string result = "<html><head></head><body>";
		result += "<table><tr><td>Property<td><td>Value</td></tr>";
		result += "<tr><td>Producer<td><td>" + gpu->GetProducer() + "</td></tr>";
		result += "<tr><td>Model<td><td>" + gpu->GetModel() + "</td></tr>";
		result += "<tr><td>Connection Interface<td><td>" + gpu->GetConnectionInterface() + "</td></tr>";
		result += "<tr><td>Memory<td><td>" + to_string(gpu->GetMemory()) + "</td></tr></table>";
		result += "</body></html>";
		out.write(result.c_str(), result.size());
		out.close();
	}
};
// сериализатор в XML
class XmlVisitor: public IVisitor
{
public:
	void VisitProcessor(Processor* proc) override
	{
		ofstream out("Processor.xml", ios::binary | ios::trunc | ios::out);
		string result = "<?xml version='1.0' encoding='UTF-8'?>";
		result += "<Processor><Producer>" + proc->GetProducer() + "</Producer>" +
			"<Frequency>" + proc->GetFrequency() + "</Frequency>" +
			"<CoreCount>" + proc->GetCoreCount() + "</CoreCount></Processor>";
		out.write(result.c_str(), result.size());
		out.close();
	}
	void VisitHdd(Hdd* hdd) override
	{
		ofstream out("Hdd.xml", ios::binary | ios::trunc | ios::out);
		string result = "<?xml version='1.0' encoding='UTF-8'?>";
		result += "<HDD><Producer>" + hdd->GetProducer() + "</Producer>" +
			"<Type>" + hdd->GetType() + "</Type>" +
			"<Volume>" + hdd->GetVolume() + "</Volume></HDD>";
		out.write(result.c_str(), result.size());
		out.close();
	}
	void VisitRAM(RAM* ram) override
	{
		ofstream out("RAM.xml", ios::binary | ios::trunc | ios::out);
		string result = "<?xml version='1.0' encoding='UTF-8'?>";
		result += "<RAM><Producer>" + ram->GetProducer() + "</Producer>"
		 + "<Model>" + ram->GetModel() + "</Model>" +
		 + "<ConnectionInterface>" + ram->GetConnectionInterface() + "</ConnectionInterface>"
		 + "<Memory>" + to_string(ram->GetMemory()) + "</Memory></RAM>";
		out.write(result.c_str(), result.size());
		out.close();
	}
	void VisitGPU(GPU* gpu) override
	{
		ofstream out("GPU.xml", ios::binary | ios::trunc | ios::out);
		string result = "<?xml version='1.0' encoding='UTF-8'?>";
		result += "<GPU><Producer>" + gpu->GetProducer() + "</Producer>"
		+ "<Model>" + gpu->GetModel() + "</Model>" +
		+ "<ConnectionInterface>" + gpu->GetConnectionInterface() + "</ConnectionInterface>"
		+ "<Memory>" + to_string(gpu->GetMemory()) + "</Memory></GPU>";
		out.write(result.c_str(), result.size());
		out.close();
	}
};
// сериализатор в TXT
class TextVisitor : public IVisitor
{
public:
	void VisitProcessor(Processor* proc) override
	{
		ofstream out("Processor.txt", ios::binary | ios::trunc | ios::out);
		string result;
		result += "Producer: " + proc->GetProducer() + "\n";
		result += "Frequency: " + proc->GetFrequency() + "\n";
		result += "Core count: " + proc->GetCoreCount() + "\n";
		out.write(result.c_str(), result.size());
		out.close();
	}
	void VisitHdd(Hdd* hdd) override
	{
		ofstream out("Hdd.txt", ios::binary | ios::trunc | ios::out);
		string result;
		result += "Producer: " + hdd->GetProducer() + "\n";
		result += "Type: " + hdd->GetType() + "\n";
		result += "Volume: " + hdd->GetVolume() + "\n";
		out.write(result.c_str(), result.size());
		out.close();
	}
	void VisitRAM(RAM* ram) override
	{
		ofstream out("RAM.txt", ios::binary | ios::trunc | ios::out);
		string result;
		result += "Producer: " + ram->GetProducer() + "\n";
		result += "Model: " + ram->GetModel() + "\n";
		result += "Connection Interface: " + ram->GetConnectionInterface() + "\n";
		result += "Memory: " + to_string(ram->GetMemory()) + "\n";
		out.write(result.c_str(), result.size());
		out.close();
	}
	void VisitGPU(GPU* gpu) override
	{
		ofstream out("GPU.txt", ios::binary | ios::trunc | ios::out);
		string result;
		result += "Producer: " + gpu->GetProducer() + "\n";
		result += "Model: " + gpu->GetModel() + "\n";
		result += "Connection Interface: " + gpu->GetConnectionInterface() + "\n";
		result += "Memory: " + to_string(gpu->GetMemory()) + "\n";
		out.write(result.c_str(), result.size());
		out.close();
	}
};
// сериализатор в консоль
class ConsoleVisitor : public IVisitor
{
public:
	void VisitProcessor(Processor* proc) override
	{
		cout << "Producer: " << proc->GetProducer() << "\n";
		cout << "Frequency: " << proc->GetFrequency() << "\n";
		cout << "CoreCount: " << proc->GetCoreCount() << "\n";
	}
	void VisitHdd(Hdd* hdd) override
	{
		cout << "Producer: " << hdd->GetProducer() << "\n";
		cout << "Type: " << hdd->GetType() << "\n";
		cout << "CoreCount: " << hdd->GetVolume() << "\n";
	}
	void VisitRAM(RAM* ram) override
	{
		cout << "Producer: " << ram->GetProducer() << "\n";
		cout << "Model: " << ram->GetModel() << "\n";
		cout << "Connection Interface: " + ram->GetConnectionInterface() << "\n";
		cout << "Memory: " + to_string(ram->GetMemory()) << "\n";
	}
	void VisitGPU(GPU* gpu) override
	{
		cout << "Producer: " << gpu->GetProducer() << "\n";
		cout << "Model: " << gpu->GetModel() << "\n";
		cout << "Connection Interface: " + gpu->GetConnectionInterface() << "\n";
		cout << "Memory: " + to_string(gpu->GetMemory()) << "\n";
	}
};

class PC
{
	vector<AbstractDevice*> devices;
public:
	void Add(AbstractDevice* d)
	{
		devices.push_back(d);
	}
	void Remove(AbstractDevice* d)
	{
		auto iter = find(devices.begin(), devices.end(), d);
		if(iter != devices.end())
			devices.erase(iter);
	}
	void Accept(IVisitor* visitor)
	{
		for(AbstractDevice* d : devices)
			d->Accept(visitor);
	}
};

int main()
{
	PC* pc = new PC();

	Processor *p = new Processor;
	p->SetProducer("Intel");
	p->SetFrequency("3.5");
	p->SetCoreCount("4");
	pc->Add(p);

	Hdd *hdd = new Hdd;
	hdd->SetProducer("Western Digital");
	hdd->SetType("SATA III");
	hdd->SetVolume("2");
	pc->Add(hdd);
	
	HtmlVisitor *html = new HtmlVisitor;
	pc->Accept(html);
	
	XmlVisitor *xml = new XmlVisitor;
	pc->Accept(xml);
	
	

	RAM* ram = new RAM;
	ram->SetProducer("Kingston");
	ram->SetModel("FURY Beast");
	ram->SetConnectionInterface("DDR4");
	ram->SetMemory(16);
	pc->Add(ram);

	GPU* gpu = new GPU;
	gpu->SetProducer("Asus");
	gpu->SetModel("Dual OC V2 LHR");
	gpu->SetConnectionInterface("PCI-Express x16 4.0");
	gpu->SetMemory(12);
	pc->Add(gpu);

	TextVisitor* textVisitor = new TextVisitor;
	pc->Accept(textVisitor);

	ConsoleVisitor* consoleVisitor = new ConsoleVisitor;
	pc->Accept(consoleVisitor);


	delete html;
	delete xml;
	delete hdd;
	delete gpu;
	delete ram;
	delete consoleVisitor;
	delete textVisitor;
	delete p;
	delete pc;

	system("pause");
}
