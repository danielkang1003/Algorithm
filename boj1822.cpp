#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

int a, b;
set<int> s;
set<int>::iterator it;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		int num;
		cin >> num;
		s.insert(num);
	}
	for (int i = 0; i < b; i++) {
		int num;
		cin >> num;
		it = s.find(num);
		if (it == s.end()) continue;
		else s.erase(num);
	}

	cout << s.size() << '\n';
	for (it = s.begin(); it != s.end(); it++) {
		cout << *it << ' ';
	}

	return 0;
}