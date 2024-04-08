#include "TextFormatter.h"
#include <fstream>

void TextFormatter::Save(vector<Human> v)
{
	ofstream out("data.txt");
	for (auto h : v)
	{
		out << h.GetName() << endl << h.GetAge();
	}
	out.close();
}

vector<Human> TextFormatter::Load()
{
	ifstream in("data.txt");
	vector<Human> v;
	while (!in.eof())
	{
		string name;
		int age;
		getline(in, name);
		in >> age;
		v.push_back(Human(name, age));
	}
	in.close();
	return v;
}