#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
const int MAX = 7;
int arr[MAX];

//����. check �迭 �ʿ����
void dfs(int* asc, int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		arr[k] = asc[i];
		dfs(asc, k + 1);
	}
}

int main() {
	//asc�� maxũ��� ���ϰ� nũ�� ��ŭ �����Ҵ����ְ� �����Ͽ���
	cin >> n >> m;
	int* asc = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> asc[i];
	}
	sort(asc, asc + n);
	dfs(asc, 0);
	delete[] asc;
	return 0;
}