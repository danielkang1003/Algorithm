#include<iostream>
#include<deque>

using namespace std;

int n;
deque<int> dq;
int main() {
	cin >> n;
	while (n--) {
		int num;
		int printNum;
		string input;
		cin >> input;
		if (input == "push_back") {
			cin >> num;
			dq.push_back(num);
		}
		else if (input == "push_front") {
			cin >> num;
			dq.push_front(num);
		}
		else if (input == "pop_front") {
			if (dq.empty()) cout << "-1\n";
			else {
				printNum = dq.front();
				dq.pop_front();
				cout << printNum << '\n';
			}
		}
		else if (input == "pop_back") {
			if (dq.empty()) cout << "-1\n";
			else {
				printNum = dq.back();
				dq.pop_back();
				cout << printNum << '\n';
			}
		}
		else if (input == "size") {
			cout << dq.size() << '\n';
		}
		else if (input == "empty") {
			cout << (!dq.empty() ? "0\n" : "1\n");
		}
		else if (input == "front") {
			if (dq.empty()) cout << "-1\n";
			else {
				printNum = dq.front();
				cout << printNum << '\n';
			}
		}
		else if (input == "back") {
			if (dq.empty()) cout << "-1\n";
			else {
				printNum = dq.back();
				cout << printNum << '\n';
			}
		}

	}

	return 0;
}