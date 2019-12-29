//연결 그래프에서의 순회
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int v, e, u1, u2;
vector<int> adj[10];
bool check[10];

void bfs() {
	queue<int> q;
	q.push(1);
	check[1] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << "현재 바라보는 숫자: " << cur << "\n";
		int size = adj[cur].size();
		cout << "cur " << cur << "과 연결된 숫자 개수: " << size << '\n';
		for (int i = 0; i < size; i++) {
			int nxt = adj[cur][i];
			cout << "adj[" << cur << "] 과 연결된 숫자: " << nxt << '\n';
			if (check[nxt]) continue;
			q.push(nxt);
			check[nxt] = 1;
		}
	}
}

int main() {
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		cin >> u1 >> u2;
		adj[u1].push_back(u2);
		adj[u2].push_back(u1);
	}
	bfs();
	return 0;
}