#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int r, c;
bool meet;
char map[1500][1500];
bool check[1500][1500];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

queue<pair<int, int>> swanQ, swanNQ, Q, NQ;	//���� ���� ť, ���� ť, ���� ���� ť, ���� ť
pair<int, int> swan;
//�ð��ʰ��� ������ ȣ�� ����.
//������ Ǯ�̸� ���� bool type �迭 �ΰ� (���� ���� ���� ���� ������ �̵��� Ȯ����)
//���� ���� ���� �ʿ��� �ѹ��� ��ȯ�����ֱ� ���� ���� ���� ��ġ�� ���� vector
//�������� ���� �ݺ����� �� ������ �ʱ�ȭ���Ѽ� �ð��ʰ��� �� ���ۿ� ������.
//Ǯ�̸� ã�ƺ��� ���� ť�� ������ �̵� Q�� ���� ���� ���Ǹ��� ���� �湮 ���� ���Ͽ� �־��ִ� ������� Ǭ�ٰ� �ؼ� �����Ͽ��� Ǯ����.
void input() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'L') {
				swan.first = i;
				swan.second = j;
			}
			if (map[i][j] != 'X') {
				Q.push({ i,j });	//���� �� �־��ش�
			}
		}
	}
	//cout << "������ ��ġ: " << swan.first << " " << swan.second << '\n';
}

void swanMove() {
	while (!swanQ.empty() && meet == false) {
		int x = swanQ.front().first;
		int y = swanQ.front().second;
		swanQ.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (check[nx][ny] == 1) continue;
			if (map[nx][ny] == '.') {	//���̸� �̵��ϰ� �湮ǥ���ϱ�
				swanQ.push({ nx,ny });
				check[nx][ny] = 1;
			}
			else if (map[nx][ny] == 'X') {	//���϶�� ������ ����� �� �̵����� ������ ���� �̵��� �־��ֱ�
				swanNQ.push({ nx,ny });
				check[nx][ny] = 1;
			}
			else if (map[nx][ny] == 'L') {	//�ٸ� ���������� ����
				check[nx][ny] = 1;
				meet = true;
				break;
			}
		}
	}
}

void meltingIce() {
	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (map[nx][ny] == 'X') {
				map[nx][ny] = '.';	//���������� �����
				NQ.push({ nx,ny });
			}
		}
	}
}

void print(int day) {
	cout << "========Day " << day << "=======\n";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
	cout << "===================\n";
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	input();
	int day = 0;
	meet = false;
	swanQ.push({ swan.first, swan.second });
	check[swan.first][swan.second] = 1;

	while (meet == false) {
		swanMove();	//���ϰ� ������� ������ ����
		if (meet == false) {
			meltingIce();	//���� �쿩��
			Q = NQ;			//������ ���ϰ� ���� ���� �����ͷ� �־���
			swanQ = swanNQ;	//������ �̵��� ���� ��ǥ�� �־���
			while (!NQ.empty()) NQ.pop();	//�־��ְ� �� �� ������ ����ֱ�
			while (!swanNQ.empty()) swanNQ.pop();
			//print(day);
			day++;
		}
	}
	cout << day << '\n';

	return 0;
}