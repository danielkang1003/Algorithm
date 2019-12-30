#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m;	//������� ���� ��,���� ģ������ ����Ʈ ����
int a, b;	//ģ������
vector<int> friends[501];
int check[501];
int cnt;

void bfs(int start) {
	queue<int> q;
	q.push(start);
	check[start] = 1;
	while (!q.empty()) {
		int cur = q.front();
		//cout << "���� ģ���� ��ȣ: " << cur <<'\n';
		q.pop();

		int size = friends[cur].size();
		//cout << cur << "�� ģ���� �� : " << size << '\n';
		for (int i = 0; i < size; i++) {
			int nxt = friends[cur][i];
			//cout << cur << "�� ģ��: " << nxt <<'\n';
			if (check[nxt] == 0) {
				q.push(nxt);
				check[nxt] = check[cur] + 1;
			}
		}

	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		friends[a].push_back(b);
		friends[b].push_back(a);
	}
	bfs(1);

	//���(1)�� ģ���� �� ģ���� ģ�� �����̹Ƿ� 3�� �Ÿ�����
	cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (check[i] == 2 || check[i] == 3) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}