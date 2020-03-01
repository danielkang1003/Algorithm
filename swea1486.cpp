#include<iostream>
#include<vector>
#include<climits>
#include<cstring>

using namespace std;

int tc, n, b;
int arr[20];
int answer;
void closestNum(int cnt, int total) {
	if (cnt >= n) {
		if (total < b) return;

		int temp = total - b;
		if (answer == -1 || answer > temp) {
			answer = temp;
		}
		return;
	}

	closestNum(cnt + 1, total + arr[cnt]);
	closestNum(cnt + 1, total);
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		answer = -1;
		cin >> n >> b;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		closestNum(0, 0);
		cout << "#" << t << " " << answer << '\n';
	}
}