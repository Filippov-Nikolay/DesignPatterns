#include "Ñontainer.h"

void Client(ILog * pILog, IStream * pIStream)
{
	Ñontainer c;
	c.SetLog(pILog);
	c.Add(Human("Larry Page", 45));
	c.Add(Human("Satya Nadella", 51));
	c.Add(Human("Tim Cook", 58));
	c.Print();

	c.SetSerializer(pIStream);
	c.Save();
	c.RemoveAll();
	c.Load();
	c.Print();
}

#include "ConsoleLog.h"
#include "FileLog.h"
#include "TextFormatter.h"
#include "BinaryFormatter.h"
int main()
{
	ILog * pILog = new ConsoleLog;
	IStream * pIStream = new BinaryFormatter;
	Client(pILog, pIStream);
	delete pILog;
	delete pIStream;

	pIStream = new TextFormatter;
	pILog = new FileLog;
	Client(pILog, pIStream);
	delete pILog;
	delete pIStream;

	system("pause");
	return 0;
}
