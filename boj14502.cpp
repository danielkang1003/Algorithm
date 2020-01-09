#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
#include<cstring>
using namespace std;

int n, m, answer;
int lab[8][8];	//0�� ��ĭ, 1 �� ��, 2�� ���̷���
int clab[8][8];
int visit[8][8];
int check[64];	//8 * 8 ũ��
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

vector<pair<int, int>> Empty, Virus;
queue<pair<int, int>> q;
//bfs�� ��Ž �ʿ��� ����

void bfs(int a, int b) {
	q.push({ a,b });
	visit[a][b] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (visit[nx][ny] == 0 && clab[nx][ny] == 0) {
					clab[nx][ny] = 2;
					visit[nx][ny] = 1;
					q.push({ nx,ny });
				}
			}
		}
	}
}
//��ĭ(���� ����)�� ��
int safeArea() {
	int Cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (clab[i][j] == 0) {
				Cnt++;
			}
		}
	}
	return Cnt;
}

//���� 3���� �Ǹ� ���̷����� ������ Ȯ���� ������
void spreadVirus() {
	int Cnt = 0;
	for (int i = 0; i < n; i++) {//ī���س��� �迭���� ����ϱ�
		for (int j = 0; j < m; j++) {
			clab[i][j] = lab[i][j];
		}
	}
	memset(visit, 0, sizeof(visit));
	int Esize = Empty.size();
	for (int i = 0; i < Esize; i++) {
		if (Cnt == 3) break;	//�� ������ŭ ���鼭 ���� �������
		if (check[i] == 1) {
			int x = Empty[i].first;
			int y = Empty[i].second;
			clab[x][y] = 1;	//���� �����ְ�
			Cnt++;			//����� Ȯ���ϱ� ���� ����� ���� �ϳ��� ����
		}
	}
	//�׸��� ���̷����� ��Ʈ���� ����
	int size = Virus.size();
	for (int i = 0; i < size; i++) {
		int x = Virus[i].first;
		int y = Virus[i].second;
		bfs(x, y);	//���̷��� �ڸ����� bfs����
	}
	int safeAreaCnt = safeArea();	//bfs�� �� ���� ��ĭ�� ���� �ִ밪�� ����
	answer = max(safeAreaCnt, answer);
}

//���� ������ 3�� �Ǹ� ���̷��� ��Ʈ������
void buildWall(int idx, int cnt) {
	if (cnt == 3) {
		spreadVirus();
		return;
	}
	//�������� �� 3���� �����
	int size = Empty.size();
	for (int i = idx; i < size; i++) {
		if (check[i] == 0) {
			check[i] = 1;
			buildWall(i, cnt + 1);
			check[i] = 0;
		}
	}
}

//�� ĭ�� ���̷����� Ȯ���ϱ����� �� ���Ϳ� 0(��ĭ) �� 2(���̷���)�̸� �־��ֱ�
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> lab[i][j];
			if (lab[i][j] == 0) {
				Empty.push_back({ i,j });
			}
			if (lab[i][j] == 2) {
				Virus.push_back({ i,j });
			}
		}
	}

	//��Ʈ��ŷ ���� (�ε����� ī��Ʈ�� 0����)
	buildWall(0, 0);
	cout << answer;
	return 0;
}