#include<iostream>

using namespace std;

bool check[10001];

int selfNumber(int n) {
	int sum = n;
	while (true) {
		if (n == 0) break;
		sum += n % 10;
		n = n / 10;
	}
	return sum;
}

int main() {
	for (int i = 1; i < 10001; i++) {
		int idx = selfNumber(i);
		if (idx <= 10001) check[idx] = 1;	//생성자가 있음
	}
	for (int i = 1; i < 10001; i++)
		if (check[i] == 0) cout << i << '\n';
	return 0;
}