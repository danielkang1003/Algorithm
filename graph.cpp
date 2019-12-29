#include<iostream>
#include<vector>

using namespace std;

int v, e;	//정점, 간선
int adj_matrix[10][10];
vector<int> adj[10];	//정점 i 와 연결된 정점들의 정보를 갖고 있음.
int main() {
	cin >> v >> e;
	//1. 인접 행렬 방식
	//1 - a) Directed Graph (방향이 있음)
	/*for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		adj_matrix[u][v] = 1;
	}*/

	//1 - b) Undirected Graph (방향이 없음)
	/*for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		adj_matrix[u][v] = 1;
		adj_matrix[v][u] = 1;
	}*/

	//2. 인접 리스트 방식
	//코딩 테스트에서 인접행렬보다 훨씬 많이 사용
	//V가 크고 E가 상대적으로 작은 상황에서 공간을 절약할 수 있는 방식
	//2 - a) Direct Graph
	/*for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}*/

	//2 - b) Undirected Graph
	for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u, v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i < e; i++) {
		for (int j = 1; j < e; j++) {
			//인접 행렬 출력
			//cout << adj_matrix[i][j] << ' ';

			//인접 리스트 출력
			cout << adj[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}