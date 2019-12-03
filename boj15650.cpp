#include<iostream>

using namespace std;

int n, m;
const int MAX = 9;
int arr[MAX], check[MAX];

void dfs(int idx, int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = idx; i < n; i++) {
		if (check[i] == 0) {
			check[i] = 1;
			arr[k] = i + 1;		//처음 수행 시k = 0, i = idx = 0이므로 + 1해주기
			//또는 위의 프린트 부분에서 arr[i] + 1해주기
			dfs(i + 1, k + 1);
			check[i] = 0;
		}
	}
}

int main() {
	cin >> n >> m;
	//idx = 0, cnt = 0부터 시작
	dfs(0, 0);
	return 0;
}