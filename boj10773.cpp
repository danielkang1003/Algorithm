#include<iostream>
#include<stack>
using namespace std;
int k;
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> k;
	stack<int> s;
	for (int i = 0; i < k; i++) {
		int money;
		cin >> money;
		if (money != 0) {
			s.push(money);
		}
		else {
			s.pop();
		}
	}
	int sum = 0;
	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}
	cout << sum;

	return 0;
}