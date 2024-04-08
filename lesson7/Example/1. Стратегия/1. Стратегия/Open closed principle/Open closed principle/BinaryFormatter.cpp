#include "BinaryFormatter.h"
#include <fstream>

void BinaryFormatter::Save(vector<Human> v)
{
	ofstream out("data.dat", ios::binary | ios::out | ios::trunc);
	int size = v.size();
	out.write((char*)&size, sizeof(int));
	for (auto h : v)
	{
		out.write((char*)&h, sizeof(h));
	}
	out.close();
}

vector<Human> BinaryFormatter::Load()
{
	ifstream in("data.dat", ios::binary | ios::in);
	int size;
	in.read((char*)&size, sizeof(int));
	Human *h = new Human;
	vector<Human> v;
	for (int i = 0; i < size; i++)
	{
		in.read((char*)h, sizeof(Human));
		v.push_back(*h);
	}
	in.close();
	return v;
}