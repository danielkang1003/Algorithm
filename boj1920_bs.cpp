#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int arr[100000];
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		if (binary_search(arr, arr + n, num)) {
			cout << "1\n";
		}
		else {
			cout << "0\n";
		}
	}

	return 0;
}