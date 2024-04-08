#include "�ontainer.h"

void �ontainer::Add(Human human)
{
	this->human.push_back(human);
	pILog->Write("Data successfully added!\n");
}

void �ontainer::Remove(int index)
{
	if (index < 0 || index >= human.size())
		return;
	human.erase(human.begin() + index);
	pILog->Write("Deleting completed successfully!\n");
}

void �ontainer::RemoveAll()
{
	human.erase(human.begin(), human.end());
	pILog->Write("All data successfully deleted!\n");
}

void �ontainer::Print()
{
	char buf[50];
	for (auto h : human)
	{
		sprintf_s(buf, "%s\t%d\n", h.GetName().c_str(), h.GetAge());
		pILog->Write(buf);
	}
}

void �ontainer::Save()
{
	pIStream->Save(human);
	pILog->Write("Data successfully saved!\n");
}

void �ontainer::Load()
{
	human = pIStream->Load();
	pILog->Write("Data loaded successfully!\n");
}


