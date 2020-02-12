#include<iostream>
#include<algorithm>

using namespace std;

int n, l;
int vmap[100][100], hmap[100][100];	//세로, 가로 맵

bool setStair(int map[][100], int x, int y) {
	for (int j = y + 1; j < y + 1 + l; j++) {
		if (map[x][y + 1] != map[x][j]) {
			//첫 시도는 무시. 값을 넘겨와 밟고 있는 다음 칸부터
			//경사로 길이만큼 확인하며 높이가 같은지 확인
			return false;	//다르다면 0 반환
		}
	}
	return true;	//같다면 1 반환
}

int possiblePath(int map[][100]) {
	int possibleCnt = 0;
	for (int i = 0; i < n; i++) {
		bool flag = true;
		int prev = 1;	//연결된 땅 높이가 같은지 보기 위해
		for (int j = 0; j < n - 1; j++) {
			if (map[i][j] == map[i][j + 1]) {	//다음 계단이랑 높이가 같다면(수평)
				prev++;	//계단 나아간걸로 증가 표시
			}
			else if (map[i][j] == map[i][j + 1] + 1) {	//현재 밟고 있는 계단 높이가 높음(내리막)
				if (setStair(map, i, j) == 1) {
					//경사로 길이만큼 높이가 같다면
					j = j + l - 1;
					prev = 0;
				}
				else {
					flag = false;
					break;
				}
			}
			else if (map[i][j] + 1 == map[i][j + 1]) {	//현재 밟고 있는 계단높이가 낮음(오르막)
				if (prev >= l) {
					prev = 1;
				}
				else {
					flag = false;
					break;
				}
			}
			else if (abs(map[i][j] - map[i][j + 1]) >= 2) {//높이 차가 2 이상이면
				flag = false;
				break;
			}
		}
		if (flag) {
			//다리를 놓을 수 있을 때만
			possibleCnt++;
		}
	}
	return possibleCnt;
}

int main() {
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> hmap[i][j];	//가로맵 받고
			vmap[j][i] = hmap[i][j];	//세로맵에 가로맵 순서대로 받음
		}
	}
	int a = possiblePath(vmap);
	int b = possiblePath(hmap);
	int answer = a + b;
	cout << answer << '\n';
	return 0;
}