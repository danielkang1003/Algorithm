#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

int tc, n, coreAnswer, lineAnswer;
int map[12][12];
bool check[12][12];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector<pair<int, int>> v;

void init() {
	memset(check, false, sizeof(check));
	memset(map, 0, sizeof(check));
	v.clear();
	coreAnswer = 0;
	lineAnswer = INT_MAX;
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				if (i == 0 || j == 0 || i == n - 1 || j == n - 1) continue;
				v.push_back({ i,j });	//끝부분을 제외한 코어 저장
			}
		}
	}
}

//코어 인덱스, 코어 탐색 수, 코어 설치 개수, 연결된 선 길이
void dfs(int idx, int cnt, int coreCnt, int len) {
	if (cnt == v.size()) {
		if (coreCnt > coreAnswer) {
			coreAnswer = coreCnt;
			lineAnswer = len;
		}
		else if (coreCnt == coreAnswer) {
			coreAnswer = coreCnt;
			lineAnswer = min(lineAnswer, len);
		}
		return;
	}

	for (int dir = 0; dir < 4; dir++) {
		vector<pair<int, int>> temp;
		bool flag = false;
		int x = v[idx].first;
		int y = v[idx].second;
		while (true) {
			if (x == 0 || y == 0 || x == n - 1 || y == n - 1) {
				flag = true;
				break;
			}
			x += dx[dir];	//같은 방향으로 계속 이동
			y += dy[dir];	//끝 부분에 도착할 때까지
			if (map[x][y] == 0) {
				temp.push_back({ x,y });	//이동 가능한 것 넣어주기
			}
			else break;	//이동하는 중 코어 발견 또는 이미 연결된 흔적이 있을 시 이동 불가
		}
		if (flag == true) {
			for (int i = 0; i < temp.size(); i++) {
				map[temp[i].first][temp[i].second] = -1;	//선 연결 시켜주기
			}
			int size = temp.size();
			dfs(idx + 1, cnt + 1, coreCnt + 1, len + size);

			for (int i = 0; i < temp.size(); i++) {
				map[temp[i].first][temp[i].second] = 0;	//선 다시 해제 시켜주기
			}
		}
	}
	dfs(idx + 1, cnt + 1, coreCnt, len);	//설치 안됫을 때
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		init();
		input();
		dfs(0, 0, 0, 0);
		cout << "#" << t << " " << lineAnswer << '\n';
	}

	return 0;
}