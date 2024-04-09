#pragma once

/*
 * �������� ������������� ������ �������� ��������� ��������, �� �������� � ������ �� ����������.
 * �������� ���� �������� Iterator ����������� � ���, ����� ������������ ����������� ������������
 * ������ �� ���������, �� ��� �������� ������������ �� ��������� ��� ���������� � ��������� ������� � ���������.
 */

class Iterator abstract
{
public:
	virtual int First() abstract;
	virtual int Next() abstract;
	virtual bool IsDone() abstract;
	virtual int CurrentItem() abstract;
};
