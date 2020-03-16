#include<iostream>
#include<stack>

using namespace std;

int n, num;
int map[80001];
stack<int> s;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> map[i];
	}
	long long cnt = 0;
	for (int i = 1; i <= n; i++) {
		while (!s.empty() && s.top() <= map[i]) {
			s.pop();
		}
		s.push(map[i]);
		cnt += s.size() - 1;
	}
	cout << cnt << '\n';
	return 0;
}