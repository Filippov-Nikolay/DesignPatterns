#pragma once
#include "Human.h"
#include "ILog.h"
#include "IStream.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

/*
  * ������� ����������/���������� � ������� ��������-���������������� ����������������,
  * ��������������� ��������� ���������: ������������ �������� (������, ������, ������� � �.�.)
  * ������ ���� ������� ��� ����������, �� ������� ��� ����������; ��� ��������, ��� �����
  * �������� ����� ��������� ������ ���� ��������� ��� ��������� �� ��������� ����.
  */

class �ontainer
{
	vector<Human> human;
	// ��������� ����� Container ������� �� ������������� ����������, �� �� ������ �� �����������.
	// ������ ��������� ������ ����� ���������, �������� ����� ����������� ������ �� ����������.
	ILog * pILog;
	IStream * pIStream;

public:
	void SetSerializer(IStream * pIStream)
	{
		this->pIStream = pIStream;
	}
	void SetLog(ILog * pILog)
	{
		this->pILog = pILog;
	}

	void Add(Human human);
	
	void Remove(int index);
	
	void RemoveAll();
	
	void Print();
	
	void Save();
	
	void Load();
};
