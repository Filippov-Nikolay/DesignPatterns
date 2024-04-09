#include <iostream>
#include <map>
#include <string>
#include "Participant.h"
#include "Chatroom.h"
#include "Beatles.h"
#include "NonBeatles.h"
using namespace std;
/*
	Mediator (Посредник) позволяет группе объектов взаимодействовать, не ссылаясь напрямую друг на друга, а используя промежуточный объект.
	Этот объект передаёт запросы от каждого участника группы всем остальным или части группы, своеобразно координируя их действия.
	В целом вариант передачи запроса между членами группы посредством Медиатора определяется конкретной поставленной задачей.
	Каждый участник группы знает, кто координирует его взаимодействие с другими подобными объектами, а медиатор инкапсулирует механизм регистрации участников группы.
	Также Медиатор инкапсулирует протокол общения между участниками группы.
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