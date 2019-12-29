#include<iostream>
#include<stack>
#include<vector>
//���� �׷��������� ��ȸ, ����� 2 (dfs)

using namespace std;

vector<int> adj[10];
bool check[10];

int v, e, u1, u2;

void dfs() {
	stack<int> s;
	s.push(1);
	while (!s.empty()) {
		int cur = s.top();
		cout << "���� �ٶ󺸴� ��: " << cur << '\n';
		s.pop();
		if (check[cur]) continue;
		check[cur] = 1;
		//cout << cur << ' ';
		int size = adj[cur].size();
		cout << cur << "�� ����� ���� ����: " << size << '\n';
		for (int i = 0; i < size; i++) {
			int nxt = adj[cur][i];
			cout << cur << "�� ����� ��: " << nxt << '\n';
			if (check[nxt]) continue;
			s.push(nxt);
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