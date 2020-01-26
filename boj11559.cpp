#include<iostream>
#include<cstring>
#include<vector>

#define endl '\n';
using namespace std;

char puyo[12][7];	//���� �ΰ��� ó������ 6 + 1
bool check[12][7];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int possibleCnt = 0; //�������� �װ� �̻��� �Ǹ� ��Ʈ���� ���� ����


vector<pair<int, int>> temp, vec;

void dfs(int x, int y) {

	cout << "\n(DFS ����) ���� dfs�� ���� ���� : " << puyo[x][y] << "�̰�, ��ǥ��" << x << " " << y << endl;

	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		//���� ���� ó�� (1. ���� ���, 2. �湮������ �н�, 3. �� �ٸ��� �н�, 4.��ĭ�̸� �н�
		if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue;
		if (check[nx][ny] == 1) continue;
		if (puyo[nx][ny] != puyo[x][y]) continue;
		if (puyo[nx][ny] == '.') continue;
		//���ǿ� �����ϸ� ����
		possibleCnt++;
		check[nx][ny] = 1;
		temp.push_back({ nx,ny });

		cout << "\t ���ǿ� �����ϹǷ� temp ���Ϳ� �����մϴ�.\n";
		cout << "\t temp ���Ϳ� ���� ��ǥ�� nx: " << nx << " ny: " << ny << "�̰� ����ִ� �� ������ " << temp.size() << endl;
		cout << "temp ������ ���� ����:" << endl;
		for (int i = 0; i < temp.size(); i++) {
			cout << "\tx: " << temp[i].first << " y: " << temp[i].second << endl;
		}

		dfs(nx, ny);
	}
}

int main() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> puyo[i][j];
		}
	}

	bool flag;
	int answer = 0;
	while (true) {
		flag = 0;
		memset(check, 0, sizeof(check));
		vec.clear();
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (puyo[i][j] != '.' && check[i][j] == 0) {
					possibleCnt = 1;
					temp.push_back({ i,j });
					check[i][j] = 1;
					cout << "temp ���Ϳ� �� ��: " << puyo[i][j] << " �̰� i�� j�� " << temp.front().first << "�� " << temp.front().second << endl;
					dfs(i, j);

					if (possibleCnt >= 4) {
						cout << "tempCnt�� 4�̻��̿��� ����\n���� tempCnt :" << possibleCnt << endl;
						flag = 1;	//���� �װ� �̻� �ֺ��� �������� ��Ʈ���� ���� ǥ�ó���
						int size = temp.size();	//dfs�� ���� �������� �͵�

						cout << "���� ���� ����: " << size << endl;

						for (int i = 0; i < size; i++) {
							vec.push_back(temp[i]);	//��Ʈ�� �� �־��ֱ�
						}

						cout << "��Ʈ�� ��ǥ��: " << endl;
						for (int i = 0; i < size; i++) {
							cout << vec[i].first << " " << vec[i].second << endl;
						}

					}
					temp.clear();
				}
			}
		}

		int size = vec.size();
		for (int i = 0; i < size; i++) {
			int x = vec[i].first;
			int y = vec[i].second;
			puyo[x][y] = '.';	//�ٲپ��ֱ�
		}

		for (int i = 10; i >= 0; i--) {
			for (int j = 0; j < 6; j++) {
				if (puyo[i][j] == '.') continue;
				int temp = i;
				while (true) {
					if (temp == 11 || puyo[temp + 1][j] != '.') break;
					puyo[temp + 1][j] = puyo[temp][j];
					puyo[temp][j] = '.';
					temp++;
				}
			}
		}

		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				cout << puyo[i][j] << ' ';
			}
			cout << '\n';
		}

		if (flag == true) answer++;
		else break;
	}
	cout << answer << endl;

	return 0;
}