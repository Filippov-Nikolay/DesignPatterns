#pragma once
#include "Participant.h"

//ConcreteColleague class
class NonBeatles: public Participant
{
public:
	NonBeatles(string name) : Participant(name) {}
	void Receive(string from, string message) override;
};
