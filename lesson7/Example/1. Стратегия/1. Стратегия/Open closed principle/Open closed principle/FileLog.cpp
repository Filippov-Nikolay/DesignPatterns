#include "FileLog.h"

void FileLog::Write(string str)
{
	ofstream out("log.txt", ios::app);
	out << str;
	out.close();
}