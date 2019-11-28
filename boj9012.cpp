#include<iostream>
#include<string>
#include<stack>
//valid PS(VPS)
using namespace std;



int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string input;	//��ȣ ����
		cin >> input;
		stack<char> s;
		bool flag = true;
		int len = input.length();
		for (int i = 0; i < len; i++) {
			if (s.empty()) {
				//����ְ�, ( ������
				if (input[i] == '(') {
					s.push(input[i]);
				}
				else if (input[i] == ')') {
					//����ִµ� ) ������ Ʋ�� ��
					flag = false;
					break;
				}
			}
			else {//������� ���� ��
				if (input[i] == '(') {
					s.push(input[i]);
				}
				else if (input[i] == ')') {
					if (s.top() == '(') {
						s.pop();
					}
				}
			}
		}
		if (!flag || !s.empty()) cout << "NO\n";
		else cout << "YES\n";

		//���� ���� ���� for �ȿ� ��û �����ϰ� �ߴµ�,
		//������ Ǯ�̸� ã�ƺ��� �̷��Ե� Ǯ����.
		//������ ����ְ�, ��ǲ�� )�� ������ �ְ�,
		//for�� ���� ���� �ߴ� ��Ű�� ������� �����ϱ�
		//NO�� ȣ���ϵ��� �����ߴ�...��ź
		//�̷��� �������.
		/*
		for (int i = 0; i < len; i++) {
			if (input[i] == '(') s.push(input[i]);
			else if (input[i] == ')') {
				if (s.empty()) {
					s.push(input[i]);
					break;
				}
				else s.pop();
			}
		}
		if (!s.empty()) cout << "NO\n";
		else cout << "YES\n";
		*/
	}

	return 0;
}