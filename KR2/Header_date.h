#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <locale>
#include <string>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <iomanip>

using namespace std;

// ����� ����
class Date
{
public:
	int dd;
	int mm;
	int ss;

	Date(); // �����������
	string Print(); // ����� ���� � ������
	Date Get(int, int, int); // ������ ����, ���� ��� 0
	bool friend operator==(Date, Date); // ���������� ��������� ���������
	bool Sravn(int, int, int);
};

// �����������, ������� �������� ��� ����
Date::Date()
{
	dd = 0;
	mm = 0;
	ss = 0;
}

// ����� � ������
string Date::Print()
{
	string temp; // ������, � ������� �� ������������
	if (dd == 0 || mm == 0 || ss == 0) // ��� �������, ����� ���� ���� �� ���� ����, ������ ������� ������
		temp = "�� ��������";
	else
	{
		if (dd / 10 == 0) // ���� ����� ������� �� ����� �����, �� ������������ 0 � ������
		{
			temp = "0";
			temp = temp + to_string(dd); // ��������� ����� � �������
		}
		else
		{
			temp = to_string(dd);
		}
		temp = temp + ".";
		if (mm / 10 == 0) // ���� ����� ������� �� ����� �����, �� ������������ 0 � ������
		{
			temp = temp + "0";
			temp = temp + to_string(mm);
		}
		else
		{
			temp = temp + to_string(mm);
		}
		temp = temp + ".";
		temp = temp + to_string(ss);
	}
	return temp;
}

// ���� ���� ���� ������������ ���� 0, �� ��������� �� ������
Date Date::Get(int dd, int mm, int ss)
{
	this->dd = dd;
	this->mm = mm;
	this->ss = ss;
	return *this;
}

// ��������� ���� ������������ ������ ����
bool operator==(Date d1, Date d2)
{
	if (d1.dd == d2.dd && d1.mm == d2.mm && d1.ss == d2.ss)
		return true;
	else
		return false;
}

bool Date::Sravn(int dd, int mm, int ss)
{
	if (this->ss < ss) // ��������� ����
		return true;
	else
		if (this->mm < mm && (this->ss == ss))
			return true;
		else
			if (this->dd < dd && ((this->ss == ss) && (this->mm == mm)))
				return true;
			else
				return false;
}