#include <iostream>
#include <map>
#include <string>
#include "Participant.h"
#include "Chatroom.h"
#include "Beatles.h"
#include "NonBeatles.h"
using namespace std;
/*
	Mediator (���������) ��������� ������ �������� �����������������, �� �������� �������� ���� �� �����, � ��������� ������������� ������.
	���� ������ ������� ������� �� ������� ��������� ������ ���� ��������� ��� ����� ������, ����������� ����������� �� ��������.
	� ����� ������� �������� ������� ����� ������� ������ ����������� ��������� ������������ ���������� ������������ �������.
	������ �������� ������ �����, ��� ������������ ��� �������������� � ������� ��������� ���������, � �������� ������������� �������� ����������� ���������� ������.
	����� �������� ������������� �������� ������� ����� ����������� ������.
*/

void registration(AbstractChatroom* chatroom, Participant *participants[], int size);
void chat(Participant *participants, string to, string message);

int main()
{
	AbstractChatroom* chatroom = new Chatroom();

	Participant *participants[5] = {
		new Beatles("George"),
		new Beatles("Paul"),
		new Beatles("Ringo"),
		new Beatles("John"),
		new NonBeatles("Yoko")
	};
	registration(chatroom, participants, 5);

	chat(participants[4], "John", "Hi John!");
	chat(participants[1], "Ringo", "All you need is love");
	chat(participants[2], "George", "My sweet Lord");
	chat(participants[1], "John", "Can't buy me love");
	chat(participants[3], "Yoko", "My sweet love");

	delete chatroom;
	for (int i = 0; i < 5; i++)
		delete participants[i];

	system("pause");
}