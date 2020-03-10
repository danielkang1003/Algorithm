#include<iostream>
#include<stack>
#include<cstring>

using namespace std;

int len, inpSize;
string inputs;
stack<char> s;

/*
16
{[()]}<>[<{}><>]
*/

void input() {
	while (!s.empty()) s.pop();
	cin >> len;
	cin >> inputs;
	inpSize = inputs.size();
	for (int i = 0; i < inpSize; i++) {
		if (inputs[i] == '(' || inputs[i] == '{' || inputs[i] == '[' || inputs[i] == '<') {
			s.push(inputs[i]);
		}
		else if (s.top() == '(' && inputs[i] == ')') s.pop();
		else if (s.top() == '{' && inputs[i] == '}') s.pop();
		else if (s.top() == '[' && inputs[i] == ']') s.pop();
		else if (s.top() == '<' && inputs[i] == '>') s.pop();
		else s.push(inputs[i]);
	}
}


int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	for (int t = 1; t <= 10; t++) {
		input();
		if (s.empty()) cout << "1\n";
		else cout << "0\n";
		while (!s.empty()) s.pop();
	}
	return 0;
}