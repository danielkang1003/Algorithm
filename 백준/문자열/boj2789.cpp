#include<iostream>

using namespace std;

int main() {
	string input, censored = "CAMBRIDGE";
	cin >> input;
	int len = input.length(), cLen = censored.length();
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < cLen; j++) {
			if (input[i] == censored[j]) input[i] = ' ';
		}
	}
	//cout << "검열 후: ";
	//for (int i = 0; i < len; i++) cout << input[i];
	//빈 문자열을 제외하고는 출력
	for (int i = 0; i < len; i++) if (input[i] != ' ') cout << input[i];
	return 0;
}