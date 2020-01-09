#include<iostream>
#include<queue>

using namespace std;

int n;
queue<int> q;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	//ī�� q�� �ֱ�
	for (int i = 1; i <= n; i++) q.push(i);
	//q�� ������������� ���ڸ� �ڷ� �Ѱ��ְ� 1�� ������ ������ְ� ��
	while (!q.empty()) {
		if (q.size() == 1) {
			cout << q.front();
			q.pop();
			break;
		}
		//�� �κ��� ���� ī�带 ������ �״��� ī�带 �ڷ� �ѱ�� �ѱ� ���� �������ִ� �۾�
		q.pop();
		q.push(q.front());
		q.pop();
	}

	return 0;
}