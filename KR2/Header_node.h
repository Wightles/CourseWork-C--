#include "Header_Student.h"

class node
{
private:
	Student field;
	node* next;
	node* prev;
public:
	node();
	node(Student);
	~node();

};

node::node()
{
	field = Student();
	next = nullptr;
	prev = nullptr;
}

node::~node()
{
	
}

node::node(Student x)
{
	field = x;

}