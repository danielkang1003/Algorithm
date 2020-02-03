#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//배열을 돌리는 가장 중요한 점에서 막혔다...
//다른 사람 풀이를 보고 구현을 완료하였지만, 아직 내것이 되지 않았다.
//내일 다시 풀어볼 예정

struct XY {
	int r, c, s;
};	//행 열 차이

int n, m, k, r, c, s;
int map[51][51], c_map[51][51];
bool check[51];
int answer;
vector<XY> v;	//돌려야하는 정보 담은 벡터
vector<int> order;	//순열로 순서를 정하기 위한 벡터

//(1,1) 기준 :
//dx,y[0]: (1,1) +(0,1) => (1,2): 왼 -> 오 (동쪽 방향)
//dx,y[1]: (1,1) +(0,-1) => (1,0): 오 -> 왼 (서쪽 방향)
//dx,y[2]: (1,1) +(1,0) => (2,1): 위 -> 아래 (남쪽 방향)
//dx,y[3]: (1,1) +(-1,0) => (0,1): 아래 -> 위 (북쪽 방향)
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int changeDir(int dir) {
	//반시계 방향
	if (dir == 0) return 3;
	else if (dir == 1) return 2;
	else if (dir == 2) return 0;
	else if (dir == 3) return 1;
}

void rotate(XY xy, int cnt) {
	//int upX, int upY, int botX, int botY
	int upX = xy.r - xy.s;
	int upY = xy.c - xy.s;
	int botX = xy.r + xy.s;
	int botY = xy.c + xy.s;
	//int t = cnt;
	//cout << "#" <<t + 1 << " "  << "왼쪽 위 좌표 x,y: " << upX << ' ' << upY << " \n오른쪽 아래 좌표 x,y: " << botX << ' ' << botY << '\n';
	//cout<< "위 아래 값: " << up << " " << bot << '\n';
	int turnCnt = (botX - upX) / 2;	//사각형 반복 수(botX는 더하는 값이기에 큰 값 - upX 작은 x값)
	for (int i = 0; i < turnCnt; i++) {
		int x = upX;
		int y = upY;
		int temp = c_map[x][y];
		int dir = 2;
		//cout << "x,y 좌표: " << x << ',' << y << "방향: " << dir << "값: " << c_map[x][y] << "temp 값: " << temp << '\n';
		while (true) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx == upX && ny == upY) {
				c_map[x][y] = temp;
				break;
			}
			if (upX <= nx && nx <= botX - i && upY <= ny && ny <= botY - i) {
				//cout << dir << "방향에 따른 좌표" << nx << ' ' << ny << "값: " << c_map[nx][ny] << '\n';
				c_map[x][y] = c_map[nx][ny];
				x = nx;
				y = ny;
			}
			else {
				dir = changeDir(dir);
			}
		}
		upX++;
		upY++;
	}
	//cout << "배열 돌린 후 값: \n";
	//for (int i = 1; i <= n; i++) {
	//	for (int j = 1; j <= m; j++) {
	//		cout << c_map[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}
}

void input() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		cin >> r >> c >> s;
		v.push_back({ r,c,s });
	}
}

int cal() {
	int val = 999999999;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= m; j++) {
			sum += c_map[i][j];
		}
		val = min(val, sum);
	}
	return val;
}

void dfs(int cnt) {
	if (cnt == k) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				c_map[i][j] = map[i][j];

		for (int i = 0; i < order.size(); i++) {
			//cout << "order: " << order[i] << '\n';	
			rotate(v[order[i]], i);//돌려야하는 정보를 담은 배열을 돌려준다.
		}
		//cout << '\n';
		answer = min(answer, cal());
		return;
	}
	//배열을 어떻게 돌리느냐에 따라 값이 달라지므로 순열 사용
	for (int i = 0; i < v.size(); i++) {
		if (check[i] == 0) {
			check[i] = 1;
			order.push_back(i);	//배열 돌릴 순서를 정함
			dfs(cnt + 1);
			order.pop_back();
			check[i] = 0;
		}
	}
}


int main() {
	answer = 987654321;
	input();
	dfs(0);
	cout << answer << '\n';
	return 0;
}