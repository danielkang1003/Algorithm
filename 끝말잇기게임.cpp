#include<iostream>

using namespace std;

int main() {
	string word;
	cout << "끝말잇기를 시작합니다.\n";
	cin >> word;
	bool flag = true;
	while (flag) {
		flag = false;
		cout << word << "를 치셨습니다.\n";
		string newWord;
		cin >> newWord;
		int size = word.size();
		if (word[size - 1] == newWord[0]) {
			word = newWord;
			flag = true;
		}
		else {
			cout << "끝말잇기란 말이에요!!";
			flag = false;
		}
	}

	return 0;
}