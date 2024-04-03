#include <iostream>
#include <map>
#include <string>
using namespace std;

/*
Паттерн используется для уменьшения затрат при работе с большим количеством мелких объектов.
Следует применять этот паттерн, когда выполнены все нижеперечисленные условия:
- в приложении используется большое число объектов;
- из-за этого накладные расходы на хранение высоки;
- большую часть состояния объектов можно вынести вовне;
- многие группы объектов можно заменить относительно небольшим количеством разделяемых объектов, поскольку внешнее состояние вынесено.
*/

// Flyweight (Character) - объявляет интерфейс, с помощью которого приспособленцы могут получать внешнее состояние.

class Sprite {
public:
	// внешнее состояние
	int pointSize;
	int color;
};

class Character abstract
{
protected:
	// внутреннее состояние
	char symbol;
	int width;
	int height;

	Sprite* sprite;

public:
	virtual  void Display(Sprite* sprite) abstract;
};

/*
ConcreteFlyweight (CharacterA) - конкретный приспособленец.
Реализует интерфейс класса Flyweight и добавляет при необходимости внутреннее состояние.
Объект класса ConcreteFlyweight должен быть разделяемым. 
Любое сохраняемое им состояние должно быть внутренним, то есть не зависящим от контекста.
*/

class CharacterA : public Character
{
public:
	CharacterA()
	{
		symbol = 'A';
		height = 100;
		width = 120;
	}
	void Display(Sprite* sprite) override
	{
		this->sprite = sprite;
		char buffer[100];
		sprintf_s(buffer, " (pointsize: %d   color: %d)\n", this->sprite->pointSize, this->sprite->color);
		cout << this->symbol << buffer;
	}
};

/*
ConcreteFlyweight (CharacterB) - конкретный приспособленец.
Реализует интерфейс класса Flyweight и добавляет при необходимости внутреннее состояние.
Объект класса ConcreteFlyweight должен быть разделяемым.
Любое сохраняемое им состояние должно быть внутренним, то есть не зависящим от контекста.
*/
class CharacterB : public Character
{
public:
	CharacterB()
	{
		symbol = 'B';
		height = 100;
		width = 140;
	}
	void Display(Sprite* sprite) override
	{
		this->sprite = sprite;
		char buffer[100];
		sprintf_s(buffer, " (pointsize: %d   color: %d)\n", this->sprite->pointSize, this->sprite->color);
		cout << this->symbol << buffer;
	}
};

//...
/*
ConcreteFlyweight (CharacterZ) - конкретный приспособленец.
Реализует интерфейс класса Flyweight и добавляет при необходимости внутреннее состояние.
Объект класса ConcreteFlyweight должен быть разделяемым.
Любое сохраняемое им состояние должно быть внутренним, то есть не зависящим от контекста.
*/

class CharacterZ : public Character
{
public:
	CharacterZ()
	{
		symbol = 'Z';
		height = 100;
		width = 100;
	}
	void Display(Sprite* sprite) override
	{
		this->sprite = sprite;
		char buffer[100];
		sprintf_s(buffer, " (pointsize: %d   color: %d)\n", this->sprite->pointSize, this->sprite->color);
		cout << this->symbol << buffer;
	}
};

/*
FlyweightFactory - фабрика приспособленцев:
- создает объекты-приспособленцы и управляет ими;
- обеспечивает должное разделение приспособленцев. Когда клиент запрашивает приспособленца,
объект FlyweightFactory предоставляет существующий экземпляр или создает новый, если готового еще нет.
*/
class CharacterFactory
{
private:
	map<char, Character*> characters;
public:
	Character* GetCharacter(char key)
	{
		Character *character = characters[key];
		if (character == nullptr)
		{
			switch (key)
			{
			case 'A':
				character = new CharacterA();
				break;
			case 'B':
				character = new CharacterB();
				break;
				//...
			case 'Z':
				character = new CharacterZ();
				break;
			}
			characters[key] = character;
		}
		return character;
	}
};

int main()
{
	/*
	 Client - клиент:
		- хранит ссылки на одного или нескольких приспособленцев;
		- вычисляет или хранит внешнее состояние приспособленцев.
	 */
	string s = "AAZZBBZB";
	CharacterFactory *pCF = new CharacterFactory();
	Sprite sprite;
	// внешнее состояние
	sprite.pointSize = 10;
	sprite.color = 7;
	for(int i = 0; i < s.length(); i++)
	{
		sprite.pointSize++;
		sprite.color++;
		Character *character = pCF->GetCharacter(s[i]);
		character->Display(&sprite);
	}

	system("pause");
}
