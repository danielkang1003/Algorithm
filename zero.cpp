#include<iostream>
#include<stack>

using namespace std;

int tc, k, answer;
stack<int> s;

//로직: 숫자를 받아서 0이 아니면 스택에 푸시, 0이라면 가장 위의 숫자 pop
//이후 스택이 빌때까지 숫자를 더하면서 꺼냄

int main() {
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		answer = 0;
		cin >> k;
		for (int i = 0; i < k; i++) {
			int num;
			cin >> num;
			if (num != 0) s.push(num);
			else s.pop();
		}
		while (!s.empty()) {
			answer += s.top();
			s.pop();
		}
		cout << "#" << t << " " << answer << '\n';
	}

	return 0;
}