#pragma once
#include "Participant.h"

//ConcreteColleague class
class Beatles: public Participant
{
public:
	Beatles(string name) : Participant(name) {}
	void Receive(string from, string message) override;
};
