#include <iostream>
#include <string>
#include <ctime>
using namespace std;

/* ������� ��������� �������� ��������������� �������� ������� �� ��� �������������, ��� ���
	   � ���������� ������ � ���� �� �������� ��������������� ����� ���������� ������ �������������.
	������������
	   - �������� �������� �������� ������� �� ������ �������� �� ����, �� ����� ������ ������� ������ � ��� ��� ��������� ����� �����;
	   - ������� ��������������� ������ ������������ ��������� ������������� ��������������� �������.
   ����� � ������ �������� ��������� � ��� ����������:
	- ��������� �������� ���������� ������������� ��������
	- ��������� ���, ����������� ��������������� � �������������
	- ���� ����� ������ �������� ��� ��������� ���������������
   */

/*
	 matrix (�������) ������������ ������� �������������� ������. 
	 ConcreteBuilder ������ ���������� ������������� �������� � ���������� ������� ��� ������.
*/
class matrix
{
	int **p;
	int row, col;
public:
	matrix() // ����������� �� ���������
	{
		row = 0;
		col = 0;
		p = nullptr;
	}
	matrix(int row, int col) // ����������� � �����������
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
	matrix(const matrix & m) // ����������� �����������
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
	~matrix() // ����������
	{
		for (int i = 0; i < row; i++)
		{
			delete[] p[i];
		}
		delete[] p;
	}
	matrix& operator= (const matrix & m) // ������������� �������� =
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

// Abstract Builder ������ ����������� ��������� ��� �������� ������ ������� Product
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

// ConcreteBuilder ��������� ��������� ��������:
	// - ������������ � �������� ������ ����� �������� ����������� ���������� ���������� Builder;
	// - ���������� ����������� ������������� � ������ �� ���;
	// - ������������� ��������� ��� ������� � ��������
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

// ConcreteBuilder ��������� ��������� ��������:
	// - ������������ � �������� ������ ����� �������� ����������� ���������� ���������� Builder;
	// - ���������� ����������� ������������� � ������ �� ���;
	// - ������������� ��������� ��� ������� � ��������
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

// Director(�������������) - ������������ ������, ��������� ����������� Builder
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
		// ������ ����������
		builder->Start();
		for (int r = 0; r < m.GetRow(); ++r) {
			// ������ ����� ������ �������
			builder->StartRow();
			for (int c = 0; c < m.GetColumn(); ++c) {
				// �������� ������� �������
				builder->AddItem(m(r, c));
			}
			// ��������� ������ �������
			builder->FinishRow();
		}
		// ��������� ����������
		builder->Finish();
		// �������� ��������� ����������
		return builder->Result();
	}
};

// ������ ������� ������-������������� Director � ������������� ��� ������ ��������-���������� Builder
void client(ArrayBuilder * builder)
{
	matrix m(4, 7);
	// ������� ���������
	ArrayConverter converter(builder);

	// ������������� ���������� ��������� � ���, ��� ����� ��������� �������
	// �������� �����������
	string textArray = converter.Convert(m);
	// ������� ��������� ���������� �� �������
	cout << textArray;
}

void main()
{
	srand(time(nullptr));
	cout << "Text representation of an array:\n";
	// ������������� ��������� ���������� ���������� �������������
	ArrayBuilder * builder = new TextArrayBuilder();
	client(builder);
	delete builder;

	cout << "Xml representation of an array:\n";
	// ������������� ��������� ���������� xml-�������������
	builder = new XmlArrayBuilder();
	client(builder);
	delete builder;

	system("pause");
}