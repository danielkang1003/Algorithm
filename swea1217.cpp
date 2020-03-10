#include<iostream>


using namespace std;

int tNum, n, m, answer;

void input() {
	answer = 0;
	cin >> tNum;
	cin >> n >> m;
}

void function(int n, int m, int cnt, int total) {
	if (cnt == m - 1) {
		cout << "#" << tNum << " " << total << '\n';
		return;
	}
	function(n, m, cnt + 1, total * n);
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	for (int t = 1; t <= 10; t++) {
		input();
		function(n, m, 0, n);
	}
	return 0;
}