#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	string a, b;
	cin >> a >> b;

	int aLen = a.length(), bLen = b.length(), diff = bLen - aLen, answer = 50;
	for (int i = 0; i <= diff; i++) {
		int cnt = 0;
		for (int j = 0; j < aLen; j++) {
			if (a[j] != b[j + i]) cnt++;
		}
		answer = min(cnt, answer);
	}
	cout << answer;
	return 0;
}