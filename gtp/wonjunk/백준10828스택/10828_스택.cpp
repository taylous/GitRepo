#include <iostream>
#include <string>

using namespace std;

class stack {
private:
	int arrsize;
	int stacksize;
	int* arr;
public:
	stack()
	{
		this->stacksize = 0;
		this->arrsize = 10;
		this->arr = new int[this->arrsize]{0};
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
	if (this->stacksize + 1 > this->arrsize)
	{
		this->arrsize *= 2;
		int* temparr = new int[this->arrsize];
		for (int i = 0; i < this->arrsize / 2; i++)
		{
			temparr[i] = this->arr[i];
		}
		delete[] this->arr;
		this->arr = temparr;
	}

	cin >> push;

	this->stacksize++;
	this->arr[stacksize - 1] = push;
}

void stack::pop()
{
	this->top();
	this->arr[this->stacksize - 1] = 0;
	if (this->stacksize > 0)
		this->stacksize--;
}

void stack::size()
{
	cout << this->stacksize << "\n";
}

void stack::empty()
{
	if (this->stacksize == 0)
		cout << 1 << "\n";
	else
		cout << 0 << "\n";
}

void stack::top()
{
	if (this->stacksize == 0)
		cout << -1 << "\n";
	else
		cout << this->arr[this->stacksize-1] << "\n";
}
