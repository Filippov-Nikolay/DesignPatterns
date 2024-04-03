#include <iostream>
#include <map>
#include <string>
using namespace std;

/*
������� ������������ ��� ���������� ������ ��� ������ � ������� ����������� ������ ��������.
������� ��������� ���� �������, ����� ��������� ��� ����������������� �������:
- � ���������� ������������ ������� ����� ��������;
- ��-�� ����� ��������� ������� �� �������� ������;
- ������� ����� ��������� �������� ����� ������� �����;
- ������ ������ �������� ����� �������� ������������ ��������� ����������� ����������� ��������, ��������� ������� ��������� ��������.
*/

// Flyweight (Character) - ��������� ���������, � ������� �������� �������������� ����� �������� ������� ���������.

class Sprite {
public:
	// ������� ���������
	int pointSize;
	int color;
};

class Character abstract
{
protected:
	// ���������� ���������
	char symbol;
	int width;
	int height;

	Sprite* sprite;

public:
	virtual  void Display(Sprite* sprite) abstract;
};

/*
ConcreteFlyweight (CharacterA) - ���������� ��������������.
��������� ��������� ������ Flyweight � ��������� ��� ������������� ���������� ���������.
������ ������ ConcreteFlyweight ������ ���� �����������. 
����� ����������� �� ��������� ������ ���� ����������, �� ���� �� ��������� �� ���������.
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
ConcreteFlyweight (CharacterB) - ���������� ��������������.
��������� ��������� ������ Flyweight � ��������� ��� ������������� ���������� ���������.
������ ������ ConcreteFlyweight ������ ���� �����������.
����� ����������� �� ��������� ������ ���� ����������, �� ���� �� ��������� �� ���������.
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
ConcreteFlyweight (CharacterZ) - ���������� ��������������.
��������� ��������� ������ Flyweight � ��������� ��� ������������� ���������� ���������.
������ ������ ConcreteFlyweight ������ ���� �����������.
����� ����������� �� ��������� ������ ���� ����������, �� ���� �� ��������� �� ���������.
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
FlyweightFactory - ������� ���������������:
- ������� �������-�������������� � ��������� ���;
- ������������ ������� ���������� ���������������. ����� ������ ����������� ��������������,
������ FlyweightFactory ������������� ������������ ��������� ��� ������� �����, ���� �������� ��� ���.
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
	 Client - ������:
		- ������ ������ �� ������ ��� ���������� ���������������;
		- ��������� ��� ������ ������� ��������� ���������������.
	 */
	string s = "AAZZBBZB";
	CharacterFactory *pCF = new CharacterFactory();
	Sprite sprite;
	// ������� ���������
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
