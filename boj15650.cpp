#include<iostream>

using namespace std;

int n, m;
const int MAX = 9;
int arr[MAX], check[MAX];

//전달받는 인자 중에 idx는 시작 숫자, k 는 카운트
void dfs(int* arr, int* check, int n, int m, int idx, int k) {
	//카운트한 숫자가 m이랑 같아지면 출력하고 종료
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	//idx는 1부터 시작. 하나 더 들어가면 i와 k를 모두 증가시켜준다.
	//이하 N & M(1)과 동일
	for (int i = idx; i <= n; i++) {
		if (check[i] == 0) {
			check[i] = 1;
			arr[k] = i;
			dfs(arr, check, n, m, i + 1, k + 1);
			check[i] = 0;
		}
	}
}

int main() {
	cin >> n >> m;
	dfs(arr, check, n, m, 1, 0);

	return 0;
}