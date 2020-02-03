#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//�迭�� ������ ���� �߿��� ������ ������...
//�ٸ� ��� Ǯ�̸� ���� ������ �Ϸ��Ͽ�����, ���� ������ ���� �ʾҴ�.
//���� �ٽ� Ǯ� ����

struct XY {
	int r, c, s;
};	//�� �� ����

int n, m, k, r, c, s;
int map[51][51], c_map[51][51];
bool check[51];
int answer;
vector<XY> v;	//�������ϴ� ���� ���� ����
vector<int> order;	//������ ������ ���ϱ� ���� ����

//(1,1) ���� :
//dx,y[0]: (1,1) +(0,1) => (1,2): �� -> �� (���� ����)
//dx,y[1]: (1,1) +(0,-1) => (1,0): �� -> �� (���� ����)
//dx,y[2]: (1,1) +(1,0) => (2,1): �� -> �Ʒ� (���� ����)
//dx,y[3]: (1,1) +(-1,0) => (0,1): �Ʒ� -> �� (���� ����)
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int changeDir(int dir) {
	//�ݽð� ����
	if (dir == 0) return 3;
	else if (dir == 1) return 2;
	else if (dir == 2) return 0;
	else if (dir == 3) return 1;
}

void rotate(XY xy, int cnt) {
	//int upX, int upY, int botX, int botY
	int upX = xy.r - xy.s;
	int upY = xy.c - xy.s;
	int botX = xy.r + xy.s;
	int botY = xy.c + xy.s;
	//int t = cnt;
	//cout << "#" <<t + 1 << " "  << "���� �� ��ǥ x,y: " << upX << ' ' << upY << " \n������ �Ʒ� ��ǥ x,y: " << botX << ' ' << botY << '\n';
	//cout<< "�� �Ʒ� ��: " << up << " " << bot << '\n';
	int turnCnt = (botX - upX) / 2;	//�簢�� �ݺ� ��(botX�� ���ϴ� ���̱⿡ ū �� - upX ���� x��)
	for (int i = 0; i < turnCnt; i++) {
		int x = upX;
		int y = upY;
		int temp = c_map[x][y];
		int dir = 2;
		//cout << "x,y ��ǥ: " << x << ',' << y << "����: " << dir << "��: " << c_map[x][y] << "temp ��: " << temp << '\n';
		while (true) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx == upX && ny == upY) {
				c_map[x][y] = temp;
				break;
			}
			if (upX <= nx && nx <= botX - i && upY <= ny && ny <= botY - i) {
				//cout << dir << "���⿡ ���� ��ǥ" << nx << ' ' << ny << "��: " << c_map[nx][ny] << '\n';
				c_map[x][y] = c_map[nx][ny];
				x = nx;
				y = ny;
			}
			else {
				dir = changeDir(dir);
			}
		}
		upX++;
		upY++;
	}
	//cout << "�迭 ���� �� ��: \n";
	//for (int i = 1; i <= n; i++) {
	//	for (int j = 1; j <= m; j++) {
	//		cout << c_map[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}
}

void input() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		cin >> r >> c >> s;
		v.push_back({ r,c,s });
	}
}

int cal() {
	int val = 999999999;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= m; j++) {
			sum += c_map[i][j];
		}
		val = min(val, sum);
	}
	return val;
}

void dfs(int cnt) {
	if (cnt == k) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				c_map[i][j] = map[i][j];

		for (int i = 0; i < order.size(); i++) {
			//cout << "order: " << order[i] << '\n';	
			rotate(v[order[i]], i);//�������ϴ� ������ ���� �迭�� �����ش�.
		}
		//cout << '\n';
		answer = min(answer, cal());
		return;
	}
	//�迭�� ��� �������Ŀ� ���� ���� �޶����Ƿ� ���� ���
	for (int i = 0; i < v.size(); i++) {
		if (check[i] == 0) {
			check[i] = 1;
			order.push_back(i);	//�迭 ���� ������ ����
			dfs(cnt + 1);
			order.pop_back();
			check[i] = 0;
		}
	}
}


int main() {
	answer = 987654321;
	input();
	dfs(0);
	cout << answer << '\n';
	return 0;
}