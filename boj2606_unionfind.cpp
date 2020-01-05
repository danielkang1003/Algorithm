#include<iostream>

using namespace std;

int n, e, a, b;
int computer[101];

int Find(int x) {
	if (x == computer[x]) return x;
	else {
		return computer[x] = Find(computer[x]);
	}
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x < y) computer[y] = x;
	else computer[x] = y;
}

int main() {
	cin >> n >> e;
	//초기화
	for (int i = 1; i <= n; i++) computer[i] = i;

	for (int i = 0; i < e; i++) {
		cin >> a >> b;
		Union(a, b);
	}

	//1이랑 이어져있으면 cnt 1씩 증가시켜주면 됨
	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (Find(1) == Find(i))cnt++;
	}
	cout << cnt;
	return 0;
}