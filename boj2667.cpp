#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int map[25][25];	//�Է¹޾Ƽ� ���� �迭
int check[25][25];	//�湮�ߴ��� Ȯ��
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int num;			//���� �� ��� ����Ʈ�� �ִ���
vector<int> totalApt;//���� �� ����Ʈ �� num�� �ֱ����� ����

void bfs(int i, int j) {
	queue<pair<int, int>> q;
	q.push({ i,j });
	check[i][j] = 1;
	num++;	//�����ȿ� ��� ����Ʈ�� �ִ��� �����ֱ�
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
			num++;	//���� ������������ num�������Ѽ� ���� �� ����Ʈ ���� Ȯ��
		}
	}
	totalApt.push_back(num);	//������ ����Ʈ ���� ���Ϳ� Ǫ��
	num = 0;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s("%1d", &map[i][j]);
		}
	}

	int cnt = 0;	//�� ��� ������ �ִ��� Ȯ���ϱ� ���� ���� ���� �� �ʱ�ȭ
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//����Ʈ(1)�̰ų�, �湮���ϸ� bfs ����, ������ ���� ���� � ������ �ִ��� Ȯ��
			if (map[i][j] == 1 && check[i][j] == 0) {
				cnt++;
				bfs(i, j);
			}
		}
	}
	sort(totalApt.begin(), totalApt.end());	//�������� ����
	cout << cnt << '\n';
	int size = totalApt.size();		//����Ʈ ������ŭ ���Ͱ� ������ �ȴ�
	for (int i = 0; i < size; i++)
		cout << totalApt[i] << '\n';
	return 0;
}