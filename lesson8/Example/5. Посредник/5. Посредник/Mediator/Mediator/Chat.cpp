#include "Participant.h"

void registration(AbstractChatroom* chatroom, Participant *participants[], int size)
{
	for (int i = 0; i < size; i++)
		chatroom->Register(participants[i]);
}

void chat(Participant *participants, string to, string message)
{
	participants->Send(to, message);
}