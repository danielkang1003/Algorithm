//나- 아빠 : 1촌
//아빠 - 할아버지 1촌
//나 -아빠 - 할아버지: 2촌
//아버지 형제 - 할아버지: 1촌
//나 - 아빠 - 할아버지 - 아버지 형제
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, a, b, m;	//사람수, 촌수계산해야하는 서로 다른 두사람의 번호, 부모자식 관계 개수
vector<int> adj[100];
int result[100];
bool check[100];
int bfs() {
	queue<int> q;
	q.push(a);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x == b) return result[x];
		for (int i = 0; i < adj[x].size(); i++) {
			int nx = adj[x].at(i);
			if (result[nx] == 0) {
				q.push(nx);
				result[nx] = result[x] + 1;
			}
		}
	}
	return -1;
}

int main() {
	cin >> n;
	cin >> a >> b;
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int x, y;	//x는 부모 y는 자식
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int answer = bfs();
	cout << answer;
	return 0;
}