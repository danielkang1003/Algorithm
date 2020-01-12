#include<iostream>

using namespace std;

int tc, n;
int arr[46];
bool answer;

void dfs(int n) {
	for (int i = 1; i < 46; i++) {
		for (int j = 1; j < 46; j++) {
			for (int k = 1; k < 46; k++) {
				if (arr[i] + arr[j] + arr[k] == n) {
					//cout << "»ï°¢¼ö´Â " << arr[i] << " " << arr[j] << ' ' << arr[k] << '\n';
					answer = 1;
					return;
				}
			}
		}
	}
	answer = 0;
}

int main() {
	cin >> tc;

	//»ï°¢¼ö ¹è¿­
	for (int i = 1; i < 46; i++) {
		arr[i] = (i * (i + 1)) / 2;
	}

	while (tc--) {
		cin >> n;
		dfs(n);
		if (answer == 1) cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}