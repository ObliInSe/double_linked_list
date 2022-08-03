#include <iostream>
using namespace std;

class List
{
public:
	List();
	~List();
	void push_back(const int data);
	void push_front(const int data);
	void insert(const int data, const int position);
	void print();
	void print_address();
	void delete_by_position(const int position);
	void reverse();
	void clear();
private:

	class Node
	{
	public:
		Node(int data = NULL, Node* pPrevious = nullptr, Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
			this->pPrevious = pPrevious;
		};
		~Node() {};
		Node* pNext;
		Node* pPrevious;
		int data;
	};
	Node* head = nullptr;
	int size = 0;
	int min_position;
	int min_value;
};


List::List()
{
}

List::~List()
{
}

void List::push_back(const int data)
{

	if (head == nullptr)
	{
		head = new Node(data);
	}
	else
	{
		Node* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node(data, current);
	}
	size++;
}

void List::push_front(const int data)
{
	if (size == 0)
	{
		this->head = new Node(data);
		size++;
	}
	else {
		this->head = new Node(data, nullptr, this->head);
		this->head->pNext->pPrevious = this->head;
		size++;
	}
}

void List::insert(const int data, const int position)
{
	if (position == 0)
	{
		push_front(data);
	}
	else if (position == size - 1)
	{
		push_back(data);
	}
	else
	{
		int current_position = 0;
		Node* current = this->head;
		while (current_position != position - 1)
		{
			current = current->pNext;
			current_position++;
		}
		current->pNext = new Node(data, current, current->pNext);
		current->pNext->pNext->pPrevious = current->pNext;
	}
	size++;
}

void List::print()
{
	if (size == 0)
	{
		cout << "List empty" << endl;
	}
	else
	{
		Node* current = this->head;
		cout << current->data << " ";
		while (current->pNext != nullptr)
		{
			current = current->pNext;
			cout << current->data << " ";
		}
		cout << endl;
	}
}

void List::print_address()
{
	if (size == 0)
	{
		cout << "List empty" << endl;
	}
	else
	{
		cout << "Previous" << "\t" << "Current" << "\t\t" << "Next" << endl;
		Node* current = this->head;
		cout << &(current->pPrevious->data) << "\t" << &(current->data) << "\t" << &(current->pNext->data) << endl;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
			cout << &(current->pPrevious->data) << "\t" << &(current->data) << "\t" << &(current->pNext->data) << endl;
		}
		cout << endl << endl;;
	}
}

void List::delete_by_position(const int position)
{
	int current_position = 0;
	Node* current = this->head;
	while (current_position != position - 1)
	{
		current = current->pNext;
		current_position++;
	}
	current->pNext = current->pNext->pNext;
	current->pNext->pPrevious = current;
	size--;
}

void List::reverse()
{
	List new_list;
	Node* current = this->head;
	while (current->pNext != nullptr)
	{
		new_list.push_front(current->data);
		current = current->pNext;
	}
	new_list.push_front(current->data);
	clear();
	current = new_list.head;
	while (current->pNext != nullptr)
	{
		push_back(current->data);
		current = current->pNext;
	}
	push_back(current->data);
}

void List::clear()
{
	while (head)
	{
		Node* current = head->pNext;
		delete head;
		head = current;
	}
	size = 0;
}


int main()
{
	List first_list;
	first_list.push_back(5);
	first_list.push_back(6);
	first_list.push_back(7);
	first_list.push_back(8);
	first_list.push_front(4);
	first_list.push_front(3);
	cout << "Before reverse" << endl;
	first_list.print();
	first_list.reverse();
	cout << "After reverse" << endl;
	first_list.print();
	
}



