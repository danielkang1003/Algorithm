#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m;	//상근이의 동기 수,동기 친구관계 리스트 길이
int a, b;	//친구관계
vector<int> friends[501];
int check[501];
int cnt;

void bfs(int start) {
	queue<int> q;
	q.push(start);
	check[start] = 1;
	while (!q.empty()) {
		int cur = q.front();
		//cout << "현재 친구의 번호: " << cur <<'\n';
		q.pop();

		int size = friends[cur].size();
		//cout << cur << "의 친구들 수 : " << size << '\n';
		for (int i = 0; i < size; i++) {
			int nxt = friends[cur][i];
			//cout << cur << "의 친구: " << nxt <<'\n';
			if (check[nxt] == 0) {
				q.push(nxt);
				check[nxt] = check[cur] + 1;
			}
		}

	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		friends[a].push_back(b);
		friends[b].push_back(a);
	}
	bfs(1);

	//상근(1)의 친구와 그 친구의 친구 까지이므로 3의 거리까지
	cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (check[i] == 2 || check[i] == 3) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}