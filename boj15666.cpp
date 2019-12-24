#include<iostream>
#include<algorithm>
#include<set>
//조합, 숫자 중복 허용

using namespace std;

int n, m;
int arr[8];
int saved[8];
set<string> s;

bool duplicate() {
	string temp = "";
	for (int i = 0; i < m; i++) {
		temp += saved[i];
	}
	if (s.find(temp) == s.end()) {
		s.insert(temp);
		return false;
	}
	else return true;
}

void dfs(int idx, int k) {
	if (k == m) {
		if (duplicate() == 0) {
			for (int i = 0; i < m; i++) {
				cout << saved[i] << ' ';
			}
			cout << '\n';
		}
		return;
	}

	for (int i = idx; i < n; i++) {
		saved[k] = arr[i];
		dfs(i, k + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	dfs(0, 0);
	return 0;
}