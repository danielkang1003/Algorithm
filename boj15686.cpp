#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

int n, m;
int answer;
int map[51][51];
vector<pair<int, int>> chicken, home, combi;
int combi_check[13];	//ġŲ���� �ִ� 13��
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int startFindMinWay() {
	int sum = 0;

	for (int i = 0; i < home.size(); i++) {
		int hx = home[i].first;
		int hy = home[i].second;
		int dist = INT_MAX; //�Ÿ��� �ּ��� ������ ��� �ٲپ��� ����
		//cout << "�� (" << hx << ',' << hy << ")�� ";
		for (int j = 0; j < combi.size(); j++) {
			int cx = combi[j].first;
			int cy = combi[j].second;
			int d = abs(cx - hx) + abs(cy - hy);	//��� ġŲ���� ���� �Ÿ�
			//cout << "ġŲ�� (" << cx << "," << cy << ") ���� �Ÿ�: " << d << '\n';
			if (dist > d) dist = d;
		}
		sum += dist;
	}
	return sum;
}


//�������� ġŲ�� ����
void dfs(int idx, int cnt) {
	if (cnt == m) {
		answer = min(answer, startFindMinWay());
		//cout << "����� �Ÿ�: " << answer <<'\n';
		return;
	}
	for (int i = idx; i < chicken.size(); i++) {
		if (combi_check[i] == 0) {
			combi_check[i] = 1;
			combi.push_back({ chicken[i].first, chicken[i].second });
			dfs(i, cnt + 1);
			combi.pop_back();
			combi_check[i] = 0;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				home.push_back({ i,j });
			}
			else if (map[i][j] == 2) {
				chicken.push_back({ i,j });
			}
		}
	}

	answer = INT_MAX;
	dfs(0, 0);
	cout << answer;
	return 0;
}