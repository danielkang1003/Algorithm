#include<iostream>
#include<string>

using namespace std;

int main() {
	int tc;
	string input;
	cin >> tc;
	cin.ignore();
	for (int i = 0; i < tc; i++) {
		getline(cin, input);
		int len = input.length();
		//cout << input << "ÀÇ ±æÀÌ : " << len <<'\n';
		string output = "";
		output += (input[0] - 32);
		for (int i = 1; i < len; i++) {
			if (input[i] == ' ') output += (input[i + 1] - 32);
		}
		cout << "#" << i + 1 << " " << output << '\n';
	}
	return 0;
}