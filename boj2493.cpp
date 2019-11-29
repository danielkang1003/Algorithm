#include<iostream>
#include<stack>
#include<vector>


using namespace std;

//������ ���ڸ� �޾Ƽ� ������ ��������� 0 ������ְ� ���ÿ� �ε����� ���̸� �־��ش�
//������ ������� �ʴٸ� ���ÿ� ������ִ� ����(s.top().second)�� ���� �Էµ� ���̶� ���Ѵ�
//���ؼ� ���ÿ� �ִ� ���� ũ�ٸ� ���ÿ� �ִ� �ε���(s.top().first ������ְ� Ż��
//���� ������ ���̺��� �Էµ� ���̰� ũ�ٸ� ������ ��ܿ� �ִ� ���� ������
//��ȣ�� ���� ���ϹǷ� pop���ָ� �ȴ�!using namespace std;

int n, num;
stack<pair<int, int>> s;
//n�� 50���̶�� ���ڿ��� ������� printf,scanf �Ǵ�
//sync�� ������ ������ �ð��ʰ� ��.
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		while (!s.empty()) {
			if (s.top().second > num) {
				cout << s.top().first << ' ';
				break;
			}
			s.pop();
		}

		if (s.empty()) cout << "0 ";
		s.push(make_pair(i, num));
	}
	return 0;
}