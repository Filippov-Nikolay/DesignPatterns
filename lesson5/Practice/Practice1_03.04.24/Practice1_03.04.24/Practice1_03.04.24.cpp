#include <iostream>
#include <map>

class Sprite {
public:
    std::string img = "image.png";

    int x = 0;
    int y = 0;
};

class CombatUnits abstract {
protected:
    int speed = 0;
    int strength = 0;

    Sprite* sprite;
public:
    virtual void Show(Sprite* sprite) abstract;
};

class LightInfantry : public CombatUnits {
public:
    LightInfantry() {
        speed = 20;
        strength = 10;
    }
    void Show(Sprite* sprite) override {
        this->sprite = sprite;

        printf("Speed: %d, Strength: %d\nImage: %s, X: %d, Y: %d\n\n", speed, strength, this->sprite->img.c_str(), this->sprite->x, this->sprite->y);
    }
};
class TransportVehicles : public CombatUnits {
public:
    TransportVehicles() {
        speed = 70;
        strength = 0;
    }
    void Show(Sprite* sprite) override {
        this->sprite = sprite;

        printf("Speed: %d, Strength: %d\nImage: %s, X: %d, Y: %d\n\n", speed, strength, this->sprite->img.c_str(), this->sprite->x, this->sprite->y);
    }
};
class HeavyGroundCombatEquipment : public CombatUnits {
public:
    HeavyGroundCombatEquipment() {
        speed = 15;
        strength = 150;
    }
    void Show(Sprite* sprite) override {
        this->sprite = sprite;

        printf("Speed: %d, Strength: %d\nImage: %s, X: %d, Y: %d\n\n", speed, strength, this->sprite->img.c_str(), this->sprite->x, this->sprite->y);
    }
};
class LightGroundCombatVehicles : public CombatUnits {
public:
    LightGroundCombatVehicles() {
        speed = 50;
        strength = 30;
    }
    void Show(Sprite* sprite) override {
        this->sprite = sprite;

        printf("Speed: %d, Strength: %d\nImage: %s, X: %d, Y: %d\n\n", speed, strength, this->sprite->img.c_str(), this->sprite->x, this->sprite->y);
    }
};
class Aircraft : public CombatUnits {
public:
    Aircraft() {
        speed = 300;
        strength = 100;
    }
    void Show(Sprite* sprite) override {
        this->sprite = sprite;

        printf("Speed: %d, Strength: %d\nImage: %s, X: %d, Y: %d\n\n", speed, strength, this->sprite->img.c_str(), this->sprite->x, this->sprite->y);
    }
};

class CombatUnitsFactory {
private:
    std::map<std::string, CombatUnits*> characters;
public:
    CombatUnits* GetCharacter(std::string key) {
        CombatUnits* combatUnits = characters[key];

        if (combatUnits == nullptr) {
            if (key == "LightInfantry") {
                combatUnits = new LightInfantry();
            }
            else if (key == "TransportVehicles") {
                combatUnits = new TransportVehicles();
            }
            else if (key == "HeavyGroundCombatEquipment") {
                combatUnits = new HeavyGroundCombatEquipment();
            }
            else if (key == "LightGroundCombatVehicles") {
                combatUnits = new LightGroundCombatVehicles();
            }
            else if (key ==  "Aircraft") {
                combatUnits = new Aircraft();
            }

            characters[key] = combatUnits;
        }

        return combatUnits;
    }
};

int main() {
    Sprite sprite;
    sprite.x = 10;
    sprite.y = 7;

    std::string combatUnitsName[5]{
        "LightInfantry", "TransportVehicles", "HeavyGroundCombatEquipment",
        "LightGroundCombatVehicles", "Aircraft"
    };
    CombatUnitsFactory* pCUF = new CombatUnitsFactory();

    for (int i = 0; i < 5; i++) {
        sprite.x++;
        sprite.y++;

        CombatUnits* combatUnits = pCUF->GetCharacter(combatUnitsName[i]);
        combatUnits->Show(&sprite);
    }

    return 0;
}
