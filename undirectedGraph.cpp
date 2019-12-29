//���� �׷������� �������� �Ÿ�
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int v, e, u1, u2;	//v: vertex(����), edge(����), u,v�� ������ �����ϱ� ����
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
		cout << "adj[cur]�� ������� " << size << "�Դϴ�\n";
		for (int i = 0; i < size; i++) {
			int nxt = adj[cur][i];
			cout << "next ���� " << nxt << "�Դϴ�\n";
			if (dist[nxt] != -1) continue;
			q.push(nxt);
			dist[nxt] = dist[cur] + 1;
		}
	}
}


int main() {
	//������ �׷���
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
//�Է� ��:
5 7
3 1
2 3
4 1
5 2
5 4
3 5
2 4
*/