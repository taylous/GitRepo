#include<iostream>
#include<string>
using namespace std;

void push(int);
int pop();
int size();
int empty();
int top();

int stack[10000] = { 0, };
int index = -1;

int main(void) {

	int N, arg;
	string fun;

	cin >> N;

	string answer = "";
	//int out;


	for (int i = 0; i < N; i += 1) {
		cin >> fun;
		
		if (fun == "push") {
			cin >> arg;
			push(arg);
			continue; // 교수님 답 참고) 왜 continue 써야되는지 모르겠었는데 알았음.
		}
		else if (fun == "pop") {
			answer.append(to_string(pop()));
		}
		else if (fun == "size") {
			answer.append(to_string(size()));
		}
		else if (fun == "empty") {
			answer.append(to_string(empty()));
		}
		else if (fun == "top") {
			answer.append(to_string(top()));
		}

		//위에 출력값을 out으로 받아서 
		//answer.append(to_string(out));
		//로 하면 out이 초기화되지 않은 메모리라고 함
	}

	cout << answer << endl;
	return 0;
}

void push(int value) {
	stack[++index] = value;
}

int pop(){
	if (index == -1) {
		return -1;
	}
	return stack[index--]; // 교수님 답 참고) else로 하면 안 되는 건지?
}

int size() {
	return (index + 1);
}

int empty() {
	return (index == -1 ? 1 : 0);
}

int top() {
	if (index == -1) {
		return -1;
	}
	return stack[index];
}


