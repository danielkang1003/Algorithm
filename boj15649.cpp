#include<iostream>

using namespace std;

int n, m;
const int MAX = 8;

int arr[MAX], check[MAX];

void dfs(int k) {//k �� ���� ����
	//m���� �����ϸ� arr ���
	//arr[0]�� 0���� �����̹Ƿ� + 1�� ���༭ ���
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] + 1 << ' ';
		}
		cout << '\n';
		return;
	}
	//���� �湮���� �ʾ����� arr ä���ְ�, �湮 ó�����ְ�
	//k�� 1 ���� ���Ѽ� dfs �����ְ� ������ �湮 ó�� ����
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