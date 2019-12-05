#include<iostream>

using namespace std;

int arr[4], cnt[2];

void check(int* cnt) {
	if (cnt[0] == 1 && cnt[1] == 3) {
		cout << "A\n";
		return;
	}
	else if (cnt[0] == 2 && cnt[1] == 2) {
		cout << "B\n";
		return;
	}
	else if (cnt[0] == 3 && cnt[1] == 1) {
		cout << "C\n";
		return;
	}
	else if (cnt[0] == 4) {
		cout << "D\n";
		return;
	}
	else if (cnt[1] == 4) {
		cout << "E\n";
		return;
	}
}

int main() {
	for (int t = 0; t < 3; t++) {
		for (int i = 0; i < 4; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < 4; i++) {
			cnt[arr[i]]++;
		}
		check(cnt);
		cnt[0] = 0, cnt[1] = 0;
	}

	return 0;
}