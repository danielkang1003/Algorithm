#include<iostream>
#include<vector>
#include<stack>
#include<queue>

//바이러스: 그래프 문제로 dfs, bfs 모두 사용 가능
using namespace std;

int n, m, u1, u2;
vector<int> computer[101];
bool check[101];
int cnt;

void dfs(int start) {
	cnt = 0;
	stack<int> s;
	s.push(start);
	check[start] = 1;
	while (!s.empty()) {
		int cur = s.top();
		s.pop();
		int size = computer[cur].size();
		for (int i = 0; i < size; i++) {
			int nxt = computer[cur][i];
			if (check[nxt]) continue;
			s.push(nxt);
			check[nxt] = 1;
			cnt++;
		}

	}
}

void bfs(int start) {
	cnt = 0;
	queue<int> q;
	q.push(start);
	check[start] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		int size = computer[cur].size();
		for (int i = 0; i < size; i++) {
			int nxt = computer[cur][i];
			if (check[nxt]) continue;
			q.push(nxt);
			check[nxt] = 1;
			cnt++;
		}

	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> u1 >> u2;
		computer[u1].push_back(u2);
		computer[u2].push_back(u1);
	}
	//dfs(1);
	bfs(1);
	cout << cnt;
	return 0;
}