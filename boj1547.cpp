#include<iostream>

using namespace std;

int ball[4] = { 0, 1,0, 0 };

void swap(int x, int y) {
	int temp = ball[x];
	ball[x] = ball[y];
	ball[y] = temp;
	return;
}

int main() {
	int m;
	cin >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		swap(x, y);
	}
	for (int i = 1; i <= 3; i++) {
		if (ball[i] == 1) {
			cout << i;
			return 0;
		}
	}
	cout << "-1";
	return 0;
}