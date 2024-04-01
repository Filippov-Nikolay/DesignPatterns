#include <iostream>
#include <string>
#include <ctime>
using namespace std;

/* Паттерн Строитель отделяет конструирование сложного объекта от его представления, так что
	   в результате одного и того же процесса конструирования могут получаться разные представления.
	Применимость
	   - алгоритм создания сложного объекта не должен зависеть от того, из каких частей состоит объект и как они стыкуются между собой;
	   - процесс конструирования должен обеспечивать различные представления конструируемого объекта.
   Плюсы и минусы паттерна строитель и его применения:
	- позволяет изменять внутреннее представление продукта
	- изолирует код, реализующий конструирование и представление
	- дает более тонкий контроль над процессом конструирования
   */

/*
	 matrix (продукт) представляет сложный конструируемый объект. 
	 ConcreteBuilder строит внутреннее представление продукта и определяет процесс его сборки.
*/
class matrix
{
	int **p;
	int row, col;
public:
	matrix() // конструктор по умолчанию
	{
		row = 0;
		col = 0;
		p = nullptr;
	}
	matrix(int row, int col) // конструктор с параметрами
	{
		this->row = row;
		this->col = col;
		p = new int*[row];
		for (int i = 0; i < row; i++)
		{
			p[i] = new int[col];
		}
		for (int i = 0; i < this->row; i++)
		{
			for (int j = 0; j < this->col; j++)
			{
				this->p[i][j] = rand() % 30;
			}
		}
	}
	matrix(const matrix & m) // конструктор копирования
	{
		this->row = m.row;
		this->col = m.col;
		this->p = new int*[this->row];
		for (int i = 0; i < this->row; i++)
		{
			this->p[i] = new int[this->col];
			for (int j = 0; j < this->col; j++)
			{
				this->p[i][j] = m.p[i][j];
			}
		}
	}
	~matrix() // деструктор
	{
		for (int i = 0; i < row; i++)
		{
			delete[] p[i];
		}
		delete[] p;
	}
	matrix& operator= (const matrix & m) // перегруженный оператор =
	{
		if (this == &m)
		{
			return *this;
		}
		for (int i = 0; i < row; i++)
		{
			delete[] p[i];
		}
		delete[] p;
		this->row = m.row;
		this->col = m.col;
		this->p = new int*[this->row];
		for (int i = 0; i < this->row; i++)
		{
			this->p[i] = new int[this->col];
			for (int j = 0; j < this->col; j++)
			{
				this->p[i][j] = m.p[i][j];
			}
		}
		return *this;
	}
	int GetRow()
	{
		return row;
	}
	int GetColumn()
	{
		return col;
	}
	int& operator()(int i, int j)
	{
		if (i < 0 || i >= row) 
			i = 0;
		if (j < 0 || j >= col) 
			j = 0;
		return p[i][j];
	}
};

// Abstract Builder задает абстрактный интерфейс для создания частей объекта Product
class ArrayBuilder abstract
{
public:
	virtual void Start(){}
	virtual void StartRow(){}
	virtual void AddItem(int item){}
	virtual void FinishRow(){}
	virtual void Finish(){}
	virtual string Result() abstract;
};

// ConcreteBuilder выполняет следующие действия:
	// - конструирует и собирает вместе части продукта посредством реализации интерфейса Builder;
	// - определяет создаваемое представление и следит за ним;
	// - предоставляет интерфейс для доступа к продукту
class XmlArrayBuilder: public ArrayBuilder
{
private:
	string xml;
public:
	void Start()override
	{
		xml += "<Array>";
		xml += "\n";
		xml += "<rows>";
		xml += "\n";
	}
	void StartRow()override
	{
		xml += "<row>";
		xml += "\n";
	}
	void AddItem(int item)override
	{
		xml += "<item>";
		char buffer[20];
		sprintf_s(buffer, "%d", item);
		xml += buffer;
		xml += "</item>";
		xml += "\n";
	}
	void FinishRow()override
	{
		xml += "</row>";
		xml += "\n";
	}
	void Finish()override
	{
		xml += "</rows>";
		xml += "\n";
		xml += "</Array>";
		xml += "\n";
	}
	string Result()override
	{
		return xml;
	}
};

// ConcreteBuilder выполняет следующие действия:
	// - конструирует и собирает вместе части продукта посредством реализации интерфейса Builder;
	// - определяет создаваемое представление и следит за ним;
	// - предоставляет интерфейс для доступа к продукту
class TextArrayBuilder : public ArrayBuilder
{
private:
	string text;
public:
	void AddItem(int  item)override
	{
		char buffer[20];
		sprintf_s(buffer, "%d", item);
		text += buffer;
		text += "\t";
	}
	void FinishRow()override
	{
		text += "\n";
	}
	string Result()override
	{
		return text;
	}
};

// Director(распорядитель) - конструирует объект, пользуясь интерфейсом Builder
class ArrayConverter
{
private:
	ArrayBuilder *builder;
	
public:
	ArrayConverter(ArrayBuilder* builder)
	{
		this->builder = builder;
	}
	string Convert(matrix & m)
	{
		// начать построения
		builder->Start();
		for (int r = 0; r < m.GetRow(); ++r) {
			// начать новую строку массива
			builder->StartRow();
			for (int c = 0; c < m.GetColumn(); ++c) {
				// добавить элемент массива
				builder->AddItem(m(r, c));
			}
			// завершить строку массива
			builder->FinishRow();
		}
		// завершить построение
		builder->Finish();
		// получить результат построения
		return builder->Result();
	}
};

// клиент создает объект-распорядитель Director и конфигурирует его нужным объектом-строителем Builder
void client(ArrayBuilder * builder)
{
	matrix m(4, 7);
	// создаем конвертер
	ArrayConverter converter(builder);

	// распорядитель уведомляет строителя о том, что нужно построить продукт
	// проводим конвертацию
	string textArray = converter.Convert(m);
	// выводим результат построения на консоль
	cout << textArray;
}

void main()
{
	srand(time(nullptr));
	cout << "Text representation of an array:\n";
	// конфигурируем конвертер строителем текстового представления
	ArrayBuilder * builder = new TextArrayBuilder();
	client(builder);
	delete builder;

	cout << "Xml representation of an array:\n";
	// конфигурируем конвертер строителем xml-представления
	builder = new XmlArrayBuilder();
	client(builder);
	delete builder;

	system("pause");
}