#include<iostream>
#include<string>

using namespace std;

char words[5][16];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	for (int i = 0; i < 5; i++) {
		string input;
		getline(cin, input);
		int size = input.size();
		for (int j = 0; j < size; j++) {
			words[i][j] = input[j];
		}
	}
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 5; j++) {
			if (words[j][i] == NULL) continue;	//���̰� ���� �ʰ� ���ͼ� �� ���ڿ� ����� ��� �ϱ� ����
			cout << words[j][i];
		}
	}
	return 0;
}