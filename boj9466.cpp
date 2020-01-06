#include<iostream>

using namespace std;

int t, n;
int arr[100001];
bool check[100001], cycle[100001];
int cnt;
void dfs(int start) {
	check[start] = 1;
	int nxt = arr[start];
	if (check[nxt] == 0) dfs(nxt);
	else if (cycle[nxt] == 0) {
		for (int i = nxt; i != start; i = arr[i]) cnt++;
		cnt++; //자기 자신도 카운트
	}
	cycle[start] = 1;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];	//팀을 하고싶은 학생을 받으면서 
			check[i] = cycle[i] = 0;	//이전에 사용된 것이 있을 수 있으므로 초기화
		}
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (check[i] == 0) dfs(i);
		}
		cout << n - cnt << '\n';
	}
	return 0;
}