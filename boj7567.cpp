#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int main() {
	string input = "";
	stack<char> s;
	int total = 0;
	cin >> input;
	int len = input.length();
	for (int i = 0; i < len; i++) {
		if (s.empty()) {
			//½ÃÀÛ
			s.push(input[i]);
			total += 10;
		}
		else {
			//¹Ø¿¡ ±×¸©ÀÌ ÀÖ´Ù¸é
			if (s.top() == '(') {
				if (input[i] == '(') {
					s.push(input[i]);
					total += 5;
				}
				else {
					// )ÀÏ ¶§
					s.push(input[i]);
					total += 10;
				}
			}
			else {// ¹Ø¿¡ ±×¸©ÀÌ ) ÀÏ ‹š
				if (input[i] == '(') {
					s.push(input[i]);
					total += 10;
				}
				else {
					// )ÀÏ ¶§
					s.push(input[i]);
					total += 5;
				}
			}
		}
	}
	cout << total;
	return 0;
}