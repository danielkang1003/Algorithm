#include<iostream>
#include<string>
#include<stack>

using namespace std;

string input;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while (1) {
		getline(cin, input);
		int len = input.length();
		stack<char> s;
		//.이 나오면 while문 종료
		if (len == 1 && input[0] == '.') break;

		bool flag = true;
		for (int i = 0; i < len; i++) {
			if (input[i] == '(' || input[i] == '[') {
				s.push(input[i]);
			}
			else if (input[i] == ')') {
				if (s.empty() || s.top() == '[') {
					flag = false;
					break;
				}
				else s.pop();
			}
			else if (input[i] == ']') {
				if (s.empty() || s.top() == '(') {
					flag = false;
					break;
				}
				else s.pop();
			}
		}
		if (flag && s.empty()) cout << "yes\n";
		else cout << "no\n";
	}

	return 0;
}
