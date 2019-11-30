#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int map[25][25];	//입력받아서 넣을 배열
int check[25][25];	//방문했는지 확인
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int num;			//단지 내 몇개의 아파트가 있는지
vector<int> totalApt;//단지 내 아파트 수 num을 넣기위한 벡터

void bfs(int i, int j) {
	queue<pair<int, int>> q;
	q.push({ i,j });
	check[i][j] = 1;
	num++;	//단지안에 몇개의 아파트가 있는지 세어주기
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n)
				continue;
			if (map[nx][ny] == 0 || check[nx][ny] == 1)
				continue;
			q.push({ nx,ny });
			check[nx][ny] = 1;
			num++;	//같은 단지내에서는 num증가시켜서 단지 내 아파트 개수 확인
		}
	}
	totalApt.push_back(num);	//세어준 아파트 수를 벡터에 푸시
	num = 0;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s("%1d", &map[i][j]);
		}
	}

	int cnt = 0;	//총 몇개의 단지가 있는지 확인하기 위해 변수 선언 및 초기화
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//아파트(1)이거나, 방문안하면 bfs 시작, 단지수 또한 세서 몇개 단지가 있는지 확인
			if (map[i][j] == 1 && check[i][j] == 0) {
				cnt++;
				bfs(i, j);
			}
		}
	}
	sort(totalApt.begin(), totalApt.end());	//오름차순 정렬
	cout << cnt << '\n';
	int size = totalApt.size();		//아파트 단지만큼 벡터가 나오게 된다
	for (int i = 0; i < size; i++)
		cout << totalApt[i] << '\n';
	return 0;
}