#include "NonBeatles.h"
#include <iostream>
using namespace std;

void NonBeatles::Receive(string from, string message)
{
	cout << "To a non-Beatles: ";
	Participant::Receive(from, message);
}