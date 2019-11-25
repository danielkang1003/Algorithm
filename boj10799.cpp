#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	string input;
	stack<char> s;
	cin >> input;
	int result = 0;
	int len = input.length();
	for (int i = 0; i < len; i++) {
		if (input[i] == '(') s.push(input[i]);
		else {
			s.pop();
			if (input[i - 1] == '(') result += s.size();
			else result += 1;
		}
	}
	cout << result;
	return 0;
}