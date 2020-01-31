#include<iostream>

using namespace std;

int tc;
string input;
int main() {
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> input;
		int len = input.length();
		bool flag = true;
		for (int i = 0; i < len; i++) {
			for (int j = len - 1 - i; j >= 0; j--) {
				cout << "i: " << input[i] << "ÀÌ°ם, j: " << input[j] << '\n';
				if (input[i] != input[j]) {
					flag = false;
					break;
				}
				else if (input[i] == input[j]) {
					break;
				}
			}
		}
		cout << "#" << t << ' ';
		if (flag == true) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
	return 0;
}