#include <iostream>

class Hero abstract {
protected:
	std::string name;
	int attack = 0;
	int speed = 0;
	int health = 0;
	int protection = 0;

public:
	Hero(std::string name) { this->name = name; }
	std::string GetName() { return name; }

	virtual int GetAttack() abstract;
	virtual int GetSpeed() abstract;
	virtual int GetHealth() abstract;
	virtual int GetProtection() abstract;
};


class Human : public Hero {
public:
	Human() : Hero("Human") { }

	int GetAttack() override { return 20; }
	int GetSpeed() override { return 20; }
	int GetHealth() override { return 150; }
	int GetProtection() override { return 0; }
};
class Elf : public Hero {
public:
	Elf() : Hero("Elf") { }

	int GetAttack() override { return 15; }
	int GetSpeed() override { return 30; }
	int GetHealth() override { return 100; }
	int GetProtection() override { return 0; }
};


// =================
// HumanDecorator
class HumanDecorator abstract : public Hero {
protected:
	Hero* hero;
public:
	HumanDecorator(std::string name, Hero* hero) : Hero(name) { this->hero = hero; }
};

// Человек воин
class HumanWarrior : public HumanDecorator {
public:
	HumanWarrior(Hero* hero) : HumanDecorator(hero->GetName() + " warrior", hero) { }

	int GetAttack() override { return hero->GetAttack() + 20; }
	int GetSpeed() override { return hero->GetSpeed() + 10; }
	int GetHealth() override { return hero->GetHealth() + 50; }
	int GetProtection() override { return hero->GetProtection() + 20; }
};

// Меченосец
class SwordBearer : public HumanDecorator {
public:
	SwordBearer(Hero* hero) : HumanDecorator(hero->GetName() + " sword bearer", hero) { }

	int GetAttack() override { return hero->GetAttack() + 40; }
	int GetSpeed() override { return hero->GetSpeed() - 10; }
	int GetHealth() override { return hero->GetHealth() + 50; }
	int GetProtection() override { return hero->GetProtection() + 40; }
};

// Лучник
class Archer : public HumanDecorator {
public:
	Archer(Hero* hero) : HumanDecorator(hero->GetName() + " archer", hero) { }

	int GetAttack() override { return hero->GetAttack() + 20; }
	int GetSpeed() override { return hero->GetSpeed() + 20; }
	int GetHealth() override { return hero->GetHealth() + 50; }
	int GetProtection() override { return hero->GetProtection() + 10; }
};

// Всадник
class Rider : public HumanDecorator {
public:
	Rider(Hero* hero) : HumanDecorator(hero->GetName() + " rider", hero) { }

	int GetAttack() override { return hero->GetAttack() - 10; }
	int GetSpeed() override { return hero->GetSpeed() + 40; }
	int GetHealth() override { return hero->GetHealth() + 200; }
	int GetProtection() override { return hero->GetProtection() + 100; }
};
// =================


// =================
// ElfDecorator
class ElfDecorator abstract : public Hero {
protected:
	Hero* hero;
public:
	ElfDecorator(std::string name, Hero* hero) : Hero(name) { this->hero = hero; }
};

// Эльф воин
class ElfWarrior : public ElfDecorator {
public:
	ElfWarrior(Hero* hero) : ElfDecorator(hero->GetName() + " warrior", hero) { }

	int GetAttack() override { return hero->GetAttack() + 20; }
	int GetSpeed() override { return hero->GetSpeed() - 10; }
	int GetHealth() override { return hero->GetHealth() + 100; }
	int GetProtection() override { return hero->GetProtection() + 20; }
};

// Эльф маг
class ElfMage : public ElfDecorator {
public:
	ElfMage(Hero* hero) : ElfDecorator(hero->GetName() + " mage", hero) { }

	int GetAttack() override { return hero->GetAttack() + 10; }
	int GetSpeed() override { return hero->GetSpeed() + 10; }
	int GetHealth() override { return hero->GetHealth() - 50; }
	int GetProtection() override { return hero->GetProtection() + 10; }
};

// Арбалетчик
class Crossbowman : public ElfDecorator {
public:
	Crossbowman(Hero* hero) : ElfDecorator(hero->GetName() + " crossbowman", hero) { }

	int GetAttack() override { return hero->GetAttack() + 20; }
	int GetSpeed() override { return hero->GetSpeed() + 10; }
	int GetHealth() override { return hero->GetHealth() + 50; }
	int GetProtection() override { return hero->GetProtection() - 10; }
};

// Злой маг 
class EvilMagician : public ElfDecorator {
public:
	EvilMagician(Hero* hero) : ElfDecorator(hero->GetName() + " evil magician", hero) { }

	int GetAttack() override { return hero->GetAttack() + 70; }
	int GetSpeed() override { return hero->GetSpeed() + 20; }
	int GetHealth() override { return hero->GetHealth() + 0; }
	int GetProtection() override { return hero->GetProtection() + 0; }
};

// Добрый маг 
class GoodMagician : public ElfDecorator {
public:
	GoodMagician(Hero* hero) : ElfDecorator(hero->GetName() + " good magician", hero) { }

	int GetAttack() override { return hero->GetAttack() + 50; }
	int GetSpeed() override { return hero->GetSpeed() + 30; }
	int GetHealth() override { return hero->GetHealth() + 100; }
	int GetProtection() override { return hero->GetProtection() + 30; }
};
// =================



void client(Hero* hero) {
	printf("Name: %s\nAttack: %d\nSpeed: %d\nHealth: %d\nProtection: %d", hero->GetName().c_str(), hero->GetAttack(), hero->GetSpeed(), hero->GetHealth(), hero->GetProtection());
}


int main() {
	Hero* hero = new Human();
	hero = new HumanWarrior(hero);
	client(hero);

	hero = new SwordBearer(hero);
	client(hero);

	hero = new Archer(hero);
	client(hero);

	hero = new Rider(hero);
	client(hero);

	delete hero;

	hero = new Elf();

    return 0;
}