#include <iostream>
#include <string>

using namespace std;

class node {
public:
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
};

class queue {
private:
	node* head;

public:
	queue() {
		this->head = NULL;
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
	int push;
	cin >> push;
	node* next = new node(push);
	if (this->head == NULL) { this->head = next; }
	else {
		node* search = this->head;
		while (search->next != NULL) { search = search->next; }
		search->next = next;
	}
}
void queue::pop() {
	if (this->head == NULL) { cout << -1 << "\n"; }
	else {
		cout << this->head->value << "\n";
		this->head = this->head->next;
	}

}
void queue::size() {
	int count = 0;
	node* search = this->head;
	if (this->head == NULL) { cout << count << "\n"; }
	else {
		count++;
		while (search->next != NULL) {
			count++;
			search = search->next;
		}
		cout << count << "\n";
	}
}
void queue::empty() {
	if (this->head == NULL) { cout << 1 << "\n"; }
	else {cout << 0 << "\n"; }

}
void queue::front() {
	if (this->head == NULL) { cout << -1 << "\n"; }
	else {
		cout << this->head->value << "\n";
	}
}
void queue::back() {
	if (this->head == NULL) { cout << -1 << "\n"; }
	else {
		node* search = this->head;
		while (search->next != NULL) { search = search->next; }
		cout << search->value << "\n";
	}
}