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

	//������ Ȱ���ؼ� �־��ְ� ���� �̸� �����ش� �׸���
	//�ݴ� ��ȣ�� ��Ÿ���� �ű⼭ ���� ����ϰ� �ο��� ��(2, 3)��
	//������ �־���. ����ó���� break�� ���⼭ �� ó��
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
		else { // ']'�� ��
			if (s.empty()) {
				flag = true;
				break;
			}
			if (s.top() == '[') s.pop();
			if (input[i - 1] == '[') ans += mul;
			mul /= 3;
		}
	}
	//���� ó��..
	if (flag || !s.empty()) cout << 0;
	else cout << ans;
	return 0;
}