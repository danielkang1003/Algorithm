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
			//����
			s.push(input[i]);
			total += 10;
		}
		else {
			//�ؿ� �׸��� �ִٸ�
			if (s.top() == '(') {
				if (input[i] == '(') {
					s.push(input[i]);
					total += 5;
				}
				else {
					// )�� ��
					s.push(input[i]);
					total += 10;
				}
			}
			else {// �ؿ� �׸��� ) �� ��
				if (input[i] == '(') {
					s.push(input[i]);
					total += 10;
				}
				else {
					// )�� ��
					s.push(input[i]);
					total += 5;
				}
			}
		}
	}
	cout << total;
	return 0;
}