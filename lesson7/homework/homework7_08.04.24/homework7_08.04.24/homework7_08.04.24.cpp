#include <iostream>

class TransportStrategy abstract {
public:
    virtual void Transport() abstract;
};


class Bike : public TransportStrategy {
    void Transport() override {
        std::cout << "Transport: " << "Bike\n";
        std::cout << "Price: " << "0$\n";
        std::cout << "Time: " << "6h\n";
    }
};
class Bus : public TransportStrategy {
    void Transport() override {
        std::cout << "Transport: " << "Bus\n";
        std::cout << "Price: " << "5$\n";
        std::cout << "Time: " << "4h\n";
    }
};
class Taxi : public TransportStrategy {
    void Transport() override {
        std::cout << "Transport: " << "Taxi\n";
        std::cout << "Price: " << "15$\n";
        std::cout << "Time: " << "2h\n";
    }
};


class ChoiceOfTransport {
    TransportStrategy* transportStrategy;
public:
    void SetTransportStrategy(TransportStrategy* transportStrategy) {
        this->transportStrategy = transportStrategy;
    }
    void Print() {
        transportStrategy->Transport();
    }
};

int main() {
    ChoiceOfTransport choiceOfTransport;
    Bike bike;
    choiceOfTransport.SetTransportStrategy(&bike);
    choiceOfTransport.Print();
    std::cout << "\n";


    Bus bus;
    choiceOfTransport.SetTransportStrategy(&bus);
    choiceOfTransport.Print();
    std::cout << "\n";


    Taxi taxi;
    choiceOfTransport.SetTransportStrategy(&taxi);
    choiceOfTransport.Print();
    std::cout << "\n";


    return 0;
}
