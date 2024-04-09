#include "Chatroom.h"

void Chatroom::Register(Participant* participant)
{
	auto res = participants.find(participant->GetName());
	if (res == participants.end())
	{
		participants[participant->GetName()] = participant;
	}
	participant->SetChatroom(this);
}

void Chatroom::Send(string from, string to, string message)
{
	Participant* participant = participants[to];
	if (participant != nullptr)
	{
		participant->Receive(from, message);
	}
}