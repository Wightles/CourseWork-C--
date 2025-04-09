#include "Header_Student.h"

// Класс списка
class List
{
private:
	class Node // Вложенный класс узла списка
	{
	public:
		Student field;
		Node* next;
		Node* prev;
	};
	Node* head; // Начало списка
	Node* tail; // Конец списка
	int size; // Размер списка
public:
	List(); // Конструктор по умолчанию
	~List(); // Деструктор
	void insertLast(Student); // Добавление в конец списка
	void show_list(); // Вывод всего списка
	void delete_node(int); // Удаление узла списка
	void extraction(int); // Извлечение по логическому номеру
	void add_logNum(int, Student); // Добавление по логическому номеру
	void add_logNum_por(Student); // Добавление с сохранением порядка
	void Sort(int, int); // Сортировка
	int search(string, int); // Поиск по строкам
	void search(Date, int); // Поиск по дате
	void save_bin(); // Сохранение в бинарный файл
	void load_bin(); // Загрузка из бинарного файла
	void edit(int, int, string);
	void edit(int, int, Date);
};

// Конструктор по умолчанию
List::List()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

// Деструктор
List::~List()
{
	while (head != NULL) // Пока начало списка не будет равно нулю
	{
		Node* tmp = head; // Запись начала в переменную
		head = head->next; // Перезапись головы на следующий элемент
		delete tmp; // Удаление ранее записанной переменной
	}
}

// Добавление в конец списка
void List::insertLast(Student value)
{
	Node* temp = new Node;
	if (head == NULL) // Если список изначально пуст
	{
		temp->prev = NULL; // Ни на что не указывает
		temp->next = NULL; // Ни на что не указывает
		temp->field = value; // Запись данных
		head = temp; // Запись в начало
		tail = temp; // Запись в конец
		size++; // Увеличение размера списка
	}
	else // Если список не пустой
	{
		tail->next = temp; // Конец указывает на добавляемый элемент
		temp->field = value; // Запись данных 
		temp->next = NULL; // Следующего после добавленного элемента нет
		temp->prev = tail; // Предыдущий является хвостом
		tail = temp; // Перезапись конца
		size++; // Увеличение размера списка
	}
}

// Вывод всего списка
void List::show_list()
{
	int i = 1; // Порядковый номер
	cout << '|' << setw(5) << "Номер" << '|' << setw(15) << "Фамилия" << setw(9) << '|' << setw(13) << "Дата рождения" << '|' << setw(15) << "Адрес" << setw(10) << '|' << setw(7) << "Группа" << setw(2) << '|' << setw(16) << "Дата поступления" << '|' << setw(17) << "Дата отчисления" << '|' << endl;
	for (Node* current = head; current; current = current->next) // От головы и до хвоста
	{
		cout <<'|'<<setw(3)<< i <<setw(3)<<'|'<< current->field; // Вывод
		i++; // Увеличение порядкового номера
	}
}

// Удаление узла из списка
void List::delete_node(int idx)
{
	Node* q = new Node;
	for (q = head; q != nullptr && idx != 0; q = q->next, idx--); // Передвигаемся к удаляемому элементу

	if (q == nullptr) // Нет такого элемента
	{
		cout << "Такого студента в списке нет" << endl;
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
			cout << "Студент успешно удалён" << endl;
			return;
		}
		q = tail->next;
		tail->next = nullptr;
		delete q;
		size--;
		cout << "Студент успешно удалён" << endl;
		return;
	}
	if (q->prev == nullptr) // Удаление первого
		head = q->next; // Коррекция заголовка
	else    
		q->prev->next = q->next; // Следующий для предыдущего равен следующему за текущим
	if (q->next != nullptr) // Удаление не последнего
		q->next->prev = q->prev; // Предыдущий для следующего равен предыдущему текущего
	delete q;
	size--; // Уменьшение размера списка
	cout << "Студент успешно удалён" << endl;
}

// Извлечение по логическому номеру
void List::extraction(int idx)
{
	if (idx >= size || idx < 0) // Если введёный индекс больше размера списка или меньше 0
	{
		cout << "Такого студента нет" << endl;
		return;
	}
	cout << '|' << setw(5) << "Номер" << '|' << setw(15) << "Фамилия" << setw(9) << '|' << setw(13) << "Дата рождения" << '|' << setw(15) << "Адрес" << setw(10) << '|' << setw(7) << "Группа" << setw(2) << '|' << setw(16) << "Дата поступления" << '|' << setw(17) << "Дата отчисления" << '|' << endl;
	Node* q;
	int i = 1;
	for (q = head; q != nullptr && idx != 0; q = q->next, idx--, i++); // Передвигаемся к элементу
	cout << '|' << setw(3) << i << setw(3) << '|' << q->field; // Вывод элемента
}

// Добавление по логическому номеру
void List::add_logNum(int idx, Student x)
{
	size++;
	Node* q, *p = new Node; // Новый элемент списка
	p->field = x;
	p->prev = p->next = NULL;
	for (q = head; q != nullptr && idx != 0; q = q->next, idx--); // Поиск места включения
	if (q == NULL) //Включение в конец списка
	{
		insertLast(x);
		cout << "Студент успешно добавлен" << endl;
		return;
	}
	p->next = q; // Следующий за новым равен текущему
	p->prev = q->prev; // Предыдущий нового равен предыдущему текущего
	if (q->prev == NULL) // Включение в начало списка
		head = p;
	else // Включение в середину
		q->prev->next = p; // Следующий за предыдущим равен новому
	q->prev = p; // Предыдущий текущего равен новому 
	cout << "Студент успешно добавлен" << endl;
}

// Включение с сохранением порядка
void List::add_logNum_por(Student x)
{
	size++;
	Node* q, *p = new Node; // Новый элемент списка
	p->field = x;
	p->prev = p->next = NULL;
	for (q = head; q != NULL && x > q->field; q = q->next); // Поиск места включения
	if (q == NULL) //Включение в конец списка
	{
		insertLast(x);
		cout << "Студент успешно добавлен" << endl;
		return;
	}
	p->next = q; // Следующий за новым равен текущему
	p->prev = q->prev; // Предыдущий нового равен предыдущему текущего
	if (q->prev == NULL) // Включение в начало списка
		head = p;
	else // Включение в середину
		q->prev->next = p; // Следующий за предыдущим равен новому
	q->prev = p; // Предыдущий текущего равен новому 
	cout << "Студент успешно добавлен" << endl;
}

// Сортировка
// q - критерий сортировки(1-Фамилия, 2-Дата рождения, 3-Группа, 4-Адрес, 5-Дата поступления, 6-Дата отчисления), v - убывание(1) или возрастание(2)
void List::Sort(int q, int v)
{
	Node* p = head; // Записываем первый элемент
	Student tmp; // Третий элемент, для сортировки пузырьком
	switch (v)
	{
	case 1: // Убывание
		for (Node* i = p; i != NULL && i->next != NULL; i = i->next) // Перебор всех элементов
		{
			for (Node* j = p; j->next != NULL; j = j->next) 
			{
				if (!(j->next->field.sravn(j->field, q))) // Сравнение следующего с текущим
				{
					tmp = j->next->field;
					j->next->field = j->field;
					j->field = tmp;
				}
			}
		}
		break;
	case 2: // Возрастание
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

// Поиск (p: 1-По фамилии, 2-По дате рождения, 3-По группе, 4-По адресу, 5-По дате поступления, 6-По дате отчисления)
int List::search(string key, int p) // Поиск по строкам
{
	Node* q;
	int i = 1, count=0;
	cout << '|' << setw(5) << "Номер" << '|' << setw(15) << "Фамилия" << setw(9) << '|' << setw(13) << "Дата рождения" << '|' << setw(15) << "Адрес" << setw(10) << '|' << setw(7) << "Группа" << setw(2) << '|' << setw(16) << "Дата поступления" << '|' << setw(17) << "Дата отчисления" << '|' << endl;
	for (q = head; q != nullptr; q = q->next)
	{
		if (q->field.search(key, p))
		{// Если строки совпадают, то вывести в консоль
			cout << '|' << setw(3) << i << setw(3) << '|' << q->field;
			count++;
		}
		i++;
	}
	if (count == 0)
		cout << "Ничего не найдено" << endl;
	return count;
}

// Поиск (p: 1-По фамилии, 2-По дате рождения, 3-По группе, 4-По адресу, 5-По дате поступления, 6-По дате отчисления)
void List::search(Date key, int p) // Поиск по дате
{
	Node* q;
	int i = 1, count=0;
	cout << '|' << setw(5) << "Номер" << '|' << setw(15) << "Фамилия" << setw(9) << '|' << setw(13) << "Дата рождения" << '|' << setw(15) << "Адрес" << setw(10) << '|' << setw(7) << "Группа" << setw(2) << '|' << setw(16) << "Дата поступления" << '|' << setw(17) << "Дата отчисления" << '|' << endl;
	for (q = head; q != nullptr; q = q->next)
	{
		if (q->field.search(key, p)) // Если совпадает дата, то вывести на экран
		{
			cout << '|' << setw(3) << i << setw(3) << '|' << q->field;
			count++;
		}
		i++;
	}
	if (count == 0)
		cout << "Ничего не найдено" << endl;
}

// Сохранение в бинарный файл
void List::save_bin()
{
	ofstream out("List.bin", ios::binary); // Открыть поток вывода в файл
	Node* q;
	for (q = head; q != nullptr; q = q->next) // Перебрать все элементы и записать их в поток
		out << q->field;
	out.close(); // Закрыть файл
}

void List::load_bin()
{
	ifstream in("List.bin", ios::binary); // Открыть поток ввода из файла
	if (!in) // Если не удалось открыть файл
	{
		cout << "Не удалось открыть файл" << endl;
		return;
	}
	Student p;
	while (!in.eof()) // Пока не конец файла, считывать данные и добавлять их в список
	{
		in >> p;
		if (in.eof())
			break;
		this->insertLast(p);
	}
	in.close(); // Закрыть поток ввода
	cout << "Список успешно загружен" << endl;
}

void List::edit(int idx, int l, string str1)
{
	Node* q;
	for (q = head; q != nullptr && idx != 0; q = q->next, idx--);
	if (q == nullptr)
	{
		cout << "Такого студента нет в списке" << endl;
		return;
	}
	q->field.edit(str1, l);
	cout << "Редактирование успешно" << endl;
}

void List::edit(int idx, int l, Date str1)
{
	Node* q;
	for (q = head; q != nullptr && idx != 0; q = q->next, idx--);
	if (q == nullptr)
	{
		cout << "Такого студента нет в списке" << endl;
		return;
	}
	q->field.edit(str1, l);
	cout << "Редактирование успешно" << endl;
}