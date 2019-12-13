#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
const int MAX = 7;
int arr[MAX];

//순열. check 배열 필요없음
void dfs(int* asc, int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		arr[k] = asc[i];
		dfs(asc, k + 1);
	}
}

int main() {
	//asc에 max크기로 안하고 n크기 만큼 동적할당해주고 진행하였음
	cin >> n >> m;
	int* asc = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> asc[i];
	}
	sort(asc, asc + n);
	dfs(asc, 0);
	delete[] asc;
	return 0;
}