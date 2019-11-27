#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> check(27, -1);

int main() {
	string S;
	cin >> S;

	for (int i = 0; i < S.size(); i++) {
		if (check[S[i] - 'a'] == -1) check[S[i] - 'a'] = i;
	}
	for (int i = 0; i < 26; i++) {
		cout << check[i] << ' ';
	}

	return 0;
}
