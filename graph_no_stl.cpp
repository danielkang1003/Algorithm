#include<iostream>

using namespace std;

int edge[10][10];
int deg[10];	//�� ������ outdegree
int* adj[10];
int idx[10];	//adj[i]���� ���ο� ������ �߰��� ���� ��ġ

int main() {
	int v, e;
	cin >> v >> e;
	//stl�� ����� �� ���� ��
	//1. ���� �׷��� (Directed Graph)
	for (int i = 0; i < e; i++) {
		cin >> edge[i][0] >> edge[i][1];
		deg[edge[i][0]]++;
	}
	for (int i = 1; i <= v; i++) {
		adj[i] = new int[deg[i]];
	}
	for (int i = 0; i < e; i++) {
		int u = edge[i][0], v = edge[i][1];
		adj[u][idx[u]] = v;
		idx[u]++;
	}

	//2. �� ���� �׷��� (Undirected Graph)
	//adj�� ó���� �ѹ� �� ���ָ� �ȴ�.
	for (int i = 0; i < e; i++) {
		cin >> edge[i][0] >> edge[i][1];
		deg[edge[i][0]]++;
		deg[edge[i][1]]++;
	}
	for (int i = 1; i <= v; i++) {
		adj[i] = new int[deg[i]];
	}
	for (int i = 0; i < e; i++) {
		int u = edge[i][0], v = edge[i][1];
		adj[u][idx[u]] = v;
		idx[u]++;
		adj[v][idx[v]] = u;
		idx[v]++;
	}
}

