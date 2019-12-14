#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
int n;	//TC
string input;
stack<char> s_main, s_temp;
int main() {
	//���ڿ� ���̰� 1000000�̹Ƿ� �ӵ� ������� ���
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;

	//�־��� TC ��ŭ �ݺ�
	while (n--) {
		cin >> input;

		//�Է¹޴� ���ڿ� ��ŭ ���������� length ����Ͽ� len�� �־���
		int len = input.length();
		for (int i = 0; i < len; i++) {
			//���� ������ ������� �ʰ� �ݺ��Ǵ� ��ǲ�� i�� < �� ��
			//���� ������ ���� temp�� �ְ� ���ο����� ���ֱ�
			if (input[i] == '<') {
				if (!s_main.empty()) {
					s_temp.push(s_main.top());
					s_main.pop();
				}
			}
			//temp ������ ������� �ʰ� �ݺ��Ǵ� ��ǲ�� i�� >�� ��
			//temp�� ����Ǿ��ִ� ���ڸ� �������� �־��ְ� temp���� pop
			else if (input[i] == '>') {
				if (!s_temp.empty()) {
					s_main.push(s_temp.top());
					s_temp.pop();
				}
			}
			//-�� �׳� ���ο��� �������ֱ�
			else if (input[i] == '-') {
				if (!s_main.empty()) s_main.pop();
			}
			//< > - �ƴϸ� ���ο��ٰ� �־��ֱ�
			else {
				s_main.push(input[i]);
			}
		}

		//temp ������ ������� ������ �� ���ְ� ���ο� �־��ֱ�
		while (!s_temp.empty()) {
			s_main.push(s_temp.top());
			s_temp.pop();
		}

		//���� ������ ���� answer ���ڿ��� �ֱ�
		string answer = "";
		while (!s_main.empty()) {
			answer += s_main.top();
			s_main.pop();
		}
		//reverse���ָ� ������� ���!
		reverse(answer.begin(), answer.end());

		cout << answer << '\n';
	}

	return 0;
}