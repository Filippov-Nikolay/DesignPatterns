#pragma once
#include <string>

using namespace std;

class ILog
{
public:
	virtual void Write(string str)=0;
};