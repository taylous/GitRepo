#include <iostream>
#include <string>

using namespace std;

struct node {
	int value;
	node* next;

	node() {
		this->value = NULL;
		this->next = NULL;
	}

	node(int v) {
		this->value = v;
		this->next = NULL;
	}

	node(int v, node* n)
	{
		this->value = v;
		this->next = n;
	}
};

class stack {
private:
	node* head;
public:
	stack()
	{
		this->head = NULL;
	}
	void push();
	void pop();
	void size();
	void empty();
	void top();
};

int main(void)
{
	int n;
	string command;
	stack* s = new stack();
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> command;
		if (command == "push") { s->push(); }
		else if (command == "pop") { s->pop(); }
		else if (command == "size") { s->size(); }
		else if (command == "empty") { s->empty(); }
		else if (command == "top") { s->top(); }
	}


	return 0;
}

void stack::push()
{
	int push;
	cin >> push;

	node* n = new node(push);
	n->next = this->head;
	this->head = n;
}

void stack::pop()
{
	if (this->head == NULL) { cout << -1 << "\n"; }
	else {
		cout << this->head->value << "\n";
		this->head = this->head->next;
	}
}

void stack::size()
{
	int count = 1;
	node* search = this->head;
	if (search == NULL) { cout << 0 << "\n"; }
	else {
		while (search->next != NULL) { search = search->next; count++; }
		cout << count << "\n";
	}
}

void stack::empty()
{
	if (this->head == NULL) { cout << 1 << "\n"; }
	else { cout << 0 << "\n"; }
}

void stack::top()
{
	if (this->head == NULL) { cout << -1 << "\n"; }
	else { cout << this->head->value << "\n"; }
}
