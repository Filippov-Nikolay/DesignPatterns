#include <iostream>
#include <string>
using namespace std;

// ������� Decorator ����������� ��������� ������� ����� �����������. 
// �������� ������ ������������� ���������� ���������� � ����� ���������� ����������������.

// ���������� ��� ���������� ����������� �����������

// Component (VisualComponent) - ��������� ���������� ��������� ��� ��������, �� ������� ����� ���� ����������� ��������� �������������� �����������
class VisualComponent abstract
{
public:
	virtual void Draw() abstract;
};

// ConcreteComponent (TextView) - ���������� ��������� ���������� ������, �� ������� ����������� �������������� �����������
class TextView : public VisualComponent
{
public:
	void Draw() override
	{
		cout << "Basic functionality - display text in a window\n";
	}
};

// Decorator ������ ������ �� ������ Component � ���������� ���������, ��������������� ���������� Component
class Decorator abstract: public VisualComponent
{
protected:
	VisualComponent* component;
public:
	void SetComponent(VisualComponent* component)
	{
		this->component = component;
	}
	void Draw() override
	{
		if (component != nullptr)
		{
			component->Draw();
		}
	}
};

// ConcreteDecorator (ScrollDecorator) - ���������� ��������� ��������� �������������� ����������� �� ���������.
class ScrollDecorator : public Decorator
{
public:
	void Scroll() // �������������� ����������������
	{
		cout << "Additional functionality - scrolling implementation\n";
	}
	void Draw() override
	{
		Decorator::Draw();
		this->Scroll();
	}
};

// ConcreteDecorator (BorderDecorator) - ���������� ��������� ��������� �������������� ����������� �� ���������.
class BorderDecorator: public Decorator
{
public:
	void DrawBorder() // �������������� ����������������
	{
		cout << "Additional functionality - frame rendering\n";
	}
	void Draw() override
	{
		this->DrawBorder();
		Decorator::Draw();
	}
};

void client(VisualComponent *vc)
{
	vc->Draw();
}

int main()
{
	VisualComponent *vc = new TextView();
	client(vc);
	cout << endl;
	// ������� ��������� (������) ��� ������� ��������� ������ � ����� ���������� ����������� ���������� ������
	Decorator *d = new ScrollDecorator();
	d->SetComponent(vc);
	//Decorator ������������ ������� ������� Component. ����� ��������� �������������� �������� �� � ����� �������������.
	client(d);
	cout << endl;
	// ������� ��������� (������) ��� ������� ��������� ������ � ����� ���������� ����������� ��������� ����� ������ ������
	d = new BorderDecorator();
	d->SetComponent(vc);
	//Decorator ������������ ������� ������� Component. ����� ��������� �������������� �������� �� � ����� �������������.
	client(d);

	system("pause");
}

	

