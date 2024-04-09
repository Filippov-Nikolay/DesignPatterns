#include "Beatles.h"
#include <iostream>
using namespace std;

void Beatles::Receive(string from, string message)
{
	cout << "To a Beatles: ";
	Participant::Receive(from, message);
}