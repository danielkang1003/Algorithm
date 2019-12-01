#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<pair<int, int>> v;

void hanoi(int num, int start, int empty, int end) {
	if (num == 1) v.push_back({ start, end });
	else {
		hanoi(num - 1, start, end, empty);
		v.push_back({ start, end });
		hanoi(num - 1, empty, start, end);
	}
}

int main() {
	int n;
	cin >> n;

	hanoi(n, 1, 2, 3);
	cout << v.size() << '\n';
	int size = v.size();
	for (int i = 0; i < size; i++) {
		cout << v[i].first << ' ' << v[i].second << '\n';
	}

	return 0;
}

//void hanoi(int num, int start, int empty, int end) {
//	if (num == 1) {
//		cout << start << ' ' << end << '\n';
//		return;
//	}
//
//	hanoi(num - 1, start, end, empty);
//	hanoi(1, start, empty, end);
//	hanoi(num - 1, empty, start, end);
//	return;
//}
//
//int main() {
//	int n;
//	cin >> n;
//	cout << (int)pow(2, n) - 1 << '\n';
//	hanoi(n, 1, 2, 3);
//	return 0;
//}