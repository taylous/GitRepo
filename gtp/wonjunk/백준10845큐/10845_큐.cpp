#include <iostream>
#include <string>

using namespace std;

class queue {
private:
	int arrsize;
	int nback;
	int* arr;

public:
	queue() {
		this->arrsize = 10;
		this->nback = -1;
		this->arr = new int[arrsize] {0};
	}
	void push();
	void pop();
	void size();
	void empty();
	void front();
	void back();
};

int main(void) {

	int n;
	cin >> n;

	string command;
	queue* q = new queue();;
	for (int i = 0; i < n; i++)
	{
		cin >> command;
		if (command == "push") { q->push(); }
		else if (command == "pop") { q->pop(); }
		else if (command == "size") { q->size(); }
		else if (command == "empty") { q->empty(); }
		else if (command == "front") { q->front(); }
		else if (command == "back") { q->back(); }
	}

	return 0;
}

void queue::push() {
	if (this->nback >= this->arrsize-1) {
		this->arrsize *= 2;
		int* temp = new int[this->arrsize];
		for (int i = 0; i < this->arrsize / 2; i++)
		{
			temp[i] = this->arr[i];
		}
		delete[] this->arr;
		this->arr = temp;
	}
	int push;
	cin >> push;
	this->arr[++this->nback] = push;
}
void queue::pop() {
	if (this->nback == -1) { cout << -1 << "\n"; }
	else { 
		cout << arr[0] << "\n"; 
		for (int i = 0; i < this->nback; i++) { this->arr[i] = this->arr[i+1]; }
		this->nback--;
	}
}
void queue::size() {
	cout << this->nback + 1 << "\n";
}
void queue::empty() {
	if (this->nback == -1) { cout << 1 << "\n"; }
	else { cout << 0 << "\n"; }
}
void queue::front() {
	if (this->nback == -1) { cout << -1 << "\n"; }
	else { cout << this->arr[0] << "\n"; }
}
void queue::back() {
	if (this->nback == -1) { cout << -1 << "\n"; }
	else { cout << this->arr[this->nback] << "\n"; }
}