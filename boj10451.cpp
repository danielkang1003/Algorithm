#include<iostream>

using namespace std;

int t, n;
int arr[1001];
bool check[1001];

//순환하며 싸이클 확인
void dfs(int start) {
	check[start] = 1;
	int nxt = arr[start];
	if (check[nxt] == 0) dfs(nxt);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];	//배열 넣으면서
			check[i] = 0;	//check배열도 초기화 해주기 while loop이므로
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (check[i] == 0) {	//방문하지 않으면 dfs
				dfs(i);
				cnt++;				//다돌면 1 증가.
			}
		}
		cout << cnt << '\n';
	}

	return 0;
}