#include<iostream>
#include<cmath>
#include<time.h>

using namespace std;

int n, k;
bool isPrime[1001];

void init() {
	for (int i = 2; i <= n; i++) {
		isPrime[i] = 1;
	}
}

void getKthErasedNum() {
	int cnt = 0;
	for (int i = 2; i * i <= 1000 * 1000; i++) {
		if (isPrime[i] == 0) continue;
		for (int j = i; j <= n; j += i) {
			if (isPrime[j] == 1) {
				isPrime[j] = 0;
				cnt++;
				if (cnt == k) {
					cout << j << '\n';
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> k;
	time_t start, end;
	start = clock();
	init();
	getKthErasedNum();
	end = clock();
	double totalTime = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "수행 시간: " << totalTime;

	return 0;
}