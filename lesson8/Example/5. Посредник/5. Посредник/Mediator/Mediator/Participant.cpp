#include "Participant.h"
#include <iostream>
using namespace std;

void Participant::Send(string to, string message)
{
	chatroom->Send(name, to, message);
}
void Participant::Receive(string from, string message)
{
	cout << from << " to " << name << ": '" << message << "'" << endl;
}