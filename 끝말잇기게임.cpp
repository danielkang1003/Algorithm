#include<iostream>

using namespace std;

int main() {
	string word;
	cout << "�����ձ⸦ �����մϴ�.\n";
	cin >> word;
	bool flag = true;
	while (flag) {
		flag = false;
		cout << word << "�� ġ�̽��ϴ�.\n";
		string newWord;
		cin >> newWord;
		int size = word.size();
		if (word[size - 1] == newWord[0]) {
			word = newWord;
			flag = true;
		}
		else {
			cout << "�����ձ�� ���̿���!!";
			flag = false;
		}
	}

	return 0;
}