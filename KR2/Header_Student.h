#include "Header_date.h"

// Класс студента
class Student
{
private:
	string surname; // Фамилия
	string adress; // Адресс
	string group; // Группа
	Date rojd; // Дата рождения
	Date post; // Дата поступления
	Date otch; // Дата отчисления
public:
	Student(); // Конструктор по умолчанию
	Student(const Student&); // Конструктор копирования
	void Get(string, string, string, Date, Date, Date); // Запись полей
	friend bool operator <(Student&, Student&); // Перегрузка оператора меньше
	friend bool operator >(Student&, Student&); // Перегрузка оператора больше
	friend ostream& operator<<(ostream&, Student); // Перегрузка оператора вывода
	friend ofstream& operator <<(ofstream&, const Student&); // Перегрузка оператора вывода в файл
	friend ifstream& operator >>(ifstream&, Student&); // Перегрузка оператора ввода из файла
	int sravn(const Student, int); // Сравнение
	int search(string, int); // Поиск по строкам
	int search(Date, int); // Поиск по датам
	void edit(string, int);
	void edit(Date, int);
};

// Конструктор по умолчанию
Student::Student()
{
	surname = '\0';
	adress = '\0';
	group = '\0';
	rojd = Date();
	post = Date();
	otch = Date();
}

// Конструктор копирования
Student::Student(const Student& s)
{
	surname = s.surname;
	adress = s.adress;
	group = s.group;
	rojd = s.rojd;
	post = s.post;
	otch = s.otch;
}

// Запись полей
void Student::Get(string surname, string adress, string group, Date rojd, Date post, Date otch)
{
	this->surname = surname;
	this->adress = adress;
	this->group = group;
	this->rojd = rojd;
	this->post = post;
	this->otch = otch;
}

bool operator<(Student& s1, Student& s2) // Перегрузка оператора меньше
{
	if (s1.surname < s2.surname) // Сравнение по фамилии
		return true;
	else
		return false;
}

bool operator>(Student& s1, Student& s2) // Перегрузка оператора больше
{
	if (s1.surname > s2.surname) // Сравнение фамилии
		return true;
	else
		return false;
}

// Вывод
ostream& operator<<(ostream& out, Student st)
{
	out << setw(15) << st.surname << setw(9)<<'|'<<setw(13)<<st.rojd.Print()<<'|'<<setw(17)<<st.adress<<setw(8)<<'|'<<setw(8)<<st.group<<setw(1)<<'|'<<setw(13)<<st.post.Print()<<setw(4)<<'|'<<setw(15)<<st.otch.Print()<<setw(3)<<'|'<<endl;
	return out;
}

// Вывод в бинарный файл
ofstream& operator<<(ofstream& out, const Student& d)
{
	size_t len = d.surname.size(); // Запись длины строки
	out.write((char*)&len, sizeof(size_t));
	out.write((char*)d.surname.c_str(), len);

	len = d.group.size();
	out.write((char*)&len, sizeof(size_t));
	out.write((char*)d.group.c_str(), len);

	len = d.adress.size();
	out.write((char*)&len, sizeof(size_t));
	out.write((char*)d.adress.c_str(), len);

	out.write((char*)&d.rojd.dd, sizeof(int));
	out.write((char*)&d.rojd.mm, sizeof(int));
	out.write((char*)&d.rojd.ss, sizeof(int));

	out.write((char*)&d.post.dd, sizeof(int));
	out.write((char*)&d.post.mm, sizeof(int));
	out.write((char*)&d.post.ss, sizeof(int));
	out.write((char*)&d.otch.dd, sizeof(int));
	out.write((char*)&d.otch.mm, sizeof(int));
	out.write((char*)&d.otch.ss, sizeof(int));
	return out;
}

// Ввод из бинарного файла
ifstream& operator>>(ifstream& in, Student& d)
{
	size_t len;
	in.read((char*)&len, sizeof(size_t));
	if (in.eof()) // Проверка на конец файла
	{
		return in;
	}
	d.surname.resize(len); // Изменение длины строки
	in.read((char*)d.surname.data(), len); // Запись строки

	in.read((char*)&len, sizeof(size_t));
	d.group.resize(len);
	in.read((char*)d.group.data(), len);
	
	in.read((char*)&len, sizeof(size_t));
	d.adress.resize(len);
	in.read((char*)d.adress.data(), len);

	in.read((char*)&d.rojd.dd, sizeof(int));
	in.read((char*)&d.rojd.mm, sizeof(int));
	in.read((char*)&d.rojd.ss, sizeof(int));

	in.read((char*)&d.post.dd, sizeof(int));
	in.read((char*)&d.post.mm, sizeof(int));
	in.read((char*)&d.post.ss, sizeof(int));
	in.read((char*)&d.otch.dd, sizeof(int));
	in.read((char*)&d.otch.mm, sizeof(int));
	in.read((char*)&d.otch.ss, sizeof(int));
	return in;
}

// Сравнение
int Student::sravn(const Student n2, int q) // В зависимости от q выбирается что сравнивать
{
	switch (q)
	{
	case 1:
		if (this->surname > n2.surname) // Сравнение фамилии
			return 1;
		else
			if (this->surname <= n2.surname)
				return 0;
		break;
	case 2:
		if (this->rojd.Sravn(n2.rojd.dd, n2.rojd.mm, n2.rojd.ss))
			return 1;
		else
			return 0;
		break;
	case 3:
		if (this->group > n2.group) // Сравнение группы
			return 1;
		else
			if (this->group <= n2.group)
				return 0;
		break;
	case 4:
		if (this->adress > n2.adress) // Сравнение адреса
			return 1;
		else
			if (this->adress <= n2.adress)
				return 0;
		break;
	case 5:
		if (this->post.Sravn(n2.post.dd, n2.post.mm, n2.post.ss))
			return 1;
		else
			return 0;
		break;
	case 6:
		if (this->otch.Sravn(n2.otch.dd, n2.otch.mm, n2.otch.ss))
			return 1;
		else
			return 0;
		break;
	default:
		break;
	}
}

// Поиск
int Student::search(string x, int q) // В зависимости от q, происходит выбор по каким полям строк сравнивать
{
	switch (q)
	{
	case 1:
		if (this->surname == x)
			return 1;
		else
			return 0;
		break;
	case 3:
		if (this->group == x)
			return 1;
		else
			return 0;
		break;
	case 4:
		if (this->adress == x)
			return 1;
		else
			return 0;
		break;
	default:
		break;
	}
}

int Student::search(Date x, int q) // В зависимости от q, происходит выбор по каким датам сравнивать
{
	switch (q)
	{
	case 2:
		if (this->rojd == x)
			return 1;
		else
			return 0;
		break;
	case 5:
		if (this->post == x)
			return 1;
		else
			return 0;
		break;
	case 6:
		if (this->otch == x)
			return 1;
		else
			return 0;
		break;
	default:
		break;
	}
}

void Student::edit(string str1, int l)
{
	switch (l)
	{
	case 1:
		surname = str1;
		break;
	case 3:
		group = str1;
		break;
	case 4:
		adress = str1;
		break;
	default:
		break;
	}
}

void Student::edit(Date d, int l)
{
	switch (l)
	{
	case 2:
		rojd = d;
		break;
	case 5:
		post = d;
		break;
	case 6:
		otch = d;
		break;
	default:
		break;
	}
}