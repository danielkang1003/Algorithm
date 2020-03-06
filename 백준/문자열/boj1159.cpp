#include<iostream>
#include<algorithm>

using namespace std;

int n;
char list[150];
int alphabet[26];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		list[i] = input.at(0);
	}
	for (int i = 0; i < n; i++) {
		alphabet[list[i] - 'a']++;
	}
	/*for (int i = 0; i < 26; i++) {
		cout << alphabet[i] <<' ';
	}*/
	string answer = "";
	bool flag = false;
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] >= 5) {
			flag = true;
			answer += i + 97;
		}
	}
	if (flag == false) {
		answer = "PREDAJA";
	}
	cout << answer;
	return 0;
}