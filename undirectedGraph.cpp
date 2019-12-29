//연결 그래프에서 정점과의 거리
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int v, e, u1, u2;	//v: vertex(정점), edge(간선), u,v는 정점들 연결하기 위해
vector<int> adj[10];
int dist[10];
void bfs() {
	//for (int i = 1; i < 10; i++) dist[i] = -1;
	fill(dist + 1, dist + 10, -1);
	queue<int> q;
	q.push(1);
	dist[1] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << cur << " \n";
		int size = adj[cur].size();
		cout << "adj[cur]의 사이즈는 " << size << "입니다\n";
		for (int i = 0; i < size; i++) {
			int nxt = adj[cur][i];
			cout << "next 값은 " << nxt << "입니다\n";
			if (dist[nxt] != -1) continue;
			q.push(nxt);
			dist[nxt] = dist[cur] + 1;
		}
	}
}


int main() {
	//무방향 그래프
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
//입력 값:
5 7
3 1
2 3
4 1
5 2
5 4
3 5
2 4
*/