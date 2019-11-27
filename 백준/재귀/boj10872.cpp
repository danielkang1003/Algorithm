#include<iostream>

using namespace std;

int factorial(int n) {
	int ans = 1;
	if (n == 1) ans *= 1;
	if (n >= 2) {
		ans *= n * factorial(n - 1);
	}

	return ans;
}

int main() {
	int N;
	cin >> N;
	cout << factorial(N) << '\n';

	return 0;
}
