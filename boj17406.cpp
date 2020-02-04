#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

struct XYInfo {
	int r, c, s;
};

int n, m, k, r, c, s;
int map[51][51], c_map[51][51];

//==============================================
// (1,1) 기준 설명:								|
/*												|
1. dx dy가 0일 때								|
(1,1) + (0,1) => (1,2) 오른쪽으로 간다. 동쪽방향|
2. dx dy가 1일 때								|
(1,1) + (0, -1) => (1,0) 왼쪽으로 간다. 서쪽방향|
3. dx dy가 2일 때								|
(1,1) + (1, 0) => (2,1) 아래로 간다. 남쪽 방향	|
4. dx dy가 3일 때								|
(1,1) + (-1,0) => (0,1) 위로 간다. 북쪽 방향	|
//==============================================
*/
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

vector<int> order;
vector<XYInfo> v;
bool check[51];
int answer;

void copyMap() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			c_map[i][j] = map[i][j];
}

//시계방향이 아닌 반대 방향으로 돌림
int changeDir(int dir) {
	if (dir == 0) return 3;	//동 -> 북
	else if (dir == 1) return 2; //서 -> 남
	else if (dir == 2) return 0; //남 -> 동
	else if (dir == 3) return 1; //북 -> 서
}

void startRotate(XYInfo v) {
	int upX = v.r - v.s;
	int upY = v.c - v.s;
	int botX = v.r + v.s;
	int botY = v.c + v.s;
	/*cout << "왼쪽 위 (x,y): " << upX << ',' << upY << ' ' << " 오른쪽 아래 (x,y): " << botX << ',' << botY <<
		"\n왼쪽 위 값:" << c_map[upX][upY] << " 오른쪽 아래 값: " << c_map[botX][botY] <<'\n';*/
		//정해진 배열내에서 반복횟수 정해야함
	int times = (botX - upX) / 2;
	//cout << "배열 회전 횟수: " << times<< '\n';
	for (int i = 0; i < times; i++) {
		//cout << "현재 배열을 돌려야하는 총 횟수 " << times << " 중 현재 i 의 값: " << i << '\n';
		int x = upX;
		int y = upY;
		int temp = c_map[x][y];
		int dir = 2;	//남쪽 방향 시작
		while (true) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			//cout << "cmap[" <<x << ","<<y<<"] = " << c_map[x][y] << " cmap[" << nx << ',' << ny <<"] = " << c_map[nx][ny]<<'\n';

			if (nx == upX && ny == upY) {
				c_map[x][y] = temp;
				//cout << "처음위치로 돌아왔습니다. cmap[" << x << "," <<y << "]  는 " << c_map[x][y] <<"입니다\n";
				break;
			}
			if (upX <= nx && nx <= botX - i && upY <= ny && ny <= botY - i) {
				//배열안의 배열을 돌리기 위해 -i를 해준다. 첫 시작은 0 두번째는 -1 ...이런식으로 한칸씩 들어감
				//cout << "현재 nx, ny: " << nx << "," << ny << " nx 범위 값: " << upX << "~" << botX - i << " ny 범위 값: " << upY << "~" << botY - i << '\n';
				c_map[x][y] = c_map[nx][ny];
				x = nx;
				y = ny;
			}
			else {
				//if (dir == 0) cout << "동쪽에서 ";
				//else if (dir == 1) cout << "서쪽에서 ";
				//else if (dir == 2) cout << "남쪽에서 ";
				//else if (dir == 3) cout << "북쪽에서 ";
				dir = changeDir(dir);
				/*if (dir == 0) {
					cout << "동쪽으로 ";
				}
				else if (dir == 1) {
					cout << "서쪽으로 ";
				}
				else if (dir == 2) {
					cout << "남쪽으로 ";
				}
				else if (dir == 3) {
					cout << "북쪽으로 ";
				}
				cout << "방향이 변경되었습니다.\n";*/
			}
		}
		upX++, upY++;	//배열안의 배열을 돌려주기 위해 왼쪽 위의 좌표 ++
	}
}

int findMinAns() {
	int minSum = INT_MAX;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= m; j++) {
			sum += c_map[i][j];
		}
		if (minSum > sum) {
			//cout << "minSum 인 " << minSum << " 보다 sum " << sum << " 이 작습니다.\n";
			minSum = sum;
		}
	}
	return minSum;
}

void dfs(int cnt) {
	if (cnt == k) {
		//순서에 따라서 결과가 달라지므로 기존의 맵을 카피해서 사용
		copyMap();
		//돌릴 수 있는 만큼 순서를 정했다면
		//cout << "순서:\n";
		int oSize = order.size();
		for (int i = 0; i < oSize; i++) {
			//cout << "#" << order[i] << ' ';
			//cout << v[order[i]].r << ' ' << v[order[i]].c << ' ' << v[order[i]].s << '\n';
			startRotate(v[order[i]]);	//그 값을 통해서 배열 돌리기
		}
		//cout << '\n';
		answer = min(answer, findMinAns());
		//cout << "배열을 돌리고 난 후 최소 값은: " << answer << '\n';
		return;
	}


	//어떤 순서로 돌릴지 정함
	int size = v.size();	//v[0]에는 3 4 2, v[1]에는 4 2 1이 들어있음
	for (int i = 0; i < size; i++) {
		if (check[i] == 0) {
			check[i] = 1;
			order.push_back(i);
			dfs(cnt + 1);
			order.pop_back();
			check[i] = 0;
		}
	}
}

int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> map[i][j];
	for (int i = 0; i < k; i++) {
		cin >> r >> c >> s;
		v.push_back({ r,c,s });
	}
	answer = INT_MAX;
	dfs(0);
	cout << answer;

	return 0;
}