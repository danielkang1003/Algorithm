#include<iostream>
#include<queue>
#include<cmath>

using namespace std;

int m, n;
int box[1001][1001];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
queue<pair<int, int>> q;

/*한참 헤맸던 문제이다. check배열을 사용해서 풀다보니까
익은 토마토가 두 곳 이상에서 bfs를 돌아야하는 테스트 케이스에서 풀리지가 않았다

해결책으로 전역 변수에 check배열을 없애주고, 토마토가 1인 것을 모두 다 큐에 담아주고 시작했다.
그러고 난 후 bfs를 돌렸다.
bfs를 돌면서 토마토가 들어간 박스가 익지 않았다면 (box[x][y] 가 0일 때)
토마토 개수를 1씩 증가시켰다. (문제는 익은 토마토는 1로 되있어서 마지막에 -1을 해주어야 걸린 시간을 출력 가능하다)

bfs를 돌리고 잘 출력이 되는지 확인을 해보니 잘 된다. 주석으로 처리해놓음.
주어진 문제에서 보관된 토마토 중에 익지 않은 토마토(0) 이 있다면 -1 처리해달라고 함
그리고 익은 토마토 중 (날짜) 가장 큰 수를 계속 업데이트 시켜주었다.
마지막엔 최대 날짜의 토마토에서 -1 해주면 정답!

6 4
1 -1 0 0 0 0
0 -1 0 0 0 0
0 0 0 0 -1 0
0 0 0 0 -1 1

이부분이 문제였는데 통과가 잘 된다!
*/
void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (box[nx][ny] == 0) {
				box[nx][ny] = box[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1)
				q.push({ i,j });
		}
	}
	bfs();

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << box[i][j] << ' ';
		}
		cout << '\n';
	}*/

	int days = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (box[i][j] == 0) {
				cout << "-1\n";
				return 0;
			}
			else days = max(days, box[i][j]);
		}
	}
	cout << days - 1;
	return 0;
}