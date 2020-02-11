#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n, k;
vector<int> path;
int arr[100001];
bool check[100001];

int bfs() {
	queue < pair<int, int>> q;
	q.push({ 0, n });	//0초(초기화), 수빈 자리
	check[n] = 1;
	while (!q.empty()) {
		int cnt = q.front().first;
		int cur = q.front().second;
		q.pop();

		if (cur == k) {
			int idx = cur;
			while (idx != n) {
				path.push_back(idx);
				idx = arr[idx];
			}
			path.push_back(n);
			return cnt;
			break;
		}

		if (cur * 2 < 100001 && check[cur * 2] == 0) {
			q.push({ cnt + 1, cur * 2 });
			check[cur * 2] = 1;
			arr[cur * 2] = cur;
		}
		if (cur + 1 < 100001 && check[cur + 1] == 0) {
			q.push({ cnt + 1, cur + 1 });
			check[cur + 1] = 1;
			arr[cur + 1] = cur;
		}
		if (cur - 1 >= 0 && check[cur - 1] == 0) {
			q.push({ cnt + 1, cur - 1 });
			check[cur - 1] = 1;
			arr[cur - 1] = cur;
		}
	}
}

int main() {
	cin >> n >> k;
	cout << bfs() << '\n';
	for (int i = path.size() - 1; i >= 0; i--) {
		cout << path[i] << ' ';
	}
	return 0;
}