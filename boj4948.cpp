#include<iostream>
#include<time.h>
using namespace std;

bool isPrime[123456 * 2 + 1];

void solution() {
	while (true) {
		int num, cnt = 0;
		cin >> num;
		if (num == 0) break;
		for (int i = 2; i <= 2 * num; i++) isPrime[i] = 1;
		for (int i = 2; i <= sqrt(2 * num); i++) {
			if (isPrime[i] == 1) {
				for (int j = i + i; j <= 2 * num; j += i) {
					if (isPrime[j] == 1) isPrime[j] = 0;
				}
			}
		}
		for (int i = num + 1; i <= 2 * num; i++) {
			if (isPrime[i] == 1) cnt++;
		}
		cout << cnt << '\n';
	}
}

int main() {
	//clock_t start, end;
	//double result;
	//start = clock();
	solution();
	//end = clock();
	//result = (double)(end - start)/ CLOCKS_PER_SEC;
	//cout << "수행시간: " <<result;

	return 0;
}