#include<iostream>
#include<queue>
using namespace std;

int n, k;
int hideAndSeek[100001];// 0�� ��, 1�� ����(����), 9 �� ����
int check[100001];
int dx[2] = { -1,1 };

void bfs(int n) {
	queue<pair<int, int>> q;
	q.push({ n, 0 });	//�������� �ڸ��� �ð�
	check[n] = 1;
	while (!q.empty()) {
		int x = q.front().first;	//������ �ڸ�
		int time = q.front().second;	//������ �̵��� Ƚ��(��)
		if (x == k) {
			cout << time << '\n';
			break;
		}
		q.pop();
		for (int dir = 0; dir < 2; dir++) {
			int nx = x + dx[dir];
			if (nx < 0 || nx >= 100001) continue;
			if (hideAndSeek[nx] == 0 && check[nx] == 0) {
				q.push({ nx, time + 1 });
				check[nx] = 1;
				hideAndSeek[nx] = hideAndSeek[x] + 1;	//Ȯ�ο�
			}
		}
		if (2 * x < 100001) {
			if (check[2 * x] == 0) {
				q.push({ 2 * x, time + 1 });
				check[2 * x] = 1;
				hideAndSeek[2 * x] = hideAndSeek[x] + 1;
			}
		}
	}

}

int main() {
	cin >> n >> k;
	//Ȯ�ο�
	//hideAndSeek[n] = 1;	//���� (����)
	//hideAndSeek[k] = 9;	//����
	//for (int i = 1; i <= 20; i++) cout << hideAndSeek[i] << ' ';
	//cout <<'\n';
	bfs(n);
	//for (int i = 1; i <= 20; i++) cout << hideAndSeek[i] << ' ';

	return 0;
}
