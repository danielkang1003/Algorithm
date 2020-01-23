#include<iostream>
#include<algorithm>
using namespace std;

int n;
int arrA[50], arrB[50];
bool check[50];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arrA[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> arrB[i];
	}

	sort(arrA, arrA + n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int temp = 0;
		int idx = 0;
		for (int j = 0; j < n; j++) {
			if (temp < arrB[j] && check[j] == 0) {
				temp = arrB[j];
				idx = j;
			}
		}
		check[idx] = 1;
		sum += arrA[i] * temp;
	}
	cout << sum;
	return 0;
}