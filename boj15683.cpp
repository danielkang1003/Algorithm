#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m, cctvCount, answer;
int map[8][8], c_map[8][8];
vector<pair<pair<int, int>, pair<int, int>>> cctv;	//�� 5���� cctv�� ������� cctv((x,y),(��ȣ,����)) �ʱ� ���� -1


////////////////////////////////////////////////////////////
//cctv�� ���� ������ �ʿ� Ȯ�� �����
void Right(int x, int y) {
	for (int j = y + 1; j < m; j++) {
		if (c_map[x][j] == 6) break;	//���� ����
		if (c_map[x][j] >= 1 && c_map[x][j] <= 5) continue;
		c_map[x][j] = -1;	//��ĭ�� -1�� ���Ҵٰ� ǥ��
	}
}

void Left(int x, int y) {
	for (int j = y - 1; j >= 0; j--) {
		if (c_map[x][j] == 6) break;
		if (c_map[x][j] >= 1 && c_map[x][j] <= 5) continue;
		c_map[x][j] = -1;
	}
}

void up(int x, int y) {
	for (int i = x - 1; i >= 0; i--) {
		if (c_map[i][y] == 6) break;
		if (c_map[i][y] >= 1 && c_map[i][y] <= 5) continue;
		c_map[i][y] = -1;
	}
}

void down(int x, int y) {
	for (int i = x + 1; i < n; i++) {
		if (c_map[i][y] == 6) break;
		if (c_map[i][y] >= 1 && c_map[i][y] <= 5) continue;
		c_map[i][y] = -1;
	}
}

//////////////////////////////////////////////////////////
void checkBlockedPoint() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			c_map[i][j] = map[i][j];
		}
	}
	int size = cctv.size();
	for (int i = 0; i < size; i++) {
		//�� cctv ���� ����
		if (cctv[i].second.first == 1) {
			//1�� cctv�� ��� �������� �� �� ����
			if (cctv[i].second.second == 0) Right(cctv[i].first.first, cctv[i].first.second);
			else if (cctv[i].second.second == 1) Left(cctv[i].first.first, cctv[i].first.second);
			else if (cctv[i].second.second == 2) down(cctv[i].first.first, cctv[i].first.second);
			else if (cctv[i].second.second == 3) up(cctv[i].first.first, cctv[i].first.second);
		}
		else if (cctv[i].second.first == 2) {
			//2�� cctv�� ���� �Ǵ� �� �Ʒ��� �� �� ����
			if (cctv[i].second.second == 0 || cctv[i].second.second == 1) {
				Right(cctv[i].first.first, cctv[i].first.second);
				Left(cctv[i].first.first, cctv[i].first.second);
			}
			else if (cctv[i].second.second == 2 || cctv[i].second.second == 3) {
				up(cctv[i].first.first, cctv[i].first.second);
				down(cctv[i].first.first, cctv[i].first.second);
			}
		}
		else if (cctv[i].second.first == 3) {
			//3�� cctv�� ���� �������� ����
			if (cctv[i].second.second == 0) {
				up(cctv[i].first.first, cctv[i].first.second);
				Right(cctv[i].first.first, cctv[i].first.second);
			}
			if (cctv[i].second.second == 1) {
				Right(cctv[i].first.first, cctv[i].first.second);
				down(cctv[i].first.first, cctv[i].first.second);
			}
			if (cctv[i].second.second == 2) {
				down(cctv[i].first.first, cctv[i].first.second);
				Left(cctv[i].first.first, cctv[i].first.second);
			}
			if (cctv[i].second.second == 3) {
				Left(cctv[i].first.first, cctv[i].first.second);
				up(cctv[i].first.first, cctv[i].first.second);
			}
		}
		else if (cctv[i].second.first == 4) {
			if (cctv[i].second.second == 0) {
				Left(cctv[i].first.first, cctv[i].first.second);
				up(cctv[i].first.first, cctv[i].first.second);
				Right(cctv[i].first.first, cctv[i].first.second);
			}
			else if (cctv[i].second.second == 1) {
				up(cctv[i].first.first, cctv[i].first.second);
				down(cctv[i].first.first, cctv[i].first.second);
				Right(cctv[i].first.first, cctv[i].first.second);
			}
			else if (cctv[i].second.second == 2) {
				Left(cctv[i].first.first, cctv[i].first.second);
				Right(cctv[i].first.first, cctv[i].first.second);
				down(cctv[i].first.first, cctv[i].first.second);
			}
			else if (cctv[i].second.second == 3) {
				Left(cctv[i].first.first, cctv[i].first.second);
				up(cctv[i].first.first, cctv[i].first.second);
				down(cctv[i].first.first, cctv[i].first.second);
			}
		}
		else if (cctv[i].second.first == 5) {
			up(cctv[i].first.first, cctv[i].first.second);
			down(cctv[i].first.first, cctv[i].first.second);
			Left(cctv[i].first.first, cctv[i].first.second);
			Right(cctv[i].first.first, cctv[i].first.second);
		}
	}
}

int blockedArea() {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (c_map[i][j] == 0) sum++;
		}
	}
	return sum;
}

void dfs(int cnt) {
	//cctv�� ������ ������ ���� �ٲپ��ָ� ���� ����
	if (cnt == cctvCount) {
		checkBlockedPoint();
		answer = min(answer, blockedArea());
		return;
	}
	for (int i = 0; i < 4; i++) {
		//0: ��, 1: ��, 2: ��, 3: ��
		cctv[cnt].second.second = i;
		dfs(cnt + 1);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] >= 1 && map[i][j] <= 5) {
				//1~5���� cctv �ϴ� ����
				cctv.push_back({ {i,j}, {map[i][j], -1} });
			}
		}
	}
	cctvCount = cctv.size();
	answer = 987654321;
	dfs(0);
	cout << answer;
	return 0;
}