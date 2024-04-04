#include <iostream>
using namespace std;

/*
 Паттерн Bridge позволяет отделить абстракцию от ее реализации так,
 чтобы то и другое можно было изменять независимо.

Данный паттерн используется когда:
- нужно избежать постоянной привязки абстракции к реализации.
Так, например, бывает, когда реализацию необходимо выбирать во время выполнения программы.
- и абстракции, и реализации должны расширяться новыми подклассами.
В таком случае паттерн мост позволяет комбинировать разные абстракции и реализации и изменять их независимо;
- изменения в реализации абстракции не должны сказываться на клиентах, то есть клиентский код не должен перекомпилироваться;

Результаты:
- отделение реализации от интерфейса;
- повышение степени расширяемости;
- сокрытие деталей реализации от клиентов.
*/

/*
Implementor(ILanguage) - реализатор определяет интерфейс для классов реализации.
*/
class ILanguage abstract
{
public:
	virtual void Build() abstract;
	virtual void Execute() abstract;
};

// Concretelmplementor (CPPLanguage)  - конкретный реализатор  содержит конкретную реализацию интерфейса класса Implementor.
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

// Concretelmplementor (CSharpLanguage) - конкретный реализатор  содержит конкретную реализацию интерфейса класса Implementor.
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

// Abstraction (Programmer) - определяет интерфейс абстракции и хранит ссылку на объект реализации типа Implementor
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

// RefinedAbstraction (FreelanceProgrammer)  - утонченная абстракция расширяет интерфейс, определенный абстракцией Abstraction
class FreelanceProgrammer: public Programmer
{
public:
	void EarnMoney() override
	{
		cout << "We receive payment for the executed order\n\n";
	}
};

// RefinedAbstraction (CorporateProgrammer)  - утонченная абстракция расширяет интерфейс, определенный абстракцией Abstraction
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
	// Объект Abstraction (Programmer) перенаправляет своему объекту Implementor запросы клиента.
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