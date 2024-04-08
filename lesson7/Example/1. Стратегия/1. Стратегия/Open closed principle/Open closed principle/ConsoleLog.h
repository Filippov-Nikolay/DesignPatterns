#pragma once
#include "ILog.h"
#include <iostream>


class ConsoleLog : public ILog
{
	public:
		void Write(string str) override;
};
