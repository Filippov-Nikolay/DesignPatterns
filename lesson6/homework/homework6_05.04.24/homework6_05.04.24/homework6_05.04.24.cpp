#include <iostream>

class Devices abstract {
protected:
    std::string name;
    std::string connector;
    
    int memory;
    int price;
    int energyConsumption;

public:
    virtual void Print() abstract;
    virtual void SetName() abstract;
    virtual void SetConnector() abstract;
    virtual void SetMemory() abstract;
    virtual void SetPrice() abstract;
    virtual void SetEnergyConsumption() abstract;
};

class GPU : public Devices {
    void Print() override {
        std::cout << name << "\n";
        std::cout << connector << "\n";
        std::cout << memory << "\n";
        std::cout << price << "\n";
        std::cout << energyConsumption << "\n";
    }
    void SetName() override {
        name = "Gigabyte PCI-Ex GeForce RTX 4060";
    }
    void SetConnector() override {
        connector = "PCI-Express 4.0 x8";
    }
    void SetMemory() override {
        memory = 8;
    }
    void SetPrice() override {
        price = 14099;
    }
    void SetEnergyConsumption() override {
        energyConsumption = 450;
    }
};
class CPU : public Devices {
    void Print() override {
        std::cout << name << "\n";
        std::cout << connector << "\n";
        std::cout << memory << "\n";
        std::cout << price << "\n";
        std::cout << energyConsumption << "\n";
    }
    void SetName() override {
        name = "Intel Core i9";
    }
    void SetConnector() override {
        connector = "Socket 2066";
    }
    void SetMemory() override {
        memory = 24;
    }
    void SetPrice() override {
        price = 749;
    }
    void SetEnergyConsumption() override {
        energyConsumption = 165;
    }
};
class HDD : public Devices {
    void Print() override {
        std::cout << name << "\n";
        std::cout << connector << "\n";
        std::cout << memory << "\n";
        std::cout << price << "\n";
        std::cout << energyConsumption << "\n";
    }
    void SetName() override {
        name = "Seagate BarraCuda";
    }
    void SetConnector() override {
        connector = "SATA III";
    }
    void SetMemory() override {
        memory = 2;
    }
    void SetPrice() override {
        price = 2429;
    }
    void SetEnergyConsumption() override {
        energyConsumption = 4;
    }
};


class IPrint {
    Devices* devices;

public:
    void SetDevices(Devices* devices) {
        this->devices = devices;

        devices->SetConnector();
        devices->SetEnergyConsumption();
        devices->SetMemory();
        devices->SetName();
        devices->SetPrice();
    }
    
    void PrintInfo() {
        devices->Print();
    }
};


void Client(Devices* devices, IPrint* IPrintDevices) {
    IPrintDevices->SetDevices(devices);
    devices->Print();
}


int main() {
    Devices* devices = new GPU();
    IPrint* IPrintDevices = new IPrint();
    Client(devices, IPrintDevices);
    std::cout << "\n";
    delete devices;
    delete IPrintDevices;


    devices = new CPU();
    IPrintDevices = new IPrint();
    Client(devices, IPrintDevices);
    std::cout << "\n";
    delete devices;
    delete IPrintDevices;


    devices = new HDD();
    IPrintDevices = new IPrint();
    Client(devices, IPrintDevices);
    std::cout << "\n";
    delete devices;
    delete IPrintDevices;


    return 0;
}
