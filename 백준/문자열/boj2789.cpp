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
	//cout << "�˿� ��: ";
	//for (int i = 0; i < len; i++) cout << input[i];
	//�� ���ڿ��� �����ϰ�� ���
	for (int i = 0; i < len; i++) if (input[i] != ' ') cout << input[i];
	return 0;
}