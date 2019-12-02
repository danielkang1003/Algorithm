#include<iostream>
#include<vector>
using namespace std;

int n, k, coin;
int arr[11];
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = n; i >= 1; i--) {
		if (k == 0) break;
		if (k >= arr[i]) {
			coin += (k / arr[i]);
			k %= arr[i];
		}
	}
	cout << coin;
	return 0;
}