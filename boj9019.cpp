#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int t, input, result;
bool check[10000];

void bfs(int input) {
	queue<pair<int, string>> q;
	q.push({ input, "" });
	check[input] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		string answer = q.front().second;
		q.pop();
		if (x == result) {
			cout << answer << '\n';
			return;
		}
		int nx = x * 2;
		if (nx > 9999) nx = nx % 10000;
		if (check[nx] == 0) {
			check[nx] = 1;
			q.push({ nx, answer + "D" });
		}
		nx = x - 1;
		if (nx < 0) nx = 9999;
		if (check[nx] == 0) {
			check[nx] = 1;
			q.push({ nx, answer + "S" });
		}
		nx = (x % 1000) * 10 + (x / 1000);
		if (check[nx] == 0) {
			check[nx] = 1;
			q.push({ nx, answer + "L" });
		}
		nx = (x % 10) * 1000 + (x / 10);
		if (check[nx] == 0) {
			check[nx] = 1;
			q.push({ nx, answer + "R" });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		memset(check, 0, sizeof(check));
		cin >> input >> result;
		bfs(input);
	}

	return 0;
}