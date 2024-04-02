#include <iostream>
#include <string>
using namespace std;

// паттерн Decorator динамически добавляет объекту новые обязанности. 
// Является гибкой альтернативой порождению подклассов с целью расширения функциональности.

// Библиотека для построения графических интерфейсов

// Component (VisualComponent) - компонент определяет интерфейс для объектов, на которые могут быть динамически возложены дополнительные обязанности
class VisualComponent abstract
{
public:
	virtual void Draw() abstract;
};

// ConcreteComponent (TextView) - конкретный компонент определяет объект, на который возлагаются дополнительные обязанности
class TextView : public VisualComponent
{
public:
	void Draw() override
	{
		cout << "Basic functionality - display text in a window\n";
	}
};

// Decorator хранит ссылку на объект Component и определяет интерфейс, соответствующий интерфейсу Component
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

// ConcreteDecorator (ScrollDecorator) - конкретный декоратор возлагает дополнительные обязанности на компонент.
class ScrollDecorator : public Decorator
{
public:
	void Scroll() // Дополнительная функциональность
	{
		cout << "Additional functionality - scrolling implementation\n";
	}
	void Draw() override
	{
		Decorator::Draw();
		this->Scroll();
	}
};

// ConcreteDecorator (BorderDecorator) - конкретный декоратор возлагает дополнительные обязанности на компонент.
class BorderDecorator: public Decorator
{
public:
	void DrawBorder() // Дополнительная функциональность
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
	// Создаем декоратор (обёртку) для объекта просмотра текста с целью реализации возможности скроллинга текста
	Decorator *d = new ScrollDecorator();
	d->SetComponent(vc);
	//Decorator переадресует запросы объекту Component. Может выполнять дополнительные операции до и после переадресации.
	client(d);
	cout << endl;
	// Создаем декоратор (обёртку) для объекта просмотра текста с целью реализации возможности отрисовки рамки вокруг текста
	d = new BorderDecorator();
	d->SetComponent(vc);
	//Decorator переадресует запросы объекту Component. Может выполнять дополнительные операции до и после переадресации.
	client(d);

	system("pause");
}

	

