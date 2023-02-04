#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	Node* next;
	Node* prev;
	int value;

	Node(int value) {
		this->next = this->prev = NULL;
		this->value = value;
	}
	~Node() {
		this->next = NULL;
		this->prev = NULL;
		delete next;
		delete prev;
	}
};

class Queue {

private:
	Node* head;
	Node* tail;
	int n;

public:
	Queue() {
		this->head = this->tail = NULL;
		this->n = 0;
	}
	~Queue() {
		while (this->head != NULL) {
			Node* node = this->head;
			this->head = this->head->next;
			delete node;
		}
	}

	void push(int value) {

		Node* node = new Node(value);
		this->n += 1;

		if (this->head == NULL) {

			this->head = node;
			this->tail = this->head;
			return;
		}
		this->tail->next = node;
		node->prev = this->tail;
		this->tail = node;
	}

	int pop() {

		if (this->head == NULL) {
			return -1;
		}
		Node* node = this->head;
		int value = node->value;

		this->head = this->head->next;

		if (this->head != NULL)
			this->head->prev = NULL;

		this->n -= 1;
		delete node;
		return value;
	}

	int size() {
		return this->n;
	}

	bool empty() {
		return this->n == 0;
	}

	int front() {

		if (this->head == NULL) {

			return -1;
		}
		return this->head->value;
	}

	int back() {

		if (this->head == NULL) {

			return -1;
		}
		return this->tail->value;
	}
};

int main() {

	Queue* queue = new Queue();

	string command, answer = "";
	int n, value;

	cin >> n;
	while (n-- > 0) {

		cin >> command;

		if (command == "push") {
			cin >> value;
			queue->push(value);
			continue;
		}
		else if (command == "pop") {
			answer.append(to_string(queue->pop()));
		}
		else if (command == "size") {
			answer.append(to_string(queue->size()));
		}
		else if (command == "empty") {
			answer.append(to_string(queue->empty()));
		}
		else if (command == "front") {
			answer.append(to_string(queue->front()));
		}
		else {
			answer.append(to_string(queue->back()));
		}
		answer.append("\n");
	}
	cout << answer << endl;
	delete queue;
	return 0;
}