#include<iostream>
#include<stack>
#include<string>
using namespace std;



int main() {
	string input;
	cin >> input;
	int len = input.length();
	stack<char> s;
	int ans = 0, mul = 1;
	bool flag = false;

	//스택을 활용해서 넣어주고 값을 미리 곱해준다 그리고
	//닫는 괄호가 나타나면 거기서 수를 계산하고 부여된 값(2, 3)을
	//나누어 주었다. 예외처리랑 break도 여기서 다 처리
	for (int i = 0; i < len; i++) {
		if (input[i] == '(') {
			mul *= 2;
			s.push(input[i]);
		}
		else if (input[i] == '[') {
			mul *= 3;
			s.push(input[i]);
		}
		else if (input[i] == ')') {
			if (s.empty()) {
				flag = true;
				break;
			}
			if (s.top() == '(') {
				s.pop();
			}
			if (input[i - 1] == '(') {
				ans += mul;
			}
			mul /= 2;
		}
		else { // ']'일 때
			if (s.empty()) {
				flag = true;
				break;
			}
			if (s.top() == '[') s.pop();
			if (input[i - 1] == '[') ans += mul;
			mul /= 3;
		}
	}
	//예외 처리..
	if (flag || !s.empty()) cout << 0;
	else cout << ans;
	return 0;
}