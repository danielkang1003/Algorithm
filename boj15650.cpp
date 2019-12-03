#include<iostream>

using namespace std;

int n, m;
const int MAX = 9;
int arr[MAX], check[MAX];

void dfs(int idx, int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = idx; i < n; i++) {
		if (check[i] == 0) {
			check[i] = 1;
			arr[k] = i + 1;		//ó�� ���� ��k = 0, i = idx = 0�̹Ƿ� + 1���ֱ�
			//�Ǵ� ���� ����Ʈ �κп��� arr[i] + 1���ֱ�
			dfs(i + 1, k + 1);
			check[i] = 0;
		}
	}
}

int main() {
	cin >> n >> m;
	//idx = 0, cnt = 0���� ����
	dfs(0, 0);
	return 0;
}