#include <iostream>
using namespace std;

/*
 Одиночка (Singleton) — порождающий шаблон проектирования, гарантирует, 
 что у класса есть только один экземпляр, и предоставляет к нему глобальную точку доступа.
 Существенно то, что можно пользоваться именно экземпляром класса, 
 так как при этом во многих случаях становится доступной более широкая функциональность.
 */

class President
{ 
private: 	
	// Указатель на единственный экземпляр класса
	static President*s;
	int k; 

	// Закрытый конструктор
	President(int i) {
		k = i;
	}  
public:
	// Метод для получения указателя на единственный экземпляр класса
	static President* getReference() {
		if(s == nullptr)
			s = new President(7);
	   return s;
	}  
	// Получение значения нестатического члена класса
	int getValue() {
		return k;
	}  
	// Перезапись значения нестатического члена класса
	void setValue(int i) {
		k = i;
	}


	// Методы
	void print() {
		cout << "Hello world" << endl;
	}
};  

// Определение статического члена класса
President* President::s;

void main() {  
	// Singleton *instance = new President; // ошибка компиляции
	// Получение указателя на единственный экземпляр класса
	President* p = President::getReference();
	// Работа с компонентом объекта
	cout << p->getValue() << "\n\n";
	p->setValue(p->getValue() + 5);
	cout << p->getValue() << "\n\n";

	p->print();
} 

