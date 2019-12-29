#include<iostream>

using namespace std;

int edge[10][10];
int deg[10];	//각 정점의 outdegree
int* adj[10];
int idx[10];	//adj[i]에서 새로운 정점을 추가할 때의 위치

int main() {
	int v, e;
	cin >> v >> e;
	//stl을 사용할 수 없을 때
	//1. 방향 그래프 (Directed Graph)
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

	//2. 무 방향 그래프 (Undirected Graph)
	//adj의 처리를 한번 더 해주면 된다.
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

