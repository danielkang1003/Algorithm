#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int v, e, u1, u2;
vector<int> adj[10];
bool check[10];

void dfs() {
	stack<int> s;
	for (int i = 1; i <= v; i++) {
		if (check[i]) continue;
		s.push(i);
		check[i] = 1;
		while (!s.empty()) {
			int cur = s.top();
			cout << "���� �ٶ󺸴� ��: " << cur << '\n';
			s.pop();
			//cout << cur << ' ';
			int size = adj[cur].size();
			cout << cur << "�� ����� ���� ����: " << size << '\n';
			for (int i = 0; i < size; i++) {
				int nxt = adj[cur][i];
				cout << cur << "�� ����� ����: " << nxt << '\n';
				if (check[nxt]) continue;
				s.push(nxt);
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
	dfs();
	return 0;
}

/*
	�Է� ��:
	6 4
	1 3
	1 2
	2 4
	5 6
*/