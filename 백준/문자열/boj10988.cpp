#include<iostream>

using namespace std;

int main() {
	string word;
	cin >> word;
	bool check = true;
	int len = word.length();
	for (int i = 0; i < len; i++) {
		if (word[i] != word[len - 1 - i]) check = false;
	}
	if (check) cout << "1\n";
	else cout << "0\n";


	return 0;
}