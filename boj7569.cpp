#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int m, n, h;
int answer;
int box[100][100][100];	//높이가 추가된 토마토 박스
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dh[6] = { 0,0,0,0,1,-1 };	//높이가 있는 3차원 배열이므로 height를 돌아줄 dh도 선언
bool check;
queue<pair<pair<int, int>, int>> q;

//다 익었는지 확인
bool check_mature() {
	for (int height = 0; height < h; height++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (box[i][j][height] == 0) return false;
			}
		}
	}
	return true;
}

void bfs() {
	while (!q.empty()) {
		int size = q.size();	//미리 담아놓은 큐 사이즈 만큼 bfs를 돌릴 예정
		for (int qs = 0; qs < size; qs++) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int hei = q.front().second;
			q.pop();
			for (int dir = 0; dir < 6; dir++) {	//높이(위 아래)까지 돌림
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				int nh = hei + dh[dir];
				if (nx < 0 || ny < 0 || nh < 0 || nx >= n || ny >= m || nh >= h)
					continue;
				if (box[nx][ny][nh] == 0) {	//0이라면
					box[nx][ny][nh] = 1;	//1로 바꾸어주고
					q.push({ {nx,ny}, nh });	//다시 푸시
				}
			}
			//bfs로 다 돌고나서
			//만약에 -1 같이 빈 칸이 있고 0이 갇혀있어서 바뀌지 못하는
			//상황을 확인하기 위해 전체를 돌아줘서 0이 발견이 된다면
			//check_mature (박스안의 토마토가 익었는지 확인하는 함수)는
			//false임. -1 출력하고 bfs 종료
			if (q.empty() && check_mature() == false) {
				cout << -1 << '\n';
				return;
			}
			//모두 익은 상태. 큐는 비어있으니까 다 돌았다는 이야기
			else if (q.empty() && check_mature() == true) {
				cout << answer << '\n';
				return;
			}
		}
		//큐가 안비어있고 bfs를 한번 돌았다면 날짜 하루++
		answer++;
	}

}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> m >> n >> h;
	check = 1;	//토마토가 미리 다 익어서 들어오는지 확인할 예정
	for (int height = 0; height < h; height++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> box[i][j][height];
				if (box[i][j][height] == 0) check = 0;	//안익은 토마토가 있다면 false로 변경
				if (box[i][j][height] == 1) {
					q.push({ {i,j}, height });	// 미리 x,y,z를 담아준다.
				}
			}
		}
	}
	//bfs 돌리기 전에 이미 다 익은 상태로 주어지면 0 출력하기 위함
	//위에서 만약 입력으로 0이 한번이라도 들어왔다면 기존에 check = 1이던 것이 0으로 변경되어있음.
	//0이 입력으로 안들어왔다면 계속 1일 것이므로 1이라면(모두 익은상태) 0 출력하고 종료
	if (check == 1) {
		cout << 0 << '\n';
		return 0;
	}

	//다 익은게 아니라면 확인하기 위해 bfs를 돌려준다.
	bfs();

	return 0;
}