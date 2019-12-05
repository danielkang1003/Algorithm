#include<iostream>
#include<algorithm>
using namespace std;

int n, s, cnt;
const int MAX = 21;
int arr[MAX];
int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	//1 << n Àº 2ÀÇ n½Â
	for (int i = 1; i < (1 << n); i++) {
		int tmp = i;
		int tot = 0;
		for (int j = 0; j < n; j++) {
			if (tmp % 2 == 1) tot += arr[j];
			tmp /= 2;
		}
		if (tot == s) cnt++;
	}
	cout << cnt;

	return 0;
}