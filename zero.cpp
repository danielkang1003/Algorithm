#include<iostream>
#include<stack>

using namespace std;

int tc, k, answer;
stack<int> s;

//����: ���ڸ� �޾Ƽ� 0�� �ƴϸ� ���ÿ� Ǫ��, 0�̶�� ���� ���� ���� pop
//���� ������ �������� ���ڸ� ���ϸ鼭 ����

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