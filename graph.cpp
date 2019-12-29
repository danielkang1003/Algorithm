#include<iostream>
#include<vector>

using namespace std;

int v, e;	//����, ����
int adj_matrix[10][10];
vector<int> adj[10];	//���� i �� ����� �������� ������ ���� ����.
int main() {
	cin >> v >> e;
	//1. ���� ��� ���
	//1 - a) Directed Graph (������ ����)
	/*for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		adj_matrix[u][v] = 1;
	}*/

	//1 - b) Undirected Graph (������ ����)
	/*for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		adj_matrix[u][v] = 1;
		adj_matrix[v][u] = 1;
	}*/

	//2. ���� ����Ʈ ���
	//�ڵ� �׽�Ʈ���� ������ĺ��� �ξ� ���� ���
	//V�� ũ�� E�� ��������� ���� ��Ȳ���� ������ ������ �� �ִ� ���
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
			//���� ��� ���
			//cout << adj_matrix[i][j] << ' ';

			//���� ����Ʈ ���
			cout << adj[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}