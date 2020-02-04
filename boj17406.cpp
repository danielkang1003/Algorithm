#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

struct XYInfo {
	int r, c, s;
};

int n, m, k, r, c, s;
int map[51][51], c_map[51][51];

//==============================================
// (1,1) ���� ����:								|
/*												|
1. dx dy�� 0�� ��								|
(1,1) + (0,1) => (1,2) ���������� ����. ���ʹ���|
2. dx dy�� 1�� ��								|
(1,1) + (0, -1) => (1,0) �������� ����. ���ʹ���|
3. dx dy�� 2�� ��								|
(1,1) + (1, 0) => (2,1) �Ʒ��� ����. ���� ����	|
4. dx dy�� 3�� ��								|
(1,1) + (-1,0) => (0,1) ���� ����. ���� ����	|
//==============================================
*/
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

vector<int> order;
vector<XYInfo> v;
bool check[51];
int answer;

void copyMap() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			c_map[i][j] = map[i][j];
}

//�ð������ �ƴ� �ݴ� �������� ����
int changeDir(int dir) {
	if (dir == 0) return 3;	//�� -> ��
	else if (dir == 1) return 2; //�� -> ��
	else if (dir == 2) return 0; //�� -> ��
	else if (dir == 3) return 1; //�� -> ��
}

void startRotate(XYInfo v) {
	int upX = v.r - v.s;
	int upY = v.c - v.s;
	int botX = v.r + v.s;
	int botY = v.c + v.s;
	/*cout << "���� �� (x,y): " << upX << ',' << upY << ' ' << " ������ �Ʒ� (x,y): " << botX << ',' << botY <<
		"\n���� �� ��:" << c_map[upX][upY] << " ������ �Ʒ� ��: " << c_map[botX][botY] <<'\n';*/
		//������ �迭������ �ݺ�Ƚ�� ���ؾ���
	int times = (botX - upX) / 2;
	//cout << "�迭 ȸ�� Ƚ��: " << times<< '\n';
	for (int i = 0; i < times; i++) {
		//cout << "���� �迭�� �������ϴ� �� Ƚ�� " << times << " �� ���� i �� ��: " << i << '\n';
		int x = upX;
		int y = upY;
		int temp = c_map[x][y];
		int dir = 2;	//���� ���� ����
		while (true) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			//cout << "cmap[" <<x << ","<<y<<"] = " << c_map[x][y] << " cmap[" << nx << ',' << ny <<"] = " << c_map[nx][ny]<<'\n';

			if (nx == upX && ny == upY) {
				c_map[x][y] = temp;
				//cout << "ó����ġ�� ���ƿԽ��ϴ�. cmap[" << x << "," <<y << "]  �� " << c_map[x][y] <<"�Դϴ�\n";
				break;
			}
			if (upX <= nx && nx <= botX - i && upY <= ny && ny <= botY - i) {
				//�迭���� �迭�� ������ ���� -i�� ���ش�. ù ������ 0 �ι�°�� -1 ...�̷������� ��ĭ�� ��
				//cout << "���� nx, ny: " << nx << "," << ny << " nx ���� ��: " << upX << "~" << botX - i << " ny ���� ��: " << upY << "~" << botY - i << '\n';
				c_map[x][y] = c_map[nx][ny];
				x = nx;
				y = ny;
			}
			else {
				//if (dir == 0) cout << "���ʿ��� ";
				//else if (dir == 1) cout << "���ʿ��� ";
				//else if (dir == 2) cout << "���ʿ��� ";
				//else if (dir == 3) cout << "���ʿ��� ";
				dir = changeDir(dir);
				/*if (dir == 0) {
					cout << "�������� ";
				}
				else if (dir == 1) {
					cout << "�������� ";
				}
				else if (dir == 2) {
					cout << "�������� ";
				}
				else if (dir == 3) {
					cout << "�������� ";
				}
				cout << "������ ����Ǿ����ϴ�.\n";*/
			}
		}
		upX++, upY++;	//�迭���� �迭�� �����ֱ� ���� ���� ���� ��ǥ ++
	}
}

int findMinAns() {
	int minSum = INT_MAX;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= m; j++) {
			sum += c_map[i][j];
		}
		if (minSum > sum) {
			//cout << "minSum �� " << minSum << " ���� sum " << sum << " �� �۽��ϴ�.\n";
			minSum = sum;
		}
	}
	return minSum;
}

void dfs(int cnt) {
	if (cnt == k) {
		//������ ���� ����� �޶����Ƿ� ������ ���� ī���ؼ� ���
		copyMap();
		//���� �� �ִ� ��ŭ ������ ���ߴٸ�
		//cout << "����:\n";
		int oSize = order.size();
		for (int i = 0; i < oSize; i++) {
			//cout << "#" << order[i] << ' ';
			//cout << v[order[i]].r << ' ' << v[order[i]].c << ' ' << v[order[i]].s << '\n';
			startRotate(v[order[i]]);	//�� ���� ���ؼ� �迭 ������
		}
		//cout << '\n';
		answer = min(answer, findMinAns());
		//cout << "�迭�� ������ �� �� �ּ� ����: " << answer << '\n';
		return;
	}


	//� ������ ������ ����
	int size = v.size();	//v[0]���� 3 4 2, v[1]���� 4 2 1�� �������
	for (int i = 0; i < size; i++) {
		if (check[i] == 0) {
			check[i] = 1;
			order.push_back(i);
			dfs(cnt + 1);
			order.pop_back();
			check[i] = 0;
		}
	}
}

int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> map[i][j];
	for (int i = 0; i < k; i++) {
		cin >> r >> c >> s;
		v.push_back({ r,c,s });
	}
	answer = INT_MAX;
	dfs(0);
	cout << answer;

	return 0;
}