#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <locale>
#include <string>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <iomanip>

using namespace std;

// Класс даты
class Date
{
public:
	int dd;
	int mm;
	int ss;

	Date(); // Конструктор
	string Print(); // Вывод даты в строке
	Date Get(int, int, int); // Запись даты, если нет 0
	bool friend operator==(Date, Date); // Перегрузка оператора сравнения
	bool Sravn(int, int, int);
};

// Конструктор, который зануляет все поля
Date::Date()
{
	dd = 0;
	mm = 0;
	ss = 0;
}

// Вывод в строку
string Date::Print()
{
	string temp; // Строка, в которую всё записывается
	if (dd == 0 || mm == 0 || ss == 0) // При условии, когда есть хотя бы один ноль, строка остаётся пустой
		temp = "Не отчислен";
	else
	{
		if (dd / 10 == 0) // Если число состоит из одной цифры, то дописывается 0 в начале
		{
			temp = "0";
			temp = temp + to_string(dd); // Переводит число в символы
		}
		else
		{
			temp = to_string(dd);
		}
		temp = temp + ".";
		if (mm / 10 == 0) // Если число состоит из одной цифры, то дописывается 0 в начале
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

// Если хоть одна составляющая даты 0, то заполнить всё нулями
Date Date::Get(int dd, int mm, int ss)
{
	this->dd = dd;
	this->mm = mm;
	this->ss = ss;
	return *this;
}

// Сравнение всех составляющих класса даты
bool operator==(Date d1, Date d2)
{
	if (d1.dd == d2.dd && d1.mm == d2.mm && d1.ss == d2.ss)
		return true;
	else
		return false;
}

bool Date::Sravn(int dd, int mm, int ss)
{
	if (this->ss < ss) // Сравнение даты
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