#include<iostream>
#include<string>

using namespace std;
typedef long long ll;

int n, len;
ll sum;


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	ll left = 1, right = 10;
	len = 1;

	while (true) {
		bool flag = false;
		for (int i = left; i < right; i++) {
			if (i > n) {
				flag = true;
				break;
			}
			sum += len;
		}
		if (flag == 1) {
			break;
		}
		left *= 10, right *= 10;
		len++;
	}
	cout << sum << '\n';

	return 0;
}