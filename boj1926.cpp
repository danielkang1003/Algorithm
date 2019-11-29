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
	//�Է�
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> image[i][j];

	int max_img = 0;//�׸� �ִ� ����
	int img_cnt = 0;//�׸� ����

	//BFS
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (image[i][j] == 0 || check[i][j]) continue;
			img_cnt++;
			queue<pair<int, int>> q;	//��ǥ�� ���� ť �����
			q.push(make_pair(i, j));	//i,j�� ��ǥ�� bfs���� �غ�
			check[i][j] = 1;			//i,j �湮 ó��
			int area = 0;		//�׸��� ����
			while (!q.empty()) {		//q�� ���� ������
				area++;
				int x = q.front().first;
				int y = q.front().second;
				q.pop();				//���� �� �����ϰ� ������
				for (int dir = 0; dir < 4; dir++) {
					//���� ���� ���� 4��� �����ִ� �۾�
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (nx < 0 || ny < 0 || nx >= n || ny >= m)
						continue;
					if (check[nx][ny] == 1 || image[nx][ny] == 0)
						continue;
					//nx ny �湮ó���ϰ� nx ny�� �����ִ� �۾� �غ�
					check[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
			}
			max_img = max(max_img, area);	//���̿� ������ max_img�� ���ؼ�
											//�� ū������ �ٲٱ�
		}
	}

	cout << img_cnt << '\n' << max_img;
	return 0;
}