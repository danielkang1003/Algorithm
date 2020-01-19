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
		computer[b].push_back(a);	//b 해킹하면 a 해킹 가능
	}
	vector<int> answer;
	for (int i = 1; i <= n; i++) {
		memset(check, 0, sizeof(check));
		num = 0;
		dfs(i);	//모든 컴퓨터를 dfs를 돌면서 해킹할 수 있는 컴퓨터 개수를 정함.
		if (temp == num) {//만약 이전 컴퓨터를 해킹한 수랑 같으면 답에 푸시
			answer.push_back(i);
		}
		else if (temp < num) {	//그렇지않고 현재 컴퓨터가 더 많다면 답을 다 지우고 다시 푸시
			temp = num;
			answer.clear();
			answer.push_back(i);
		}
	}

	sort(answer.begin(), answer.end());	//답은 오름차순으로 출력
	int size = answer.size();
	for (int i = 0; i < size; i++) {
		cout << answer[i] << ' ';
	}
	cout << '\n';
	return 0;
}