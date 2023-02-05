#include<iostream>
#include<string>
using namespace std; 

class Node {

public:
	Node* next; //교수님 코드 참고
	Node* prev; //교수님 코드 참고

	int value;

	Node(int value) {
		this->next = NULL;
		this->prev = NULL;
		this->value = value;
	}

};

void push(int, int);
int pop();
//int size();
int empty();
int front();
int back();

Node* head;
Node* tail;
int s = 0;

int main(void) {
	
	int N, arg;
	string fun;
	string answer = "";

	//첫째 줄에 주어지는 명령의 수 N(1 ≤ N ≤ 10, 000)이 주어진다.
	cin >> N;

	//둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다.주어지는 정수는 1보다 크거나 같고, 100, 000보다 작거나 같다.
	while(N-- > 0) {
		cin >> fun;

		if (fun == "push") {
			cin >> arg;
			push(arg, s);
			continue;
		}
		else if (fun == "pop") {
			answer.append(to_string(pop()));
		}
		else if (fun == "size") {
			answer.append(to_string(s));
		}
		else if (fun == "empty") {
			answer.append(to_string(empty()));
		}
		else if (fun == "front") {
			answer.append(to_string(front()));
		}
		else if (fun == "back") {
			answer.append(to_string(back()));
		}

		answer.append("\n");
	}
	
	cout << answer << endl;
	return 0;
}
// push X : 정수 X를 큐에 넣는 연산이다.
void push(int arg, int s) {
	Node* node = new Node(arg);

	if (s == 0) {
		head = node;
		tail = node;
	}
	else {
		tail->next = node;
		node->prev = tail;
		tail = node; 		
	}

	s += 1;
}

//pop : 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다.만약 큐에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
int pop() {
	if (s == 0) {
		return -1;
	}
	int res = head->value;

	head = head->next; //이렇게 하면 head의 value, prev는 head->next의 prev, value로 바로 바뀌는 건가?
	head->prev = NULL;
	s -= 1;
	
	return res;
}

//size : 큐에 들어있는 정수의 개수를 출력한다.

//empty : 큐가 비어있으면 1, 아니면 0을 출력한다.
int empty() {
	return ( s == 0 ? 1 : 0);
}

//front : 큐의 가장 앞에 있는 정수를 출력한다.만약 큐에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
int front() {
	if (s == 0) {
		return -1;
	}
	return head->value;
}

//back : 큐의 가장 뒤에 있는 정수를 출력한다.만약 큐에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
int back() {
	if (s == 0) {
		return -1;
	}
	return tail->value;
}
