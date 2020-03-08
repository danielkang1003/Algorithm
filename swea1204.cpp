#include<iostream>
#include<cstring>
#include<time.h>

using namespace std;

int tc, tcNum, maxNum, maxIdx;
time_t start, endt;
int arr[1001], cnt[101];
void init() {
	memset(arr, 0, sizeof(arr));
	memset(cnt, 0, sizeof(cnt));
}

void findAnswer() {
	for (int i = 1; i <= 1000; i++) {
		cin >> arr[i];
		cnt[arr[i]]++;
	}
	maxNum = -1;
	maxIdx = 0;
	for (int i = 1; i <= 100; i++) {
		if (maxNum <= cnt[i]) {
			maxNum = cnt[i];
			maxIdx = i;
		}
	}
}

void input() {
	cin >> tc;
	while (tc--) {
		cin >> tcNum;
		init();
		findAnswer();
		cout << "#" << tcNum << " " << maxIdx << '\n';
		/*for (int i = 1; i <= 100; i++) {
			if (i % 10 == 0) cout << '\n';
			cout << cnt[i] << ' ';
		}*/
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	start = clock();
	input();
	endt = clock();
	double timeSpent = (double)(endt - start) / CLOCKS_PER_SEC;
	//cout << "수행 시간: " << timeSpent;
	return 0;
}