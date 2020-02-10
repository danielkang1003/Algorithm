//��- �ƺ� : 1��
//�ƺ� - �Ҿƹ��� 1��
//�� -�ƺ� - �Ҿƹ���: 2��
//�ƹ��� ���� - �Ҿƹ���: 1��
//�� - �ƺ� - �Ҿƹ��� - �ƹ��� ����
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, a, b, m;	//�����, �̼�����ؾ��ϴ� ���� �ٸ� �λ���� ��ȣ, �θ��ڽ� ���� ����
vector<int> adj[100];
int result[100];
bool check[100];
int bfs() {
	queue<int> q;
	q.push(a);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x == b) return result[x];
		for (int i = 0; i < adj[x].size(); i++) {
			int nx = adj[x].at(i);
			if (result[nx] == 0) {
				q.push(nx);
				result[nx] = result[x] + 1;
			}
		}
	}
	return -1;
}

int main() {
	cin >> n;
	cin >> a >> b;
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int x, y;	//x�� �θ� y�� �ڽ�
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int answer = bfs();
	cout << answer;
	return 0;
}