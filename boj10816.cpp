#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int arr[500001];

int upper_index(int target, int len) {
	int start = 0;
	int end = len;
	while (start < end) {
		int mid = (start + end) / 2;
		if (arr[mid] > target) end = mid;
		else start = mid + 1;
	}
	return start;
}

int lower_index(int target, int len) {
	int start = 0;
	int end = len;
	while (start < end) {
		int mid = (start + end) / 2;
		if (arr[mid] >= target) end = mid;
		else start = mid + 1;
	}
	return start;
}



int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr[i] = num;
	}
	sort(arr, arr + n);
	cin >> m;
	while (m--) {
		int targetNum;
		cin >> targetNum;
		int lower = lower_index(targetNum, n);
		int upper = upper_index(targetNum, n);
		cout << upper - lower << ' ';
	}
	return 0;
}