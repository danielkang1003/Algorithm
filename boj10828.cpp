#include<iostream>

using namespace std;

struct stack {
	int data[10000];
	int idx = -1;

	void push(int x) {
		data[++idx] = x;
	}
	bool empty() {
		if (idx == -1) return true;
		else return false;
		//return idx ==-1;
	}
	int size() {
		if (empty()) return 0;
		else return idx + 1;
	}
	int top() {
		if (!empty()) return data[idx];
		else return -1;
	}
	int pop() {
		if (!empty()) {
			int res = data[idx];
			data[idx--] = 0;
			return res;
		}
		else return -1;
	}
};

int main() {
	int n;
	stack s;
	cin >> n;
	while (n--) {
		string input;
		cin >> input;
		if (input == "push") {
			int x;
			cin >> x;
			s.push(x);
		}
		else if (input == "empty") cout << s.empty() << '\n';
		else if (input == "size") cout << s.size() << "\n";
		else if (input == "top") cout << s.top() << '\n';
		else if (input == "pop") cout << s.pop() << '\n';
	}

	return 0;
}