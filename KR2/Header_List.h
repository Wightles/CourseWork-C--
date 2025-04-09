#include "Header_Student.h"

// ����� ������
class List
{
private:
	class Node // ��������� ����� ���� ������
	{
	public:
		Student field;
		Node* next;
		Node* prev;
	};
	Node* head; // ������ ������
	Node* tail; // ����� ������
	int size; // ������ ������
public:
	List(); // ����������� �� ���������
	~List(); // ����������
	void insertLast(Student); // ���������� � ����� ������
	void show_list(); // ����� ����� ������
	void delete_node(int); // �������� ���� ������
	void extraction(int); // ���������� �� ����������� ������
	void add_logNum(int, Student); // ���������� �� ����������� ������
	void add_logNum_por(Student); // ���������� � ����������� �������
	void Sort(int, int); // ����������
	int search(string, int); // ����� �� �������
	void search(Date, int); // ����� �� ����
	void save_bin(); // ���������� � �������� ����
	void load_bin(); // �������� �� ��������� �����
	void edit(int, int, string);
	void edit(int, int, Date);
};

// ����������� �� ���������
List::List()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

// ����������
List::~List()
{
	while (head != NULL) // ���� ������ ������ �� ����� ����� ����
	{
		Node* tmp = head; // ������ ������ � ����������
		head = head->next; // ���������� ������ �� ��������� �������
		delete tmp; // �������� ����� ���������� ����������
	}
}

// ���������� � ����� ������
void List::insertLast(Student value)
{
	Node* temp = new Node;
	if (head == NULL) // ���� ������ ���������� ����
	{
		temp->prev = NULL; // �� �� ��� �� ���������
		temp->next = NULL; // �� �� ��� �� ���������
		temp->field = value; // ������ ������
		head = temp; // ������ � ������
		tail = temp; // ������ � �����
		size++; // ���������� ������� ������
	}
	else // ���� ������ �� ������
	{
		tail->next = temp; // ����� ��������� �� ����������� �������
		temp->field = value; // ������ ������ 
		temp->next = NULL; // ���������� ����� ������������ �������� ���
		temp->prev = tail; // ���������� �������� �������
		tail = temp; // ���������� �����
		size++; // ���������� ������� ������
	}
}

// ����� ����� ������
void List::show_list()
{
	int i = 1; // ���������� �����
	cout << '|' << setw(5) << "�����" << '|' << setw(15) << "�������" << setw(9) << '|' << setw(13) << "���� ��������" << '|' << setw(15) << "�����" << setw(10) << '|' << setw(7) << "������" << setw(2) << '|' << setw(16) << "���� �����������" << '|' << setw(17) << "���� ����������" << '|' << endl;
	for (Node* current = head; current; current = current->next) // �� ������ � �� ������
	{
		cout <<'|'<<setw(3)<< i <<setw(3)<<'|'<< current->field; // �����
		i++; // ���������� ����������� ������
	}
}

// �������� ���� �� ������
void List::delete_node(int idx)
{
	Node* q = new Node;
	for (q = head; q != nullptr && idx != 0; q = q->next, idx--); // ������������� � ���������� ��������

	if (q == nullptr) // ��� ������ ��������
	{
		cout << "������ �������� � ������ ���" << endl;
		return;
	}
	if (q->next == nullptr)
	{
		q = tail->prev;
		tail = q;
		if (this->tail == nullptr)
		{
			head = NULL;
			delete q;
			size--;
			cout << "������� ������� �����" << endl;
			return;
		}
		q = tail->next;
		tail->next = nullptr;
		delete q;
		size--;
		cout << "������� ������� �����" << endl;
		return;
	}
	if (q->prev == nullptr) // �������� �������
		head = q->next; // ��������� ���������
	else    
		q->prev->next = q->next; // ��������� ��� ����������� ����� ���������� �� �������
	if (q->next != nullptr) // �������� �� ����������
		q->next->prev = q->prev; // ���������� ��� ���������� ����� ����������� ��������
	delete q;
	size--; // ���������� ������� ������
	cout << "������� ������� �����" << endl;
}

// ���������� �� ����������� ������
void List::extraction(int idx)
{
	if (idx >= size || idx < 0) // ���� ������� ������ ������ ������� ������ ��� ������ 0
	{
		cout << "������ �������� ���" << endl;
		return;
	}
	cout << '|' << setw(5) << "�����" << '|' << setw(15) << "�������" << setw(9) << '|' << setw(13) << "���� ��������" << '|' << setw(15) << "�����" << setw(10) << '|' << setw(7) << "������" << setw(2) << '|' << setw(16) << "���� �����������" << '|' << setw(17) << "���� ����������" << '|' << endl;
	Node* q;
	int i = 1;
	for (q = head; q != nullptr && idx != 0; q = q->next, idx--, i++); // ������������� � ��������
	cout << '|' << setw(3) << i << setw(3) << '|' << q->field; // ����� ��������
}

// ���������� �� ����������� ������
void List::add_logNum(int idx, Student x)
{
	size++;
	Node* q, *p = new Node; // ����� ������� ������
	p->field = x;
	p->prev = p->next = NULL;
	for (q = head; q != nullptr && idx != 0; q = q->next, idx--); // ����� ����� ���������
	if (q == NULL) //��������� � ����� ������
	{
		insertLast(x);
		cout << "������� ������� ��������" << endl;
		return;
	}
	p->next = q; // ��������� �� ����� ����� ��������
	p->prev = q->prev; // ���������� ������ ����� ����������� ��������
	if (q->prev == NULL) // ��������� � ������ ������
		head = p;
	else // ��������� � ��������
		q->prev->next = p; // ��������� �� ���������� ����� ������
	q->prev = p; // ���������� �������� ����� ������ 
	cout << "������� ������� ��������" << endl;
}

// ��������� � ����������� �������
void List::add_logNum_por(Student x)
{
	size++;
	Node* q, *p = new Node; // ����� ������� ������
	p->field = x;
	p->prev = p->next = NULL;
	for (q = head; q != NULL && x > q->field; q = q->next); // ����� ����� ���������
	if (q == NULL) //��������� � ����� ������
	{
		insertLast(x);
		cout << "������� ������� ��������" << endl;
		return;
	}
	p->next = q; // ��������� �� ����� ����� ��������
	p->prev = q->prev; // ���������� ������ ����� ����������� ��������
	if (q->prev == NULL) // ��������� � ������ ������
		head = p;
	else // ��������� � ��������
		q->prev->next = p; // ��������� �� ���������� ����� ������
	q->prev = p; // ���������� �������� ����� ������ 
	cout << "������� ������� ��������" << endl;
}

// ����������
// q - �������� ����������(1-�������, 2-���� ��������, 3-������, 4-�����, 5-���� �����������, 6-���� ����������), v - ��������(1) ��� �����������(2)
void List::Sort(int q, int v)
{
	Node* p = head; // ���������� ������ �������
	Student tmp; // ������ �������, ��� ���������� ���������
	switch (v)
	{
	case 1: // ��������
		for (Node* i = p; i != NULL && i->next != NULL; i = i->next) // ������� ���� ���������
		{
			for (Node* j = p; j->next != NULL; j = j->next) 
			{
				if (!(j->next->field.sravn(j->field, q))) // ��������� ���������� � �������
				{
					tmp = j->next->field;
					j->next->field = j->field;
					j->field = tmp;
				}
			}
		}
		break;
	case 2: // �����������
		for (Node* i = p; i != NULL && i->next != NULL; i = i->next)
		{
			for (Node* j = p; j->next != NULL; j = j->next)
			{
				if (j->next->field.sravn(j->field, q))
				{
					tmp = j->next->field;
					j->next->field = j->field;
					j->field = tmp;
				}
			}
		}
		break;
	default:
		break;
	}
}

// ����� (p: 1-�� �������, 2-�� ���� ��������, 3-�� ������, 4-�� ������, 5-�� ���� �����������, 6-�� ���� ����������)
int List::search(string key, int p) // ����� �� �������
{
	Node* q;
	int i = 1, count=0;
	cout << '|' << setw(5) << "�����" << '|' << setw(15) << "�������" << setw(9) << '|' << setw(13) << "���� ��������" << '|' << setw(15) << "�����" << setw(10) << '|' << setw(7) << "������" << setw(2) << '|' << setw(16) << "���� �����������" << '|' << setw(17) << "���� ����������" << '|' << endl;
	for (q = head; q != nullptr; q = q->next)
	{
		if (q->field.search(key, p))
		{// ���� ������ ���������, �� ������� � �������
			cout << '|' << setw(3) << i << setw(3) << '|' << q->field;
			count++;
		}
		i++;
	}
	if (count == 0)
		cout << "������ �� �������" << endl;
	return count;
}

// ����� (p: 1-�� �������, 2-�� ���� ��������, 3-�� ������, 4-�� ������, 5-�� ���� �����������, 6-�� ���� ����������)
void List::search(Date key, int p) // ����� �� ����
{
	Node* q;
	int i = 1, count=0;
	cout << '|' << setw(5) << "�����" << '|' << setw(15) << "�������" << setw(9) << '|' << setw(13) << "���� ��������" << '|' << setw(15) << "�����" << setw(10) << '|' << setw(7) << "������" << setw(2) << '|' << setw(16) << "���� �����������" << '|' << setw(17) << "���� ����������" << '|' << endl;
	for (q = head; q != nullptr; q = q->next)
	{
		if (q->field.search(key, p)) // ���� ��������� ����, �� ������� �� �����
		{
			cout << '|' << setw(3) << i << setw(3) << '|' << q->field;
			count++;
		}
		i++;
	}
	if (count == 0)
		cout << "������ �� �������" << endl;
}

// ���������� � �������� ����
void List::save_bin()
{
	ofstream out("List.bin", ios::binary); // ������� ����� ������ � ����
	Node* q;
	for (q = head; q != nullptr; q = q->next) // ��������� ��� �������� � �������� �� � �����
		out << q->field;
	out.close(); // ������� ����
}

void List::load_bin()
{
	ifstream in("List.bin", ios::binary); // ������� ����� ����� �� �����
	if (!in) // ���� �� ������� ������� ����
	{
		cout << "�� ������� ������� ����" << endl;
		return;
	}
	Student p;
	while (!in.eof()) // ���� �� ����� �����, ��������� ������ � ��������� �� � ������
	{
		in >> p;
		if (in.eof())
			break;
		this->insertLast(p);
	}
	in.close(); // ������� ����� �����
	cout << "������ ������� ��������" << endl;
}

void List::edit(int idx, int l, string str1)
{
	Node* q;
	for (q = head; q != nullptr && idx != 0; q = q->next, idx--);
	if (q == nullptr)
	{
		cout << "������ �������� ��� � ������" << endl;
		return;
	}
	q->field.edit(str1, l);
	cout << "�������������� �������" << endl;
}

void List::edit(int idx, int l, Date str1)
{
	Node* q;
	for (q = head; q != nullptr && idx != 0; q = q->next, idx--);
	if (q == nullptr)
	{
		cout << "������ �������� ��� � ������" << endl;
		return;
	}
	q->field.edit(str1, l);
	cout << "�������������� �������" << endl;
}