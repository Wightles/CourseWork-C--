#include "Header_List.h"

// Функия проверяет на наличие ошибок потока
int Prov()
{
	if (cin.fail())
	{
		cin.clear();
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		return 0;
	}
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	if (cin.gcount() > 1) // если мы удалили более одного дополнительного символа
	{
		return 0;
	}
}

// Функция проверяет есть ли в строке числа
bool isValidName(char s[])
{
	int i = 0;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9' || s[i]=='-') { return 0; }
		i++;
	}
}

// Функция ввода
Student insert()
{
	int dd, mm, ss; // q - выбор функции, l - вспомогательная переменная, sv - вспомогательная переменная, dd - дни, mm - месяц, ss - год
	Student a; // Студент
	Date otch, post, rojd; // Дата отчисления, поступления и рождения
	string surname, adress, group; // Фамилия, адрес, группа, строка для поиска и строка для редактирования
	char* A; // Массив символов для записи в строки
	cout << "Фамилия студента: ";
	A = new char[80]; // Выделение памяти под 80 символов
	cin.getline(A, 80); // Ввод строки с пробелами
	surname = A; // Запись символов в строку
	while (surname.size() > 15 || surname.size() == 0 || !isValidName(A))
	{
		cout << "Ошибка. Повторите попытку ввода" << endl << endl;
		cout << "Фамилия студента: ";
		A = new char[80]; // Выделение памяти под 80 символов
		cin.getline(A, 80); // Ввод строки с пробелами
		surname = A; // Запись символов в строку
	}
	delete[] A;

	cout << "Адрес проживания: ";
	A = new char[80];
	cin.getline(A, 80);
	adress = A;
	while (adress.size() > 16 || adress.size() == 0)
	{
		cout << "Ошибка. Повторите попытку ввода" << endl << endl;
		cout << "Адрес проживания: ";
		A = new char[80]; // Выделение памяти под 80 символов
		cin.getline(A, 80); // Ввод строки с пробелами
		adress = A; // Запись символов в строку
	}
	delete[] A;

	cout << "Группа: ";
	A = new char[80];
	cin.getline(A, 80);
	group = A;
	while (group.size() > 9 || group.size() == 0)
	{
		cout << "Ошибка. Повторите попытку ввода" << endl << endl;
		cout << "Группа: ";
		A = new char[80]; // Выделение памяти под 80 символов
		cin.getline(A, 80); // Ввод строки с пробелами
		group = A; // Запись символов в строку
	}
	delete[] A;

	cout << "Дата рождения(ДД ММ ГГГГ): ";
	cin >> dd >> mm >> ss;
	while (!Prov() || dd <= 0 || dd > 31 || mm <= 0 || mm > 12 || ss <= 1900) // Ограничение по дате
	{
		cout << "Ошибка. Повторите попытку ввода" << endl << endl;
		cout << "Дата рождения(ДД ММ ГГГГ): ";
		cin >> dd >> mm >> ss;
	}
	rojd.Get(dd, mm, ss);

	cout << "Дата поступления(ДД ММ ГГГГ): ";
	cin >> dd >> mm >> ss;
	while (!Prov() || dd <= 0 || dd > 31 || mm <= 0 || mm > 12 || ss <= 1900 || !(rojd.Sravn(dd, mm, ss))) // Ограничение по дате
	{
		cout << "Ошибка. Повторите попытку ввода" << endl << endl;
		cout << "Дата поступления(ДД ММ ГГГГ): ";
		cin >> dd >> mm >> ss;
	}
	post.Get(dd, mm, ss);

	cout << "Дата отчисления(ДД ММ ГГГГ или введите 0 0 0, если студент не отчислен): ";
	cin >> dd >> mm >> ss;
	while (!Prov() || dd <= 0 || dd > 31 || mm <= 0 || mm > 12 || ss <= 1990 || !(post.Sravn(dd, mm, ss))) // Ограничение по дате
	{
		if (ss == 0 && dd == 0 && mm == 0)
			break;
		cout << "Ошибка. Повторите попытку ввода" << endl << endl;
		cout << "Дата отчисления(ДД ММ ГГГГ или введите 0 0 0, если студент не отчислен): ";
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
	a.Get("Будзинский", "пер. Шукшина 3", "АВТ-241", rojd.Get(rand()%31,rand()%12,rand()%2002), post.Get(rand() % 31, rand() % 12, rand() % 2002), otch.Get(rand() % 31, rand() % 12, rand() % 2002));
	for (int i = 0; i < 1000; i++)
		list.insertLast(a);
	list.Sort(1,2);

}

int main()
{
	SetConsoleCP(1251); // Задание кодировки для ввода в консоль
	SetConsoleOutputCP(1251); // Задание кодировки для вывода в консоль
	int q, l, sv, dd, mm, ss; // q - выбор функции, l - вспомогательная переменная, sv - вспомогательная переменная, dd - дни, mm - месяц, ss - год
	List list; // Список
	Student a; // Студент
	Date psk, post; // Дата для поиска
	string psk_s, edt; // Cтрока для поиска и строка для редактирования
	char* A; // Массив символов для записи в строки
	while (1)
	{
		q = 0;
		cout << "МЕНЮ" << endl << endl;
		cout << "1 - Добавить студента\n2 - Удалить студента\n3 - Вставка по номеру" << endl;
		cout << "4 - Вывести студента под номером\n5 - Отсортировать список\n6 - Добавить студента с сохранением порядка" << endl;
		cout << "7 - Сохранить список в файл\n8 - Загрузить список из файла\n9 - Поиск\n10 - Вывести список\n11 - Редактирование\n0 - Выход" << endl;
		cout << "Введите число: ";
		cin >> q;
		while (!Prov())
		{
			cout << "Ошибка. Повторите попытку ввода" << endl << endl;
			cout << "Введите число: ";
			cin >> q;
		}
		switch (q)
		{
		case 1:
			system("cls");
			cin.clear();
			cout << "Для продолжения нажмите любую кнопку..\nНажмите 0 для отмены.."<<endl;
			if (_getch() == '0')
			{
				system("cls");
				break;
			}
			system("cls");
			cout << "ДОБАВЛЕНИЕ СТУДЕНТА" << endl << endl;
			a = insert();
			list.insertLast(a);
			cout << "Студент успешно добавлен" << endl;
			cout << "Нажмите любую клавишу.." << endl;
			_getch();
			system("cls");
			break;
		case 2:
			system("cls");
			cin.clear();
			cout << "Для продолжения нажмите любую кнопку..\nНажмите 0 для отмены.." << endl;
			if (_getch() == '0')
			{
				system("cls");
				break;
			}
			system("cls");
			cout << "УДАЛЕНИЕ СТУДЕНТА" << endl << endl;
			list.show_list();
			cout << "Введите номер студента которого нужно удалить: ";
			cin >> l;
			while (!Prov())
			{
				cout << "Ошибка. Повторите попытку ввода" << endl << endl;
				cout << "Введите номер студента которого нужно удалить: ";
				cin >> l;
			}
			list.delete_node(l - 1);
			cout << "Нажмите любую клавишу.." << endl;
			_getch();
			system("cls");
			break;
		case 3:
			system("cls");
			cout << "Для продолжения нажмите любую кнопку..\nНажмите 0 для отмены.." << endl;
			if (_getch() == '0')
			{
				system("cls");
				break;
			}
			system("cls");
			cout << "ВСТАВКА ПО ЛОГИЧЕСКОМУ НОМЕРУ" << endl << endl;
			a = insert();
			list.show_list();
			cout << endl;
			cout << "На какое место поставить студента: ";
			cin >> l;
			while (!Prov() || l<=0)
			{
				cout << "Ошибка. Повторите попытку ввода" << endl << endl;
				cout << "На какое место поставить студента: ";
				cin >> l;
			}
			list.add_logNum(l - 1, a);
			cout << "Нажмите любую клавишу.." << endl;
			_getch();
			system("cls");
			break;
		case 4:
			system("cls");
			cout << "Для продолжения нажмите любую кнопку..\nНажмите 0 для отмены.." << endl;
			if (_getch() == '0')
			{
				system("cls");
				break;
			}
			system("cls");
			cout << "ВЫВОД СТУДЕНТА ПО НОМЕРУ" << endl << endl;
			cout << "Введите номер студента для вывода: ";
			cin >> l;
			while (!Prov())
			{
				cout << "Ошибка. Повторите попытку ввода" << endl << endl;
				cout << "Введите номер студента для вывода: ";
				cin >> l;
			}
			list.extraction(l - 1);
			cout << "Нажмите любую клавишу.." << endl;
			_getch();
			system("cls");
			break;
		case 5:
			system("cls");
			cout << "Для продолжения нажмите любую кнопку..\nНажмите 0 для отмены.." << endl;
			if (_getch() == '0')
			{
				system("cls");
				break;
			}
			system("cls");
			cout << "СОРТИРОВКА СПИСКА" << endl << endl;
			cout << "Выберите критерий сортировки:" << endl;
			cout << "1 - Фамилия\n2 - Дата рождения\n3 - Группа\n4 - Адрес\n5 - Дата поступления\n6 - Дата отчисления\nВведите число: ";
			cin >> q;
			while (!Prov() || q <1 || q>6)
			{
				cout << "Ошибка. Повторите попытку ввода" << endl << endl;
				cout << "Выберите критерий сортировки:" << endl;
				cout << "1 - Фамилия\n2 - Дата рождения\n3 - Группа\n4 - Адрес\n5 - Дата поступления\n6 - Дата отчисления\nВведите число: ";
				cin >> q;
			}
			cout << "\nВыберите как сортировать список:" << endl;
			if (q == 1 || q == 3 || q == 4)
				cout << "1 - В алфавитном порядка\n2 - В обратном алфавитном порядке\nВведите число: ";
			else
				cout << "1 - Убывание\n2 - Возрастание\nВведите число: ";
			cin >> l;
			while (!Prov() || q < 1 || q>6)
			{
				cout << "Ошибка. Повторите попытку ввода" << endl << endl;
				cout << "\nВыберите как сортировать список:" << endl;
				if (q == 1 || q == 3 || q == 4)
					cout << "1 - В алфавитном порядка\n2 - В обратном алфавитном порядке\nВведите число: ";
				else
					cout << "1 - Убывание\n2 - Возрастание\nВведите число: ";
				cin >> l;
			}
			list.Sort(q, l);
			cout << "Список отсортирован" << endl;
			list.show_list();
			cout << "Нажмите любую клавишу.." << endl;
			_getch();
			system("cls");
			break;
		case 6:
			system("cls");
			cout << "Для продолжения нажмите любую кнопку..\nНажмите 0 для отмены.." << endl;
			if (_getch() == '0')
			{
				system("cls");
				break;
			}
			system("cls");
			cout << "ДОБАВЛЕНИЕ СТУДЕНТА С СОХРАНЕНИЕМ ПОРЯДКА" << endl << endl;
			a = insert();
			list.add_logNum_por(a);
			cout << "Нажмите любую клавишу.." << endl;
			_getch();
			system("cls");
			break;
		case 7:
			system("cls");
			cout << "Для продолжения нажмите любую кнопку..\nНажмите 0 для отмены.." << endl;
			if (_getch() == '0')
			{
				system("cls");
				break;
			}
			system("cls");
			cout << "СОХРАНЕНИЕ СПИСКА В ФАЙЛ" << endl << endl;
			list.save_bin();
			cout << "Сохранение успешно" << endl;
			cout << "Нажмите любую клавишу.." << endl;
			_getch();
			system("cls");
			break;
		case 8:
			system("cls");
			cout << "ЗАГРУЗКА СПИСКА ИЗ ФАЙЛА" << endl << endl;
			list.load_bin();
			cout << "Нажмите любую клавишу.." << endl;
			_getch();
			system("cls");
			break;
		case 9:
			system("cls");
			cout << "Для продолжения нажмите любую кнопку..\nНажмите 0 для отмены.." << endl;
			if (_getch() == '0')
			{
				system("cls");
				break;
			}
			system("cls");
			cout << "ПОИСК" << endl << endl;
			cout << "Выберите критерий поиска:" << endl;
			cout << "1 - Фамилия\n2 - Дата рождения\n3 - Группа\n4 - Адрес\n5 - Дата поступления\n6 - Дата отчисления\nВведите число: ";
			cin >> l;
			while (!Prov() || l < 1 || l > 6)
			{
				cout << "Ошибка. Повторите попытку ввода" << endl << endl;
				cout << "Выберите критерий поиска:" << endl;
				cout << "1 - Фамилия\n2 - Дата рождения\n3 - Группа\n4 - Адрес\n5 - Дата поступления\n6 - Дата отчисления\nВведите число: ";
				cin >> l;
			}
			if (l == 1 || l == 3 || l == 4)
			{
				cout << "Введите данные для поиска: ";
				A = new char[80];
				cin.getline(A, 80);
				psk_s = A;
				delete[] A;
				list.search(psk_s, l);
			}
			else
				if (l == 2 || l == 5 || l == 6)
				{
					cout << "Введите данные для поиска(ДД ММ ГГГГ): ";
					cin >> dd >> mm >> ss;
					psk.Get(dd, mm, ss);
					list.search(psk, l);
				}
			cout << "Нажмите любую клавишу.." << endl;
			_getch();
			system("cls");
			break;
		case 10:
			system("cls");
			cout << "СПИСОК СТУДЕНТОВ" << endl;
			list.show_list();
			cout << "Нажмите любую клавишу.." << endl;
			_getch();
			system("cls");
			break;
		case 11:
			system("cls");
			cout << "Для продолжения нажмите любую кнопку..\nНажмите 0 для отмены.." << endl;
			if (_getch() == '0')
			{
				system("cls");
				break;
			}
			system("cls");
			cout << "РЕДАКТИРОВАНИЕ" << endl << endl;
			cout << "Критерии поиска студента для редактирования\n1 - Фамилия\n2 - Группа\nВведите число: ";
			cin >> sv;
			while (!Prov() || sv < 1 || sv > 2)
			{
				cout << "Ошибка. Повторите попытку ввода" << endl << endl;
				cout << "Критерии поиска студента для редактирования\n1 - Фамилия\n2 - Группа\nВведите число: ";
				cin >> sv;
			}
			cout << "Введите данные для поиска: ";
			A = new char[80];
			cin.getline(A, 80);
			psk_s = A;
			delete[] A;
			if (sv == 2)
				sv = 3;
			l = list.search(psk_s, sv);
			if (l == 0)
			{
				cout << "Нажмите любую клавишу.."<<endl;
				_getch();
				system("cls");
				break;
			}
			cout << "Введите номер студента, которого хотите редактировать\nВведите число: ";
			cin >> q;
			while (!Prov() || q < 1)
			{
				cout << "Ошибка. Повторите попытку ввода" << endl << endl;
				cout << "Введите номер студента, которого хотите редактировать\nВведите число: ";
				cin >> q;
			}
			cout << "По какому критерию редактировать\n1 - Фамилия\n2 - Дата рождения\n3 - Группа\n4 - Адрес\n5 - Дата поступления\n6 - Дата отчисления\nВведите число: ";
			cin >> l;
			while (!Prov() || l < 1 || l > 6)
			{
				cout << "Ошибка. Повторите попытку ввода" << endl << endl;
				cout << "По какому критерию редактировать\n1 - Фамилия\n2 - Дата рождения\n3 - Группа\n4 - Адрес\n5 - Дата поступления\n6 - Дата отчисления\nВведите число: ";
				cin >> l;
			}
			cout << "Введите значение, на которое нужно изменить: ";
			if (l == 1 || l == 3 || l == 4)
			{
				A = new char[80]; // Выделение памяти под 80 символов
				cin.getline(A, 80); // Ввод строки с пробелами
				psk_s = A; // Запись символов в строку
				if (l == 1)
				{
					while (!isValidName(A))
					{
						cout << "Ошибка. Повторите попытку ввода" << endl << endl;
						cout << "Введите значение, на которое нужно изменить: ";
						A = new char[80]; // Выделение памяти под 80 символов
						cin.getline(A, 80); // Ввод строки с пробелами
						psk_s = A; // Запись символов в строку
					}
				}
				delete[] A;
				list.edit(q - 1, l, psk_s);
			}
			else
			{
				cin >> dd >> mm >> ss;
				while (!Prov() || dd <= 0 || dd > 31 || mm <= 0 || mm > 12 || ss <= 1990) // Ограничение по дате
				{
					if (ss == 0 && dd == 0 && mm == 0 && l==6)
						break;
					cout << "Ошибка. Повторите попытку ввода" << endl << endl;
					cout << "Введите значение, на которое нужно изменить: ";
					cin >> dd >> mm >> ss;
				}
				post.Get(dd, mm, ss);
				list.edit(q - 1, l, post);
			}
			cout << "Нажмите любую клавишу.." << endl;
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
			cout << "Введите число из списка" << endl;
			cout << "Нажмите любую клавишу.." << endl;
			_getch();
			system("cls");
			break;
		}
	}
}