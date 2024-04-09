#pragma once
#include <string>
using namespace std;

class Participant;

// The 'Mediator' abstract class
class AbstractChatroom abstract
{
public:
	virtual void Register(Participant* participant) abstract;
	virtual void Send(string from, string to, string message) abstract;
};
