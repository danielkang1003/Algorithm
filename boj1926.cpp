#include<iostream>
#include<queue>

using namespace std;

int n, m;
int image[500][500];
int check[500][500];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	//입력
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> image[i][j];

	int max_img = 0;//그림 최대 넓이
	int img_cnt = 0;//그림 개수

	//BFS
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (image[i][j] == 0 || check[i][j]) continue;
			img_cnt++;
			queue<pair<int, int>> q;	//좌표를 넣을 큐 만들기
			q.push(make_pair(i, j));	//i,j를 좌표로 bfs시작 준비
			check[i][j] = 1;			//i,j 방문 처리
			int area = 0;		//그림의 넓이
			while (!q.empty()) {		//q가 비지 않으면
				area++;
				int x = q.front().first;
				int y = q.front().second;
				q.pop();				//넣은 값 지정하고 꺼내기
				for (int dir = 0; dir < 4; dir++) {
					//꺼낸 값의 인접 4방면 돌아주는 작업
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (nx < 0 || ny < 0 || nx >= n || ny >= m)
						continue;
					if (check[nx][ny] == 1 || image[nx][ny] == 0)
						continue;
					//nx ny 방문처리하고 nx ny도 돌아주는 작업 준비
					check[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
			}
			max_img = max(max_img, area);	//넓이와 기존의 max_img와 비교해서
											//더 큰값으로 바꾸기
		}
	}

	cout << img_cnt << '\n' << max_img;
	return 0;
}