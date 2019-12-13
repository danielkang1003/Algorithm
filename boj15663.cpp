#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

int n, m;
int arr[8];
int check[8];
map<int, int> numCnt;
//map으로 key value를 줘서 확인

void dfs(int idx, int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[check[i]] << ' ';
		}
		cout << '\n';
		return;
	}
	if (idx == n) return;

	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
		if (numCnt[arr[i]]) {
			numCnt[arr[i]]--;
			check[idx] = i;
			dfs(idx + 1, k + 1);
			numCnt[arr[i]]++;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (!numCnt.count(num)) {
			numCnt[num] = 1;
			arr[i] = num;
		}
		else {
			numCnt[num]++;
		}
	}
	sort(arr, arr + n);
	dfs(0, 0);

	return 0;
}