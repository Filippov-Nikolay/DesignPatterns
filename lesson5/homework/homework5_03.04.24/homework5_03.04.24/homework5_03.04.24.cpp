#include <iostream>


class GPU {
public:
    bool StartGPU() {
        std::cout << "Запуск видеокарты" << "\n";

        return true;
    }
    bool CheckingConnectionWithTheMonitor() {
        std::cout << "Проверка связи с монитором" << "\n";

        return true;
    }
    bool DisplayingDataAboutTheWinchester() {
        std::cout << "Вывод данных о винчестере" << "\n";

        return true;
    }
    bool DisplayingDataAboutTheRAM() {
        std::cout << "Вывод данных об оперативной памяти" << "\n";

        return true;
    }
    bool DisplayAFarewellMessageOnTheMonitor() {
        std::cout << "Вывести на монитор данные прощальное сообщение" << "\n";

        return true;
    }
};
class RAM {
public:
    bool StartRAM() {
        std::cout << "Запуск оперативной памяти" << "\n";

        return true;
    }
    bool MemoryAnalysis() {
        std::cout << "Анализ памяти" << "\n";

        return true;
    }


    bool MemoryClearing() {
        std::cout << "Очистка оперативной памяти" << "\n";

        return true;
    }
};
class Winchester {
public:
    bool StartWinchester() {
        std::cout << "Запуск винчестера" << "\n";

        return true;
    }
    bool BootSectorCheck() {
        std::cout << "Проверка загрузочного сектора" << "\n";

        return true;
    }


    bool StoppingTheDevice() {
        std::cout << "Остановка устройства (винчестера)" << "\n";

        return true;
    }
};
class PowerUnit {
public:
    bool ServeFood() {
        std::cout << "Подать питание" << "\n";

        return true;
    }
    bool SupplyPowerToTheGPU() {
        std::cout << "Подать питание на видеокарту" << "\n";

        return true;
    }
    bool SupplyPowerToTheRAM() {
        std::cout << "Подать питание на оперативную память" << "\n";

        return true;
    }
    bool SupplyPowerToTheWinchester() {
        std::cout << "Подать питание на винчестер" << "\n";

        return true;
    }


    bool StopPoweringTheGPU() {
        std::cout << "Прекратить питание видео карты" << "\n";

        return true;
    }
    bool StopPoweringTheRAM() {
        std::cout << "Прекратить питание оперативной памяти" << "\n";

        return true;
    }
    bool StopPoweringTheWinchester() {
        std::cout << "Прекратить питание винчестеров" << "\n";

        return true;
    }
    bool Shutdown() {
        std::cout << "Выключение блока питания" << "\n";

        return true;
    }
};

class Sensors {
public:
    bool CheckVoltage() {
        std::cout << "Проверить напряжение" << "\n";

        return true;
    }
    bool CheckTheTemperatureInThePowerUnit() {
        std::cout << "Проверить температуру в блоке питания" << "\n";

        return true;
    }
    bool CheckTheTemperatureInTheGPU() {
        std::cout << "Проверить температуру в видеокарте" << "\n";

        return true;
    }
    bool CheckTheTemperatureInTheRAM() {
        std::cout << "Проверить температуру в оперативной памяти" << "\n";

        return true;
    }
    bool CheckTheTemperatureOfAllSystems() {
        std::cout << "Проверить температуру всех систем" << "\n";

        return true;
    }
};


class PC {
    GPU* gpu;
    RAM* ram;
    Winchester* winchester;
    PowerUnit* powerUnit;
    Sensors* sensors;

public:
    void BeginWork() {
        powerUnit->ServeFood();

        sensors->CheckVoltage();
        sensors->CheckTheTemperatureInThePowerUnit();
        sensors->CheckTheTemperatureInTheGPU();

        powerUnit->SupplyPowerToTheGPU();
        
        gpu->StartGPU();
        gpu->CheckingConnectionWithTheMonitor();

        sensors->CheckTheTemperatureInTheRAM();

        powerUnit->SupplyPowerToTheRAM();

        ram->StartRAM();
        ram->MemoryAnalysis();

        gpu->DisplayingDataAboutTheRAM();
        
        powerUnit->SupplyPowerToTheWinchester();

        winchester->StartWinchester();
        winchester->BootSectorCheck();

        gpu->DisplayingDataAboutTheWinchester();

        sensors->CheckTheTemperatureOfAllSystems();
    }

    void FinishWork() {
        winchester->StoppingTheDevice();

        ram->MemoryClearing();
        ram->MemoryAnalysis();

        gpu->DisplayAFarewellMessageOnTheMonitor();

        powerUnit->StopPoweringTheGPU();
        powerUnit->StopPoweringTheRAM();
        powerUnit->StopPoweringTheWinchester();

        sensors->CheckVoltage();

        powerUnit->Shutdown();
    }
};



int main() {
    setlocale(0, "");

    PC* pc = new PC();
    
    pc->BeginWork();
    
    std::cout << "\n";
    
    pc->FinishWork();

    delete pc;

    return 0;
}

