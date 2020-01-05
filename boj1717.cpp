#include<iostream>

using namespace std;

int n, m;	//n은 집합 개수, m은 입력으로 주어지는 연산 개수
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
	//초기화
	for (int i = 1; i <= n; i++) parent[i] = i;

	//집합 표현 프로그램 수행
	for (int i = 0; i < m; i++) {
		int num, a, b;
		cin >> num >> a >> b;	//합집합이면 0, 같은 집합에 포함되있는지 확인하려면 1
		if (num == 0) {
			Union(a, b);
		}
		if (num == 1) {
			cout << (FindParent(a, b) == 1 ? "YES" : "NO") << '\n';
		}
	}
	return 0;
}