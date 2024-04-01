#include <iostream>

class Product {
	std::string nameMechanism;
	std::string body;
	int engine;
	int wheelsR;
	std::string gearShiftBox;
public:
	void SetNameMechanism(std::string nameMechanism) { this->nameMechanism = nameMechanism; }
	std::string GetNameMechanism() { return this->nameMechanism; }

	void SetBody(std::string body) { this->body = body; }
	std::string GetBody() { return this->body; }

	void SetEngine(int engine) { this->engine = engine; }
	int GetEngine() { return this->engine; }

	void SetWheelsR(int wheelsR) { this->wheelsR = wheelsR; }
	int GetWheelsR() { return this->wheelsR; }

	void SetGearShiftBox(std::string gearShiftBox) { this->gearShiftBox = gearShiftBox; }
	std::string GetGearShiftBox() { return this->gearShiftBox; }

	void ShowProduct() {
		std::cout << "Имя механизма: " << nameMechanism << "\nКорпус: " << body << "\nДвигатель (л. с): " << engine << "\nКолёса (R): " << wheelsR << "\nК. П. П.: " << gearShiftBox << "\n\n";
	}
};


class MechanismBuilder abstract {
protected:
	Product product;
public:
	Product GetMechanism() { return product; }
	virtual void BuildNameMechanism() abstract;
	virtual void BuildBody() abstract;
	virtual void BuildEngine() abstract;
	virtual void BuildWheelsR() abstract;
	virtual void BuildGearShiftBox() abstract;
};

class DaewooLanos : public MechanismBuilder {
public:
	void BuildNameMechanism() override { product.SetNameMechanism("Daewoo Lanos"); }
	void BuildBody() override { product.SetBody("Седан"); }
	void BuildEngine() override { product.SetEngine(98); }
	void BuildWheelsR() override { product.SetWheelsR(13); }
	void BuildGearShiftBox() override { product.SetGearShiftBox("5 Manual"); }
};
class FordProbe : public MechanismBuilder {
public:
	void BuildNameMechanism() override { product.SetNameMechanism("Ford Probe"); }
	void BuildBody() override { product.SetBody("Купе"); }
	void BuildEngine() override { product.SetEngine(160); }
	void BuildWheelsR() override { product.SetWheelsR(14); }
	void BuildGearShiftBox() override { product.SetGearShiftBox("4 Auto"); }
};
class UAZPatriot : public MechanismBuilder {
public:
	void BuildNameMechanism() override { product.SetNameMechanism("UAZ Patriot"); }
	void BuildBody() override { product.SetBody("Универсал"); }
	void BuildEngine() override { product.SetEngine(120); }
	void BuildWheelsR() override { product.SetWheelsR(16); }
	void BuildGearShiftBox() override { product.SetGearShiftBox("4 Manual"); }
};
class HyundaiGetz : public MechanismBuilder {
public:
	void BuildNameMechanism() override { product.SetNameMechanism("Hyundai Getz"); }
	void BuildBody() override { product.SetBody("Хетчбэк"); }
	void BuildEngine() override { product.SetEngine(66); }
	void BuildWheelsR() override { product.SetWheelsR(13); }
	void BuildGearShiftBox() override { product.SetGearShiftBox("4 auto"); }
};


class Shop {
	MechanismBuilder* mechanismBuilder;
public:
	void SetMechanismBuilder(MechanismBuilder* cp) { mechanismBuilder = cp; }
	Product GetProduct() { return mechanismBuilder->GetMechanism(); }
	void ConstructPizza() {
		mechanismBuilder->BuildNameMechanism();
		mechanismBuilder->BuildBody();
		mechanismBuilder->BuildEngine();
		mechanismBuilder->BuildWheelsR();
		mechanismBuilder->BuildGearShiftBox();
	}
};


void client(MechanismBuilder* builder) {
	Shop shop;
	shop.SetMechanismBuilder(builder);
	shop.ConstructPizza();

	Product product = shop.GetProduct();
	product.ShowProduct();
}


int main() {
	setlocale(LC_ALL, "Russian");

	MechanismBuilder* builder = new DaewooLanos();
	client(builder);
	delete builder;


	builder = new FordProbe();
	client(builder);
	delete builder;


	builder = new UAZPatriot();
	client(builder);
	delete builder;


	builder = new HyundaiGetz();
	client(builder);
	delete builder;
	

	return 0;
}
