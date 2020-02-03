#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int n;
char candy[55][55];
int dx[2] = { 0,1 };
int dy[2] = { 1,0 };

int maxCandy() {
	int answer = 1;
	int cnt = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < n; j++) {
			if (candy[i][j] == candy[i][j + 1]) cnt++;
			else {
				answer = max(answer, cnt);
				cnt = 1;
			}
		}
		answer = max(answer, cnt);
		cnt = 1;

		for (int j = 1; j < n; j++) {
			if (candy[j][i] == candy[j + 1][i]) cnt++;
			else {
				answer = max(answer, cnt);
				cnt = 1;
			}
		}
		answer = max(answer, cnt);
		cnt = 1;
	}
	return answer;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> candy[i][j];
		}
	}
	int answer = 0;
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			for (int dir = 0; dir < 2; dir++) {
				int nx = x + dx[dir], ny = y + dy[dir];
				if (!candy[nx][ny]) continue;
				swap(candy[x][y], candy[nx][ny]);
				answer = max(answer, maxCandy());
				swap(candy[x][y], candy[nx][ny]);
			}
		}
	}
	cout << answer;
	return 0;
}