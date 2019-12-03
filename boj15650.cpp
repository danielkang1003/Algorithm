#include<iostream>

using namespace std;

int n, m;
const int MAX = 9;
int arr[MAX], check[MAX];

//���޹޴� ���� �߿� idx�� ���� ����, k �� ī��Ʈ
void dfs(int* arr, int* check, int n, int m, int idx, int k) {
	//ī��Ʈ�� ���ڰ� m�̶� �������� ����ϰ� ����
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	//idx�� 1���� ����. �ϳ� �� ���� i�� k�� ��� ���������ش�.
	//���� N & M(1)�� ����
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