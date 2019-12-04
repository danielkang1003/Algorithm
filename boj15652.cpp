#include<iostream>

using namespace std;

//dfs 중복 조합
int n, m;
const int MAX = 8;
int arr[MAX];

void dfs(int idx, int k) {
	//카운트 k 가 m이 되면 출력
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	//중복이 허용되므로 check 배열이 없어도 된다.
	for (int i = idx; i < n; i++) {
		arr[k] = i + 1;
		dfs(i, k + 1);
	}
}

int main() {
	cin >> n >> m;
	dfs(0, 0);

	return 0;
}