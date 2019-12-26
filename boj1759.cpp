#include<iostream>
#include<algorithm>

using namespace std;

int l, c;
char alphabet[15];

//1. ��ȣ�� ������������ ������ ��
//2. ��ȣ���� �ּ� �Ѱ��� ������ �ּ� �ΰ��� �������� ����

//���ڰ����� �ε���, ����, ����, ����, �׸��� ��ȣ(����) �Ѱ��ش�.
void dfs(int idx, int k, int aeiou, int others, string password) {
	//����1���� ���� 2�� �̻��̰� ���̰� l�̶�� �����
	if (k == l) {
		if (aeiou >= 1 && others >= 2) {
			cout << password << '\n';
		}
		return;
	}
	//��ȣ�� ���������̹Ƿ� ������ ���ĺ��� ���� �ʴ´�.
	for (int i = idx; i < c; i++) {
		//�����ϋ� dfs
		if (alphabet[i] == 'a' || alphabet[i] == 'e' || alphabet[i] == 'i' ||
			alphabet[i] == 'o' || alphabet[i] == 'u') {
			dfs(i + 1, k + 1, aeiou + 1, others, password + alphabet[i]);
		}
		//�����϶� dfs
		else {
			dfs(i + 1, k + 1, aeiou, others + 1, password + alphabet[i]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		cin >> alphabet[i];
	}
	//��ȣ�� ������������ �ؼ� ����ϱ� ����
	sort(alphabet, alphabet + c);
	dfs(0, 0, 0, 0, "");	//ù ������ ��� 0 �̰� ��ȣ�� �������.
	return 0;
}