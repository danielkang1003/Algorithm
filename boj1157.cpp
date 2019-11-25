#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int check[26];
string input;
int maxCnt, idx, cnt;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> input;

	//�ܾ� ���� ���� check�� ���� �ֱ�
	for (int i = 0; i < input.length(); i++) {
		if (input[i] >= 'A' && input[i] <= 'Z') {
			//�빮�ڶ��
			check[input[i] - 'A']++;
		}
		else {
			//�ҹ��ڶ��
			check[input[i] - 'a']++;
		}
	}

	//���� ���� ���� ã�Ƽ� maxCnt �� idx�� ����
	for (int i = 0; i < 26; i++) {
		if (check[i] >= maxCnt) {
			maxCnt = check[i];
			idx = i;
		}
	}

	//check�迭�� ���Ƽ� ������ maxCnt�� ������ cnt ����
	//�ٵ� cnt �� �ΰ� �̻��̸� ���� ���� ���ĺ��� 2��
	//�̻��̶�� ���̹Ƿ� ���� ���ǰ� ���� ? ���
	for (int i = 0; i < 26; i++) {
		if (check[i] == maxCnt) {
			cnt++;
			if (cnt >= 2) {
				cout << "?\n";
				return 0;
			}
		}
	}

	cout << (char)(idx + 65);

	return 0;
}