#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int v, e, u1, u2;
vector<int> adj[10];
bool check[10];

void bfs() {
	queue<int> q;
	for (int i = 1; i < v; i++) {
		if (check[i]) continue;
		q.push(i);
		check[i] = 1;
		while (!q.empty()) {
			int cur = q.front();
			cout << "현재 바라보는 정점: " << cur << '\n';
			q.pop();
			int size = adj[cur].size();
			cout << "정점 " << cur << "과(와) 연결된 정점의 갯수: " << size << '\n';
			for (int i = 0; i < size; i++) {
				int nxt = adj[cur][i];
				cout << cur << "과(와) " << nxt << "가 연결 되있습니다\n";
				if (check[nxt]) continue;
				q.push(nxt);
				check[nxt] = 1;
			}
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

/*
	입력 값:
	6 4
	1 3
	1 2
	2 4
	5 6
*/