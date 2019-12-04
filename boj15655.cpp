#include<iostream>
#include<algorithm>

using namespace std;

int n, m;
const int MAX = 8;
int arr[MAX], check[MAX], asc[MAX];

//오름차순으로 정렬된 숫자를 바탕으로 조합을 구현하면 된다
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
			arr[k] = asc[i];
			dfs(i, k + 1);
			check[i] = 0;
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> asc[i];
	}
	sort(asc, asc + n);
	//for (int i = 0; i < n; i++) {
	//	cout << asc[i] << ' ';
	//}
	//cout << '\n';
	dfs(0, 0);

	return 0;
}