#include<iostream>
#include<algorithm>

using namespace std;

int n;
string input, temp;
int main() {
	cin >> n;
	cin >> input;
	string result = input;
	for (int i = 1; i < n; i++) {	//ù��° input���� �޾Ұ�, �� �����Ÿ� ������ 1���� n-1���� �ݺ�
		string temp;
		cin >> temp;
		for (int j = 0; j < input.length(); j++) {	//�� ���ھ� ���鼭 ��
			if (input[j] != temp[j]) result[j] = '?';	//ó�� �޾Ҵ� �ܾ�� �� ���� ���� �ܾ� ��
			//���� �Է¹��� �ܾ���� �ٸ��� ?�� �ٲ���
		}
	}
	cout << result;

	return 0;
}