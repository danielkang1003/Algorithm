#include<iostream>
#include<string>

using namespace std;

int n;
int map[101][101];


void attach(int a, int b) {
	for (int i = b; i < b + 10; i++) {
		for (int j = a; j < a + 10; j++) {
			map[i][j] = 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		attach(x, y);
	}
	int cnt = 0;
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (map[i][j] == 1) cnt++;
		}
	}
	cout << cnt;
	return 0;
}