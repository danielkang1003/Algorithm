#include<iostream>
#include<stack>

using namespace std;

string input, result;
stack<char> s;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> input;
	int len = input.length();
	for (int i = 0; i < len; i++) {
		if (input[i] >= 'A' && input[i] <= 'Z') {
			result += input[i];
		}
		else {
			switch (input[i]) {
			case '(':
				s.push(input[i]);
				break;
			case '*':
			case '/':
				while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
					result += s.top();
					s.pop();
				}
				s.push(input[i]);
				break;

			case '+':
			case '-':
				while (!s.empty() && s.top() != '(') {
					result += s.top();
					s.pop();
				}
				s.push(input[i]);
				break;
			case ')':
				while (!s.empty() && s.top() != '(') {
					result += s.top();
					s.pop();
				}
				s.pop();
				break;
			}
		}
	}
	while (!s.empty()) {
		result += s.top();
		s.pop();
	}
	cout << result << '\n';
	return 0;
}
