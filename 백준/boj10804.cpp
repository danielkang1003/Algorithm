#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int a, b;
int arr[21];

int main() {
	for (int i = 1; i <= 20; i++) {
		arr[i] = i;
	}

	//10번의 뒤집는 작업
	for (int tc = 1; tc <= 10; tc++) {
		cin >> a >> b;

		//알고리즘에서 reverse() 기능 사용해도 됨
		//reverse(arr + a, arr + b + 1);
		while (a < b) {
			int temp = arr[a];
			arr[a] = arr[b];
			arr[b] = temp;
			a++, b--;
		}

	}
	for (int i = 1; i <= 20; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';
	return 0;
}