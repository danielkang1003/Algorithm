#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int n, m, answer = 987654321;
int map[50][50], c_map[50][50];
bool check[50][50], dfsCheck[10];	//���̷����� 10�� �ִ�Ƿ� dfscheck = 10ũ��

//���� ���� ������������ Ž��
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

vector<pair<int, int>> v, virus;	//������ ���� v�� ���̷��� ���� �� �ִ� �ڸ� ����, virus�� �������� ����� ���̷��� ��Ʈ��������
queue<pair<int, int>> q;			//�������� ����� ���̷��� ������

int minimum(int a, int b) {
	return a < b ? a : b;
}

bool checkPossible() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (c_map[i][j] == -1) continue;
			if (check[i][j] == 0) return false;
		}
	}
	return true;
}

void bfs() {
	int cnt = 0;
	while (!q.empty()) {
		int size = q.size();
		for (int s = 0; s < size; s++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;	//���� ��
				if (c_map[nx][ny] == -1) continue;						//��
				if (check[nx][ny] == 1) continue;						//�̹� �湮
				q.push({ nx,ny });
				c_map[nx][ny] = c_map[x][y] + 1;	//�̵��ð� + 1
				check[nx][ny] = 1;
				//cout << "���� (" << x << ',' << y << ") ���� (" << nx << ',' << ny << ")�� �̵�\n";
			}
		}
		if (size != 0) cnt++;
	}
	if (checkPossible() == true) answer = min(answer, cnt);
}

void copyMap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			c_map[i][j] = map[i][j];
		}
	}
}

void print() {
	cout << "==========���========\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << c_map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "======================\n";
}

void dfs(int idx, int cnt) {
	if (cnt == m) {	//�������� �̾Ƴ� ������ �������� ������� ����
		memset(check, 0, sizeof(check));	//�ּҽð��� ���� ���̱⿡ �Ź� �ʱ�ȭ���ֱ�
		copyMap();							//�ʵ� ���ο� �ʿ��� �ٽ��ؾ��ϹǷ� �ʱ�ȭ
		//cout << "���� �õ�:";
		for (int i = 0; i < virus.size(); i++) {
			//cout << "(" << virus[i].first << " " << virus[i].second << ") ";
			//ť�� �־��༭ ������
			q.push({ virus[i] });
			check[virus[i].first][virus[i].second] = 1;	//���� ���� �湮 ǥ��
			c_map[virus[i].first][virus[i].second] = 1;	//������ 1�� ����� ����. ���߿� �ּҽð����� -1 ���ֱ�
		}
		bfs();
		//print();
		//cout << '\n';
		return;
	}
	for (int i = idx; i < v.size(); i++) {	//v���� ���̷��� ���� �� �ִ� ���� ��ǥ�� �������. ����
		if (dfsCheck[i] == 0) {
			dfsCheck[i] = 1;
			virus.push_back({ v[i].first, v[i].second });
			dfs(i + 1, cnt + 1);
			virus.pop_back();
			dfsCheck[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				v.push_back({ i,j });
				map[i][j] = 0;	//���̷����� �ִ� �ڸ��� ���õ����ʾ� �����ʴ´ٸ� 0���� ������༭ �̵��� �� �ֵ��� ����
			}
			else if (map[i][j] == 1) {
				map[i][j] = -1;	//-1�� ���� �ּҽð��� ��ġ�� �ʵ���
			}
		}
	}
	dfs(0, 0);	//���̷��� �������� �ּ� �ð� ����� ��
	if (answer == 987654321) cout << "-1\n";
	else cout << answer - 1 << '\n';
	return 0;
}