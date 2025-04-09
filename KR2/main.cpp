#include "Header_List.h"

// ������ ��������� �� ������� ������ ������
int Prov()
{
	if (cin.fail())
	{
		cin.clear();
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		return 0;
	}
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	if (cin.gcount() > 1) // ���� �� ������� ����� ������ ��������������� �������
	{
		return 0;
	}
}

// ������� ��������� ���� �� � ������ �����
bool isValidName(char s[])
{
	int i = 0;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9' || s[i]=='-') { return 0; }
		i++;
	}
}

// ������� �����
Student insert()
{
	int dd, mm, ss; // q - ����� �������, l - ��������������� ����������, sv - ��������������� ����������, dd - ���, mm - �����, ss - ���
	Student a; // �������
	Date otch, post, rojd; // ���� ����������, ����������� � ��������
	string surname, adress, group; // �������, �����, ������, ������ ��� ������ � ������ ��� ��������������
	char* A; // ������ �������� ��� ������ � ������
	cout << "������� ��������: ";
	A = new char[80]; // ��������� ������ ��� 80 ��������
	cin.getline(A, 80); // ���� ������ � ���������
	surname = A; // ������ �������� � ������
	while (surname.size() > 15 || surname.size() == 0 || !isValidName(A))
	{
		cout << "������. ��������� ������� �����" << endl << endl;
		cout << "������� ��������: ";
		A = new char[80]; // ��������� ������ ��� 80 ��������
		cin.getline(A, 80); // ���� ������ � ���������
		surname = A; // ������ �������� � ������
	}
	delete[] A;

	cout << "����� ����������: ";
	A = new char[80];
	cin.getline(A, 80);
	adress = A;
	while (adress.size() > 16 || adress.size() == 0)
	{
		cout << "������. ��������� ������� �����" << endl << endl;
		cout << "����� ����������: ";
		A = new char[80]; // ��������� ������ ��� 80 ��������
		cin.getline(A, 80); // ���� ������ � ���������
		adress = A; // ������ �������� � ������
	}
	delete[] A;

	cout << "������: ";
	A = new char[80];
	cin.getline(A, 80);
	group = A;
	while (group.size() > 9 || group.size() == 0)
	{
		cout << "������. ��������� ������� �����" << endl << endl;
		cout << "������: ";
		A = new char[80]; // ��������� ������ ��� 80 ��������
		cin.getline(A, 80); // ���� ������ � ���������
		group = A; // ������ �������� � ������
	}
	delete[] A;

	cout << "���� ��������(�� �� ����): ";
	cin >> dd >> mm >> ss;
	while (!Prov() || dd <= 0 || dd > 31 || mm <= 0 || mm > 12 || ss <= 1900) // ����������� �� ����
	{
		cout << "������. ��������� ������� �����" << endl << endl;
		cout << "���� ��������(�� �� ����): ";
		cin >> dd >> mm >> ss;
	}
	rojd.Get(dd, mm, ss);

	cout << "���� �����������(�� �� ����): ";
	cin >> dd >> mm >> ss;
	while (!Prov() || dd <= 0 || dd > 31 || mm <= 0 || mm > 12 || ss <= 1900 || !(rojd.Sravn(dd, mm, ss))) // ����������� �� ����
	{
		cout << "������. ��������� ������� �����" << endl << endl;
		cout << "���� �����������(�� �� ����): ";
		cin >> dd >> mm >> ss;
	}
	post.Get(dd, mm, ss);

	cout << "���� ����������(�� �� ���� ��� ������� 0 0 0, ���� ������� �� ��������): ";
	cin >> dd >> mm >> ss;
	while (!Prov() || dd <= 0 || dd > 31 || mm <= 0 || mm > 12 || ss <= 1990 || !(post.Sravn(dd, mm, ss))) // ����������� �� ����
	{
		if (ss == 0 && dd == 0 && mm == 0)
			break;
		cout << "������. ��������� ������� �����" << endl << endl;
		cout << "���� ����������(�� �� ���� ��� ������� 0 0 0, ���� ������� �� ��������): ";
		cin >> dd >> mm >> ss;
	}
	otch.Get(dd, mm, ss);
	a.Get(surname, adress, group, rojd, post, otch);
	return a;
}

void randm(List& list)
{
	Student a;
	Date rojd, post, otch;
	a.Get("����������", "���. ������� 3", "���-241", rojd.Get(rand()%31,rand()%12,rand()%2002), post.Get(rand() % 31, rand() % 12, rand() % 2002), otch.Get(rand() % 31, rand() % 12, rand() % 2002));
	for (int i = 0; i < 1000; i++)
		list.insertLast(a);
	list.Sort(1,2);

}

int main()
{
	SetConsoleCP(1251); // ������� ��������� ��� ����� � �������
	SetConsoleOutputCP(1251); // ������� ��������� ��� ������ � �������
	int q, l, sv, dd, mm, ss; // q - ����� �������, l - ��������������� ����������, sv - ��������������� ����������, dd - ���, mm - �����, ss - ���
	List list; // ������
	Student a; // �������
	Date psk, post; // ���� ��� ������
	string psk_s, edt; // C����� ��� ������ � ������ ��� ��������������
	char* A; // ������ �������� ��� ������ � ������
	while (1)
	{
		q = 0;
		cout << "����" << endl << endl;
		cout << "1 - �������� ��������\n2 - ������� ��������\n3 - ������� �� ������" << endl;
		cout << "4 - ������� �������� ��� �������\n5 - ������������� ������\n6 - �������� �������� � ����������� �������" << endl;
		cout << "7 - ��������� ������ � ����\n8 - ��������� ������ �� �����\n9 - �����\n10 - ������� ������\n11 - ��������������\n0 - �����" << endl;
		cout << "������� �����: ";
		cin >> q;
		while (!Prov())
		{
			cout << "������. ��������� ������� �����" << endl << endl;
			cout << "������� �����: ";
			cin >> q;
		}
		switch (q)
		{
		case 1:
			system("cls");
			cin.clear();
			cout << "��� ����������� ������� ����� ������..\n������� 0 ��� ������.."<<endl;
			if (_getch() == '0')
			{
				system("cls");
				break;
			}
			system("cls");
			cout << "���������� ��������" << endl << endl;
			a = insert();
			list.insertLast(a);
			cout << "������� ������� ��������" << endl;
			cout << "������� ����� �������.." << endl;
			_getch();
			system("cls");
			break;
		case 2:
			system("cls");
			cin.clear();
			cout << "��� ����������� ������� ����� ������..\n������� 0 ��� ������.." << endl;
			if (_getch() == '0')
			{
				system("cls");
				break;
			}
			system("cls");
			cout << "�������� ��������" << endl << endl;
			list.show_list();
			cout << "������� ����� �������� �������� ����� �������: ";
			cin >> l;
			while (!Prov())
			{
				cout << "������. ��������� ������� �����" << endl << endl;
				cout << "������� ����� �������� �������� ����� �������: ";
				cin >> l;
			}
			list.delete_node(l - 1);
			cout << "������� ����� �������.." << endl;
			_getch();
			system("cls");
			break;
		case 3:
			system("cls");
			cout << "��� ����������� ������� ����� ������..\n������� 0 ��� ������.." << endl;
			if (_getch() == '0')
			{
				system("cls");
				break;
			}
			system("cls");
			cout << "������� �� ����������� ������" << endl << endl;
			a = insert();
			list.show_list();
			cout << endl;
			cout << "�� ����� ����� ��������� ��������: ";
			cin >> l;
			while (!Prov() || l<=0)
			{
				cout << "������. ��������� ������� �����" << endl << endl;
				cout << "�� ����� ����� ��������� ��������: ";
				cin >> l;
			}
			list.add_logNum(l - 1, a);
			cout << "������� ����� �������.." << endl;
			_getch();
			system("cls");
			break;
		case 4:
			system("cls");
			cout << "��� ����������� ������� ����� ������..\n������� 0 ��� ������.." << endl;
			if (_getch() == '0')
			{
				system("cls");
				break;
			}
			system("cls");
			cout << "����� �������� �� ������" << endl << endl;
			cout << "������� ����� �������� ��� ������: ";
			cin >> l;
			while (!Prov())
			{
				cout << "������. ��������� ������� �����" << endl << endl;
				cout << "������� ����� �������� ��� ������: ";
				cin >> l;
			}
			list.extraction(l - 1);
			cout << "������� ����� �������.." << endl;
			_getch();
			system("cls");
			break;
		case 5:
			system("cls");
			cout << "��� ����������� ������� ����� ������..\n������� 0 ��� ������.." << endl;
			if (_getch() == '0')
			{
				system("cls");
				break;
			}
			system("cls");
			cout << "���������� ������" << endl << endl;
			cout << "�������� �������� ����������:" << endl;
			cout << "1 - �������\n2 - ���� ��������\n3 - ������\n4 - �����\n5 - ���� �����������\n6 - ���� ����������\n������� �����: ";
			cin >> q;
			while (!Prov() || q <1 || q>6)
			{
				cout << "������. ��������� ������� �����" << endl << endl;
				cout << "�������� �������� ����������:" << endl;
				cout << "1 - �������\n2 - ���� ��������\n3 - ������\n4 - �����\n5 - ���� �����������\n6 - ���� ����������\n������� �����: ";
				cin >> q;
			}
			cout << "\n�������� ��� ����������� ������:" << endl;
			if (q == 1 || q == 3 || q == 4)
				cout << "1 - � ���������� �������\n2 - � �������� ���������� �������\n������� �����: ";
			else
				cout << "1 - ��������\n2 - �����������\n������� �����: ";
			cin >> l;
			while (!Prov() || q < 1 || q>6)
			{
				cout << "������. ��������� ������� �����" << endl << endl;
				cout << "\n�������� ��� ����������� ������:" << endl;
				if (q == 1 || q == 3 || q == 4)
					cout << "1 - � ���������� �������\n2 - � �������� ���������� �������\n������� �����: ";
				else
					cout << "1 - ��������\n2 - �����������\n������� �����: ";
				cin >> l;
			}
			list.Sort(q, l);
			cout << "������ ������������" << endl;
			list.show_list();
			cout << "������� ����� �������.." << endl;
			_getch();
			system("cls");
			break;
		case 6:
			system("cls");
			cout << "��� ����������� ������� ����� ������..\n������� 0 ��� ������.." << endl;
			if (_getch() == '0')
			{
				system("cls");
				break;
			}
			system("cls");
			cout << "���������� �������� � ����������� �������" << endl << endl;
			a = insert();
			list.add_logNum_por(a);
			cout << "������� ����� �������.." << endl;
			_getch();
			system("cls");
			break;
		case 7:
			system("cls");
			cout << "��� ����������� ������� ����� ������..\n������� 0 ��� ������.." << endl;
			if (_getch() == '0')
			{
				system("cls");
				break;
			}
			system("cls");
			cout << "���������� ������ � ����" << endl << endl;
			list.save_bin();
			cout << "���������� �������" << endl;
			cout << "������� ����� �������.." << endl;
			_getch();
			system("cls");
			break;
		case 8:
			system("cls");
			cout << "�������� ������ �� �����" << endl << endl;
			list.load_bin();
			cout << "������� ����� �������.." << endl;
			_getch();
			system("cls");
			break;
		case 9:
			system("cls");
			cout << "��� ����������� ������� ����� ������..\n������� 0 ��� ������.." << endl;
			if (_getch() == '0')
			{
				system("cls");
				break;
			}
			system("cls");
			cout << "�����" << endl << endl;
			cout << "�������� �������� ������:" << endl;
			cout << "1 - �������\n2 - ���� ��������\n3 - ������\n4 - �����\n5 - ���� �����������\n6 - ���� ����������\n������� �����: ";
			cin >> l;
			while (!Prov() || l < 1 || l > 6)
			{
				cout << "������. ��������� ������� �����" << endl << endl;
				cout << "�������� �������� ������:" << endl;
				cout << "1 - �������\n2 - ���� ��������\n3 - ������\n4 - �����\n5 - ���� �����������\n6 - ���� ����������\n������� �����: ";
				cin >> l;
			}
			if (l == 1 || l == 3 || l == 4)
			{
				cout << "������� ������ ��� ������: ";
				A = new char[80];
				cin.getline(A, 80);
				psk_s = A;
				delete[] A;
				list.search(psk_s, l);
			}
			else
				if (l == 2 || l == 5 || l == 6)
				{
					cout << "������� ������ ��� ������(�� �� ����): ";
					cin >> dd >> mm >> ss;
					psk.Get(dd, mm, ss);
					list.search(psk, l);
				}
			cout << "������� ����� �������.." << endl;
			_getch();
			system("cls");
			break;
		case 10:
			system("cls");
			cout << "������ ���������" << endl;
			list.show_list();
			cout << "������� ����� �������.." << endl;
			_getch();
			system("cls");
			break;
		case 11:
			system("cls");
			cout << "��� ����������� ������� ����� ������..\n������� 0 ��� ������.." << endl;
			if (_getch() == '0')
			{
				system("cls");
				break;
			}
			system("cls");
			cout << "��������������" << endl << endl;
			cout << "�������� ������ �������� ��� ��������������\n1 - �������\n2 - ������\n������� �����: ";
			cin >> sv;
			while (!Prov() || sv < 1 || sv > 2)
			{
				cout << "������. ��������� ������� �����" << endl << endl;
				cout << "�������� ������ �������� ��� ��������������\n1 - �������\n2 - ������\n������� �����: ";
				cin >> sv;
			}
			cout << "������� ������ ��� ������: ";
			A = new char[80];
			cin.getline(A, 80);
			psk_s = A;
			delete[] A;
			if (sv == 2)
				sv = 3;
			l = list.search(psk_s, sv);
			if (l == 0)
			{
				cout << "������� ����� �������.."<<endl;
				_getch();
				system("cls");
				break;
			}
			cout << "������� ����� ��������, �������� ������ �������������\n������� �����: ";
			cin >> q;
			while (!Prov() || q < 1)
			{
				cout << "������. ��������� ������� �����" << endl << endl;
				cout << "������� ����� ��������, �������� ������ �������������\n������� �����: ";
				cin >> q;
			}
			cout << "�� ������ �������� �������������\n1 - �������\n2 - ���� ��������\n3 - ������\n4 - �����\n5 - ���� �����������\n6 - ���� ����������\n������� �����: ";
			cin >> l;
			while (!Prov() || l < 1 || l > 6)
			{
				cout << "������. ��������� ������� �����" << endl << endl;
				cout << "�� ������ �������� �������������\n1 - �������\n2 - ���� ��������\n3 - ������\n4 - �����\n5 - ���� �����������\n6 - ���� ����������\n������� �����: ";
				cin >> l;
			}
			cout << "������� ��������, �� ������� ����� ��������: ";
			if (l == 1 || l == 3 || l == 4)
			{
				A = new char[80]; // ��������� ������ ��� 80 ��������
				cin.getline(A, 80); // ���� ������ � ���������
				psk_s = A; // ������ �������� � ������
				if (l == 1)
				{
					while (!isValidName(A))
					{
						cout << "������. ��������� ������� �����" << endl << endl;
						cout << "������� ��������, �� ������� ����� ��������: ";
						A = new char[80]; // ��������� ������ ��� 80 ��������
						cin.getline(A, 80); // ���� ������ � ���������
						psk_s = A; // ������ �������� � ������
					}
				}
				delete[] A;
				list.edit(q - 1, l, psk_s);
			}
			else
			{
				cin >> dd >> mm >> ss;
				while (!Prov() || dd <= 0 || dd > 31 || mm <= 0 || mm > 12 || ss <= 1990) // ����������� �� ����
				{
					if (ss == 0 && dd == 0 && mm == 0 && l==6)
						break;
					cout << "������. ��������� ������� �����" << endl << endl;
					cout << "������� ��������, �� ������� ����� ��������: ";
					cin >> dd >> mm >> ss;
				}
				post.Get(dd, mm, ss);
				list.edit(q - 1, l, post);
			}
			cout << "������� ����� �������.." << endl;
			_getch();
			system("cls");
			break;
		case 12:
			randm(list);
			break;
		case 0:
			exit(0);
			break;
		default:
			cout << "������� ����� �� ������" << endl;
			cout << "������� ����� �������.." << endl;
			_getch();
			system("cls");
			break;
		}
	}
}