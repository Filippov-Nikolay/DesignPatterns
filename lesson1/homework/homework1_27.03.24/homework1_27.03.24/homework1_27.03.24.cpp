#include <iostream>
#include <string>

class Figure abstract {
protected:
    bool arr[4][4]{ 0 };
    std::string color = "";
public:
    virtual void SetFigure() = 0;
    virtual void SetColor() = 0;
    void ShowFigure() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (arr[i][j]) {
                    std::cout << "*";
                }
                else {
                    std::cout << " ";
                }
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
};

class Figure1 : public Figure {
    void SetFigure() override {
        arr[0][0] = 1; arr[0][1] = 1; arr[0][2] = 0; arr[0][3] = 0;
        arr[1][0] = 1; arr[1][1] = 1; arr[1][2] = 0; arr[1][3] = 0;
        arr[2][0] = 0; arr[2][1] = 0; arr[2][2] = 0; arr[2][3] = 0;
        arr[3][0] = 0; arr[3][1] = 0; arr[3][2] = 0; arr[3][3] = 0;
    }

    void SetColor() override {
        color = "Yellow";
    }
};

class Figure2 : public Figure {
    void SetFigure() override {
        arr[0][0] = 1; arr[0][1] = 0; arr[0][2] = 0; arr[0][3] = 0;
        arr[1][0] = 1; arr[1][1] = 0; arr[1][2] = 0; arr[1][3] = 0;
        arr[2][0] = 1; arr[2][1] = 0; arr[2][2] = 0; arr[2][3] = 0;
        arr[3][0] = 1; arr[3][1] = 0; arr[3][2] = 0; arr[3][3] = 0;
    }

    void SetColor() override {
        color = "Blue";
    }
};

class Figure3 : public Figure {
    void SetFigure() override {
        arr[0][0] = 0; arr[0][1] = 0; arr[0][2] = 0; arr[0][3] = 0;
        arr[1][0] = 0; arr[1][1] = 0; arr[1][2] = 0; arr[1][3] = 0;
        arr[2][0] = 0; arr[2][1] = 1; arr[2][2] = 1; arr[2][3] = 0;
        arr[3][0] = 1; arr[3][1] = 1; arr[3][2] = 0; arr[3][3] = 0;
    }

    void SetColor() override {
        color = "Red";
    }
};

class Figure4 : public Figure {
    void SetFigure() override {
        arr[0][0] = 0; arr[0][1] = 0; arr[0][2] = 0; arr[0][3] = 0;
        arr[1][0] = 0; arr[1][1] = 0; arr[1][2] = 0; arr[1][3] = 0;
        arr[2][0] = 1; arr[2][1] = 1; arr[2][2] = 0; arr[2][3] = 0;
        arr[3][0] = 0; arr[3][1] = 1; arr[3][2] = 1; arr[3][3] = 0;
    }

    void SetColor() override {
        color = "Green";
    }
};

class Figure5 : public Figure {
    void SetFigure() override {
        arr[0][0] = 1; arr[0][1] = 0; arr[0][2] = 0; arr[0][3] = 0;
        arr[1][0] = 1; arr[1][1] = 0; arr[1][2] = 0; arr[1][3] = 0;
        arr[2][0] = 1; arr[2][1] = 0; arr[2][2] = 0; arr[2][3] = 0;
        arr[3][0] = 1; arr[3][1] = 1; arr[3][2] = 0; arr[3][3] = 0;
    }

    void SetColor() override {
        color = "Orange";
    }
};

class Figure6 : public Figure {
    void SetFigure() override {
        arr[0][0] = 0; arr[0][1] = 1; arr[0][2] = 0; arr[0][3] = 0;
        arr[1][0] = 0; arr[1][1] = 1; arr[1][2] = 0; arr[1][3] = 0;
        arr[2][0] = 0; arr[2][1] = 1; arr[2][2] = 0; arr[2][3] = 0;
        arr[3][0] = 1; arr[3][1] = 1; arr[3][2] = 0; arr[3][3] = 0;
    }

    void SetColor() override {
        color = "Pink";
    }
};

class Figure7 : public Figure {
    void SetFigure() override {
        arr[0][0] = 0; arr[0][1] = 0; arr[0][2] = 0; arr[0][3] = 0;
        arr[1][0] = 0; arr[1][1] = 0; arr[1][2] = 0; arr[1][3] = 0;
        arr[2][0] = 1; arr[2][1] = 1; arr[2][2] = 1; arr[2][3] = 0;
        arr[3][0] = 0; arr[3][1] = 1; arr[3][2] = 0; arr[3][3] = 0;
    }

    void SetColor() override {
        color = "Purple";
    }
};

class CreateFigure abstract {
public:
    virtual Figure* FactoryMethod() = 0;
};

class CreateFigure1 : public CreateFigure {
public: 
    Figure* FactoryMethod() override {
        Figure* figure = new Figure1();
        figure->SetFigure();
        figure->SetColor();
        return figure;
    }
};

class CreateFigure2 : public CreateFigure {
public:
    Figure* FactoryMethod() override {
        Figure* figure = new Figure2();
        figure->SetFigure();
        figure->SetColor();
        return figure;
    }
};

class CreateFigure3 : public CreateFigure {
public:
    Figure* FactoryMethod() override {
        Figure* figure = new Figure3();
        figure->SetFigure();
        figure->SetColor();
        return figure;
    }
};

class CreateFigure4 : public CreateFigure {
public:
    Figure* FactoryMethod() override {
        Figure* figure = new Figure4();
        figure->SetFigure();
        figure->SetColor();
        return figure;
    }
};

class CreateFigure5 : public CreateFigure {
public:
    Figure* FactoryMethod() override {
        Figure* figure = new Figure5();
        figure->SetFigure();
        figure->SetColor();
        return figure;
    }
};

class CreateFigure6 : public CreateFigure {
public:
    Figure* FactoryMethod() override {
        Figure* figure = new Figure6();
        figure->SetFigure();
        figure->SetColor();
        return figure;
    }
};

class CreateFigure7 : public CreateFigure {
public:
    Figure* FactoryMethod() override {
        Figure* figure = new Figure7();
        figure->SetFigure();
        figure->SetColor();
        return figure;
    }
};

void Factory(CreateFigure** creators, int size) {
    for (int i = 0; i < size; i++) {
        Figure* figure = creators[i]->FactoryMethod();
        figure->ShowFigure();
    }
}

int main() {
    CreateFigure* creators[7];

    creators[0] = new CreateFigure1();
    creators[1] = new CreateFigure2();
    creators[2] = new CreateFigure3();
    creators[3] = new CreateFigure4();
    creators[4] = new CreateFigure5();
    creators[5] = new CreateFigure6();
    creators[6] = new CreateFigure7();

    Factory(creators, 7);

    return 0;
}