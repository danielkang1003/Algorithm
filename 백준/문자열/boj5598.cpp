#include<iostream>

using namespace std;

string encrypted, decrypted;

int main() {
	cin >> encrypted;
	int len = encrypted.length();
	for (int i = 0; i < len; i++) {
		if (encrypted[i] >= 'D' && encrypted[i] <= 'Z') decrypted += encrypted[i] - 3;
		else if (encrypted[i] < 'D')
			decrypted += encrypted[i] - 'A' + 'X';
	}
	cout << decrypted;
	return 0;
}