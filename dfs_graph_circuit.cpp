#include<iostream>
#include<stack>
#include<vector>
//DFS로 연결 그래프에서의 순회, 비재귀
using namespace std;

vector<int> adj[10];
bool check[10];

int v, e, u1, u2;

void dfs() {
	stack<int> s;
	s.push(1);
	check[1] = 1;
	while (!s.empty()) {
		int cur = s.top();
		s.pop();
		cout << "현재 보고 있는 값: " << cur << '\n';
		int size = adj[cur].size();
		cout << cur << "과(와) 연결된 숫자 갯수: " << size << '\n';
		for (int i = 0; i < size; i++) {
			int nxt = adj[cur][i];
			cout << "현재 " << cur << "에 연결된 정점: " << nxt << '\n';
			if (check[nxt]) continue;
			s.push(nxt);
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
	dfs();
	return 0;
}

/*
	입력 값:
	7 8
	2 1
	1 3
	1 4
	3 4
	3 5
	5 6
	5 7
	6 7
*/