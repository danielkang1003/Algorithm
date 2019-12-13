#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
const int MAX = 8;
int arr[MAX];

//중복조합 문제
void dfs(int* asc, int idx, int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = idx; i < n; i++) {
		arr[k] = asc[i];
		dfs(asc, i, k + 1);
	}
}

int main() {
	cin >> n >> m;
	int* asc = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> asc[i];
	}
	sort(asc, asc + n);
	/*for (int i = 0; i < n; i++) {
		cout << asc[i] << ' ';
	}*/
	dfs(asc, 0, 0);

	delete[] asc;
	return 0;
}