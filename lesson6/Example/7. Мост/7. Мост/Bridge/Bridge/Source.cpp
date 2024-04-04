#include <iostream>
using namespace std;

/*
 ������� Bridge ��������� �������� ���������� �� �� ���������� ���,
 ����� �� � ������ ����� ���� �������� ����������.

������ ������� ������������ �����:
- ����� �������� ���������� �������� ���������� � ����������.
���, ��������, ������, ����� ���������� ���������� �������� �� ����� ���������� ���������.
- � ����������, � ���������� ������ ����������� ������ �����������.
� ����� ������ ������� ���� ��������� ������������� ������ ���������� � ���������� � �������� �� ����������;
- ��������� � ���������� ���������� �� ������ ����������� �� ��������, �� ���� ���������� ��� �� ������ �������������������;

����������:
- ��������� ���������� �� ����������;
- ��������� ������� �������������;
- �������� ������� ���������� �� ��������.
*/

/*
Implementor(ILanguage) - ���������� ���������� ��������� ��� ������� ����������.
*/
class ILanguage abstract
{
public:
	virtual void Build() abstract;
	virtual void Execute() abstract;
};

// Concretelmplementor (CPPLanguage)  - ���������� ����������  �������� ���������� ���������� ���������� ������ Implementor.
class CPPLanguage: public ILanguage
{
public:
	void Build() override
	{
		cout << "Using the C++ compiler, we compile the program into a binary code\n\n";
	}
	void Execute() override
	{
		cout << "Run the executable file\n\n";
	}
};

// Concretelmplementor (CSharpLanguage) - ���������� ����������  �������� ���������� ���������� ���������� ������ Implementor.
class CSharpLanguage : public ILanguage
{
public:
	void Build() override
	{
		cout << "We compile the source code, we get the assembly(exe)\n\n";
	}
	void Execute() override
	{
		cout << "JIT-compiler compiles a program into a binary code\n\n";
		cout << "CLR executes compiled binary code\n\n";
	}
};

// Abstraction (Programmer) - ���������� ��������� ���������� � ������ ������ �� ������ ���������� ���� Implementor
class Programmer abstract
{
protected:
	ILanguage* language;
public:
	ILanguage* GetLanguage()
	{
		return language;
	}
	void SetLanguage(ILanguage* language)
	{
		this->language = language;
	}
	virtual void DoWork()
	{
		language->Build();
		language->Execute();
	}
	virtual void EarnMoney() abstract;
};

// RefinedAbstraction (FreelanceProgrammer)  - ���������� ���������� ��������� ���������, ������������ ����������� Abstraction
class FreelanceProgrammer: public Programmer
{
public:
	void EarnMoney() override
	{
		cout << "We receive payment for the executed order\n\n";
	}
};

// RefinedAbstraction (CorporateProgrammer)  - ���������� ���������� ��������� ���������, ������������ ����������� Abstraction
class CorporateProgrammer: public Programmer
{
public:
	void EarnMoney() override
	{
		cout << "We get a salary at the end of the month\n\n";
	}
};

void client(ILanguage* lang, Programmer* programmer)
{
	programmer->SetLanguage(lang);
	// ������ Abstraction (Programmer) �������������� ������ ������� Implementor ������� �������.
	programmer->DoWork();
	programmer->EarnMoney();
}

int main()
{
	ILanguage* lang = new CPPLanguage();
	Programmer* programmer = new FreelanceProgrammer();
	client(lang, programmer);
	delete lang;

	lang = new CSharpLanguage();
	client(lang, programmer);
	delete lang;
	delete programmer;

	lang = new CPPLanguage();
	programmer = new CorporateProgrammer();
	client(lang, programmer);
	delete lang;

	lang = new CSharpLanguage();
	client(lang, programmer);
	delete lang;
	delete programmer;

	system("pause");
	return 0;
}