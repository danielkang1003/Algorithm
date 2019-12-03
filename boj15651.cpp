#include<iostream>
//BOJ 15651 N 과 M 3
using namespace std;

int n, m;
const int MAX = 7;
int arr[MAX];
//N과 M 순열문제인데  숫자 중복하여 출력해야하므로
//숫자가 이전에 사용됬는지 확인하는 check 배열이 필요가 없다.
void dfs(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] + 1 << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		arr[k] = i;
		dfs(k + 1);
	}
}
int main() {
	cin >> n >> m;
	dfs(0);

	return 0;
}