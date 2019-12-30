#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m;	//�갣 ����, �갣�� ����� ��
int a, b;	//����� �갣��
vector<int> hide[20001];
int dist[20001];

//�갣�� �Ÿ� üũ
void bfs(int start) {
	queue<int> q;
	q.push(start);
	dist[start] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		int size = hide[cur].size();
		for (int i = 0; i < size; i++) {
			int nxt = hide[cur][i];
			if (dist[nxt] == 0) {
				q.push(nxt);
				dist[nxt] = dist[cur] + 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		hide[a].push_back(b);
		hide[b].push_back(a);
	}

	bfs(1);

	//���� �հŸ��� �����ִ� ��� ����
	int max_dist = 0, place = 0;
	for (int i = 2; i <= n; i++) {
		if (dist[i] > max_dist) {
			max_dist = dist[i];
			place = i;
		}
	}
	//���� �Ÿ��� �갣 ������ ����
	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (dist[i] == max_dist) {
			cnt++;
		}
	}

	cout << place << ' ' << max_dist - 1 << ' ' << cnt;
	return 0;
}