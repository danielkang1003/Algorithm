#include<iostream>
#include<algorithm>
using namespace std;

int n, m, result;
long long trees[1000000];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> m;
	long long maxHeight = 0, start = 0, end = 0, answer = 0;
	for (int i = 0; i < n; i++) {
		cin >> trees[i];
		if (maxHeight < trees[i]) maxHeight = trees[i];
	}
	end = maxHeight;

	while (start <= end) {
		long long mid = (start + end) / 2;
		long long sum = 0;
		//cout << "start: " << start << " end: " << end << " mid: " << mid << '\n';
		for (int i = 0; i < n; i++) {
			if (mid < trees[i]) {
				//cout << "mid: " << mid << "�� tree[" << i << "] �� " << trees[i] << "��\n";
				sum += trees[i] - mid;
				//cout << "�ڸ��� ���� ���� ���� :" << trees[i] - mid <<'\n';
			}
		}
		//cout << "�ڸ� ��: " << sum << '\n';
		if (sum > m) {
			if (answer < mid) answer = mid;
			start = mid + 1;
		}
		else if (sum == m) {
			answer = mid;
			break;
		}
		else end = mid - 1;
	}
	cout << answer << '\n';
	return 0;
}