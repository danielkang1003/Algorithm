#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int n;
char paper[100][100];
int check[100][100];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int rgb, rrb;	//�Ϲ���(rgb), ����(rrb) ���� ����

void bfs(int i, int j) {
	queue<pair<int, int>> q;
	q.push({ i,j });
	check[i][j] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (check[nx][ny] == 1 || paper[nx][ny] != paper[x][y]) continue;
			//�湮�߰ų�, ���� ���� ���� ���ϴ°��� �ٸ��ٸ� �Ѿ��
			//�湮���� �ʰ� ���ϴ� ���� ������ push
			q.push({ nx,ny });
			check[nx][ny] = 1;
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}

	//�Ϲ��� bfs
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == 0) {
				bfs(i, j);
				rgb++;
			}
		}
	}
	
	//�ʱ�ȭ�� �ؼ� ���� �� ����
	memset(check, 0, sizeof(check));
	
	//Green�� Red�� ����
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (paper[i][j] == 'G')
				paper[i][j] = 'R';
		}
	}
	//bfs�ѹ� �� ������
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == 0) {
				bfs(i, j);
				rrb++;
			}
		}
	}
	cout << rgb << ' ' << rrb;


	return 0;
}