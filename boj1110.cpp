#include<iostream>

using namespace std;

int main() {
	// 수 받기
	int N;
	cin >> N;
	
	// 초기 값을 저장하기 위한 init
	int init = 0, result = 0;
	init = N;

	//N 이 일의 자리와 십의 자리로 더해져서 새로운 수가 되기에 연산해주기
	do{
		int before = N / 10;
		int after = N % 10;
		int sum = before + after;

		N = after * 10 + sum % 10;
		result++;
	} while (N != init);

	cout << result <<'\n';

	return 0;
}