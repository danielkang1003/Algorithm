#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

int n, num;
char answer[200050];
stack<int> s;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	cin >> n;
	int idx = 0, maxN = 0;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		if (num > maxN) {
			for (int j = maxN + 1; j <= num; j++) {
				s.push(j);
				answer[idx++] = '+';
			}
		}
		else if (s.top() != num) {
			cout << "NO\n";
			return 0;
		}
		s.pop();
		answer[idx++] = '-';
		if (maxN < num) maxN = num;
	}
	for (int i = 0; i < idx; i++) {
		cout << answer[i] << '\n';
	}
	return 0;
}