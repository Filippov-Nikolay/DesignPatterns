#pragma once
#include "AbstractChatroom.h"

// The 'Colleague' abstract class
class Participant abstract
{
	AbstractChatroom* chatroom;
	string name;
public:
	Participant(string name)
	{
		this->name = name;
	}
	string GetName()
	{
		return name;
	}
	void SetName(string name)
	{
		this->name = name;
	}
	AbstractChatroom* GetChatroom()
	{
		return chatroom;
	}
	void SetChatroom(AbstractChatroom* chatroom)
	{
		this->chatroom = chatroom;
	}
	void Send(string to, string message);
	virtual void Receive(string from, string message);
};
