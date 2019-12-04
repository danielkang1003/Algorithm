#include<iostream>

using namespace std;

//dfs �ߺ� ����
int n, m;
const int MAX = 8;
int arr[MAX];

void dfs(int idx, int k) {
	//ī��Ʈ k �� m�� �Ǹ� ���
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	//�ߺ��� ���ǹǷ� check �迭�� ��� �ȴ�.
	for (int i = idx; i < n; i++) {
		arr[k] = i + 1;
		dfs(i, k + 1);
	}
}

int main() {
	cin >> n >> m;
	dfs(0, 0);

	return 0;
}