#include <iostream>
using namespace std;

/*
 �������� (Singleton) � ����������� ������ ��������������, �����������, 
 ��� � ������ ���� ������ ���� ���������, � ������������� � ���� ���������� ����� �������.
 ����������� ��, ��� ����� ������������ ������ ����������� ������, 
 ��� ��� ��� ���� �� ������ ������� ���������� ��������� ����� ������� ����������������.
 */

class President
{ 
private: 	
	// ��������� �� ������������ ��������� ������
	static President*s;
	int k; 

	// �������� �����������
	President(int i) {
		k = i;
	}  
public:
	// ����� ��� ��������� ��������� �� ������������ ��������� ������
	static President* getReference() {
		if(s == nullptr)
			s = new President(7);
	   return s;
	}  
	// ��������� �������� �������������� ����� ������
	int getValue() {
		return k;
	}  
	// ���������� �������� �������������� ����� ������
	void setValue(int i) {
		k = i;
	}


	// ������
	void print() {
		cout << "Hello world" << endl;
	}
};  

// ����������� ������������ ����� ������
President* President::s;

void main() {  
	// Singleton *instance = new President; // ������ ����������
	// ��������� ��������� �� ������������ ��������� ������
	President* p = President::getReference();
	// ������ � ����������� �������
	cout << p->getValue() << "\n\n";
	p->setValue(p->getValue() + 5);
	cout << p->getValue() << "\n\n";

	p->print();
} 

