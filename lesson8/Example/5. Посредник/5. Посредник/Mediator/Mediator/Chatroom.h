#pragma once
#include "AbstractChatroom.h"
#include "Participant.h"
#include <map>
#include <string>
using namespace std;

// The 'ConcreteMediator' class
class Chatroom: public AbstractChatroom
{
	map<string, Participant*> participants;
public:
	void Register(Participant* participant);
	void Send(string from, string to, string message) override;
};
