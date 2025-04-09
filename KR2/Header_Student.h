#include "Header_date.h"

// ����� ��������
class Student
{
private:
	string surname; // �������
	string adress; // ������
	string group; // ������
	Date rojd; // ���� ��������
	Date post; // ���� �����������
	Date otch; // ���� ����������
public:
	Student(); // ����������� �� ���������
	Student(const Student&); // ����������� �����������
	void Get(string, string, string, Date, Date, Date); // ������ �����
	friend bool operator <(Student&, Student&); // ���������� ��������� ������
	friend bool operator >(Student&, Student&); // ���������� ��������� ������
	friend ostream& operator<<(ostream&, Student); // ���������� ��������� ������
	friend ofstream& operator <<(ofstream&, const Student&); // ���������� ��������� ������ � ����
	friend ifstream& operator >>(ifstream&, Student&); // ���������� ��������� ����� �� �����
	int sravn(const Student, int); // ���������
	int search(string, int); // ����� �� �������
	int search(Date, int); // ����� �� �����
	void edit(string, int);
	void edit(Date, int);
};

// ����������� �� ���������
Student::Student()
{
	surname = '\0';
	adress = '\0';
	group = '\0';
	rojd = Date();
	post = Date();
	otch = Date();
}

// ����������� �����������
Student::Student(const Student& s)
{
	surname = s.surname;
	adress = s.adress;
	group = s.group;
	rojd = s.rojd;
	post = s.post;
	otch = s.otch;
}

// ������ �����
void Student::Get(string surname, string adress, string group, Date rojd, Date post, Date otch)
{
	this->surname = surname;
	this->adress = adress;
	this->group = group;
	this->rojd = rojd;
	this->post = post;
	this->otch = otch;
}

bool operator<(Student& s1, Student& s2) // ���������� ��������� ������
{
	if (s1.surname < s2.surname) // ��������� �� �������
		return true;
	else
		return false;
}

bool operator>(Student& s1, Student& s2) // ���������� ��������� ������
{
	if (s1.surname > s2.surname) // ��������� �������
		return true;
	else
		return false;
}

// �����
ostream& operator<<(ostream& out, Student st)
{
	out << setw(15) << st.surname << setw(9)<<'|'<<setw(13)<<st.rojd.Print()<<'|'<<setw(17)<<st.adress<<setw(8)<<'|'<<setw(8)<<st.group<<setw(1)<<'|'<<setw(13)<<st.post.Print()<<setw(4)<<'|'<<setw(15)<<st.otch.Print()<<setw(3)<<'|'<<endl;
	return out;
}

// ����� � �������� ����
ofstream& operator<<(ofstream& out, const Student& d)
{
	size_t len = d.surname.size(); // ������ ����� ������
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

// ���� �� ��������� �����
ifstream& operator>>(ifstream& in, Student& d)
{
	size_t len;
	in.read((char*)&len, sizeof(size_t));
	if (in.eof()) // �������� �� ����� �����
	{
		return in;
	}
	d.surname.resize(len); // ��������� ����� ������
	in.read((char*)d.surname.data(), len); // ������ ������

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

// ���������
int Student::sravn(const Student n2, int q) // � ����������� �� q ���������� ��� ����������
{
	switch (q)
	{
	case 1:
		if (this->surname > n2.surname) // ��������� �������
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
		if (this->group > n2.group) // ��������� ������
			return 1;
		else
			if (this->group <= n2.group)
				return 0;
		break;
	case 4:
		if (this->adress > n2.adress) // ��������� ������
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

// �����
int Student::search(string x, int q) // � ����������� �� q, ���������� ����� �� ����� ����� ����� ����������
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

int Student::search(Date x, int q) // � ����������� �� q, ���������� ����� �� ����� ����� ����������
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