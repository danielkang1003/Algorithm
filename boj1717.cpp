#include<iostream>

using namespace std;

int n, m;	//n�� ���� ����, m�� �Է����� �־����� ���� ����
int parent[1000001];

int Find(int x) {
	if (x == parent[x]) return x;
	else {
		return parent[x] = Find(parent[x]);
	}
}


void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x < y) parent[y] = x;
	else parent[x] = y;
}

int FindParent(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x == y) return 1;
	else return 0;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	//�ʱ�ȭ
	for (int i = 1; i <= n; i++) parent[i] = i;

	//���� ǥ�� ���α׷� ����
	for (int i = 0; i < m; i++) {
		int num, a, b;
		cin >> num >> a >> b;	//�������̸� 0, ���� ���տ� ���Ե��ִ��� Ȯ���Ϸ��� 1
		if (num == 0) {
			Union(a, b);
		}
		if (num == 1) {
			cout << (FindParent(a, b) == 1 ? "YES" : "NO") << '\n';
		}
	}
	return 0;
}