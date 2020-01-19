#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int n, m, a, b, temp, num;
vector<int> computer[10001];
bool check[10001];

void dfs(int x) {
	check[x] = 1;
	int size = computer[x].size();
	for (int i = 0; i < size; i++) {
		int nx = computer[x][i];
		if (check[nx] == 0) {
			num++;
			dfs(nx);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		computer[b].push_back(a);	//b ��ŷ�ϸ� a ��ŷ ����
	}
	vector<int> answer;
	for (int i = 1; i <= n; i++) {
		memset(check, 0, sizeof(check));
		num = 0;
		dfs(i);	//��� ��ǻ�͸� dfs�� ���鼭 ��ŷ�� �� �ִ� ��ǻ�� ������ ����.
		if (temp == num) {//���� ���� ��ǻ�͸� ��ŷ�� ���� ������ �信 Ǫ��
			answer.push_back(i);
		}
		else if (temp < num) {	//�׷����ʰ� ���� ��ǻ�Ͱ� �� ���ٸ� ���� �� ����� �ٽ� Ǫ��
			temp = num;
			answer.clear();
			answer.push_back(i);
		}
	}

	sort(answer.begin(), answer.end());	//���� ������������ ���
	int size = answer.size();
	for (int i = 0; i < size; i++) {
		cout << answer[i] << ' ';
	}
	cout << '\n';
	return 0;
}