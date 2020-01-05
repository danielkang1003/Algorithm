#include<iostream>

using namespace std;

int parent[11];

int Find(int x) {
	if (x == parent[x]) return x;
	else {
		int p = Find(parent[x]);
		parent[x] = p;
		return p;
	}
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	//if (x != y) parent[y] = x;
	if (x < y) parent[y] = x;
	else parent[x] = y;
}

int findParent(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x == y) return 1;
	else return 0;
}

int main() {
	for (int i = 1; i <= 10; i++) parent[i] = i;
	Union(1, 2);
	Union(2, 3);
	Union(3, 4);
	Union(5, 6);
	Union(6, 7);
	Union(7, 8);
	for (int i = 1; i <= 10; i++) {
		cout << "노드는 " << i << "이고 부모는 : " << parent[i] << '\n';
	}

	cout << "1과 5의 연결 상태 : " << (findParent(1, 5) == 1 ? "Connected!" : "Disconnect!") << '\n';
	Union(1, 5);
	cout << "1과 5의 연결 상태 : " << (findParent(1, 5) == 1 ? "Connected!" : "Disconnect!");
	return 0;
}