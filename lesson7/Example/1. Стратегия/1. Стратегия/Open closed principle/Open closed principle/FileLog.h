#pragma once
#include "ILog.h"
#include <fstream>

class FileLog : public ILog
{
public:
	void Write(string str) override;
};
