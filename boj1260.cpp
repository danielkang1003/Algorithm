#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
#include<algorithm>
using namespace std;

int n, m, v; //����, ����, �׸��� Ž�� ������ ���� ��ȣ
int u1, u2;	//������ �����ϴ� �� ����
vector<int> adj[1001];
bool check[1001];

void dfs(int start) {
	stack<int> s;
	s.push(start);
	while (!s.empty()) {
		int cur = s.top();
		s.pop();
		if (check[cur]) continue;
		check[cur] = 1;
		cout << cur << ' ';
		int size = adj[cur].size();
		for (int i = 0; i < size; i++) {
			int nxt = adj[cur][size - i - 1];	//��ȣ�� �������� ���� �湮�ϱ� ���� size���� -i�� ���ְ� �迭 ũ�⸦ ���� �ʱ� ���� -1 ó��
			//cout << "nxt�� " << nxt << '\n';
			if (check[nxt]) continue;
			s.push(nxt);
		}
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	check[start] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << cur << ' ';
		int size = adj[cur].size();
		for (int i = 0; i < size; i++) {
			int nxt = adj[cur][i];
			if (check[nxt]) continue;
			q.push(nxt);
			check[nxt] = 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		cin >> u1 >> u2;
		adj[u1].push_back(u2);
		adj[u2].push_back(u1);
	}
	for (int i = 1; i <= n; i++) {
		sort(adj[i].begin(), adj[i].end());
	}

	//dfs
	dfs(v);

	memset(check, 0, sizeof(check));
	cout << '\n';
	//bfs
	bfs(v);
	return 0;
}