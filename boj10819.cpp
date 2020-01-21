#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int arr[8];
int check[8];
vector<int> v;
int maxNum = -1;

//순열을 돌리면서 절대값을 계속 더해주고 정답이 최대인 값을 저장해두고 출력!
void dfs(int cnt) {
	int addAll = 0;
	if (cnt == n) {
		for (int i = 0; i < v.size() - 1; i++) {
			//cout << v[i] << ' ';
			addAll += abs(v[i] - v[i + 1]);
		}
		if (addAll > maxNum) maxNum = addAll;
		//cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		if (check[i] == 0) {
			check[i] = 1;
			v.push_back(arr[i]);
			dfs(cnt + 1);
			v.pop_back();
			check[i] = 0;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	//순열
	dfs(0);
	cout << maxNum;
	return 0;
}