#include<iostream>

using namespace std;

int n, m;
const int MAX = 8;

int arr[MAX], check[MAX];

void dfs(int k) {//k 수 부터 시작
	//m개를 선택하면 arr 출력
	//arr[0]은 0부터 시작이므로 + 1을 해줘서 출력
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] + 1 << ' ';
		}
		cout << '\n';
		return;
	}
	//만약 방문하지 않았으면 arr 채워주고, 방문 처리해주고
	//k를 1 증가 시켜서 dfs 돌아주고 끝나면 방문 처리 해제
	for (int i = 0; i < n; i++) {
		if (check[i] == 0) {
			arr[k] = i;
			check[i] = 1;
			dfs(k + 1);
			check[i] = 0;
		}
	}
}

int main() {
	cin >> n >> m;
	dfs(0);

	return 0;
}