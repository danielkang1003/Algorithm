#include<iostream>

using namespace std;

int arr[10];

int main() {
	int num, total = 1;
	for (int i = 0; i < 3; i++) {
		cin >> num;
		total *= num;
	}
	
	//cout << total << '\n';

	while (1) {
		arr[total % 10]++;
		if (total / 10 == 0) break;
		total /= 10;
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << '\n';
	}

	return 0;
}
