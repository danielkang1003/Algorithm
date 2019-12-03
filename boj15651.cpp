#include<iostream>
//BOJ 15651 N �� M 3
using namespace std;

int n, m;
const int MAX = 7;
int arr[MAX];
//N�� M ���������ε�  ���� �ߺ��Ͽ� ����ؾ��ϹǷ�
//���ڰ� ������ ������� Ȯ���ϴ� check �迭�� �ʿ䰡 ����.
void dfs(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] + 1 << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		arr[k] = i;
		dfs(k + 1);
	}
}
int main() {
	cin >> n >> m;
	dfs(0);

	return 0;
}