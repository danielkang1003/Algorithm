#include<iostream>
#include<algorithm>
using namespace std;
int n, m;
int arr[100000];

int BinarySearch(int target, int len) {
	int start = 0;
	int end = len - 1;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (arr[mid] == target) return mid;
		else if (arr[mid] > target) {
			end = mid - 1;
		}
		else {
			//arr[mid] < target
			start = mid + 1;
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	cin >> m;
	while (m--) {
		int temp;
		cin >> temp;
		if (BinarySearch(temp, n) == -1) cout << "0\n";
		else cout << "1\n";
	}

	return 0;
}