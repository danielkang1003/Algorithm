#include<iostream>

using namespace std;

int fibo(int n) {
	int answer = 0;
	if (n < 2) {
		answer += n;
	}
	else if (n >= 2) {
		answer += fibo(n - 1) + fibo(n - 2);
	}
	return answer;
}

int main() {
	int n;
	cin >> n;
	int result = fibo(n);
	cout << result << '\n';

	return 0;
}
