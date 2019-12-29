#include<iostream>
#include<stack>
#include<queue>
#include<vector>

using namespace std;

int v, e, u1, u2;
vector<int> adj[1001];
bool check[1001];
int answer;
//void dfs() {
//	answer = 0;
//	stack<int> s;
//	for (int i = 1; i <= v; i++) {
//		if (check[i]) continue;
//		answer++;
//		s.push(i);
//		check[i] = 1;
//		while (!s.empty()) {
//			int cur = s.top();
//			s.pop();
//			int size = adj[cur].size();
//			for (int i = 0; i < size; i++) {
//				int nxt = adj[cur][i];
//				if (check[nxt]) continue;
//				s.push(nxt);
//				check[nxt] = 1;
//			}
//		}
//	}
//}

void bfs() {
	answer = 0;
	queue<int> q;
	for (int i = 1; i <= v; i++) {
		if (check[i]) continue;
		answer++;
		check[i] = 1;
		q.push(i);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			int size = adj[cur].size();
			for (int i = 0; i < size; i++) {
				int nxt = adj[cur][i];
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
	//dfs();
	bfs();
	cout << answer;
	return 0;
}