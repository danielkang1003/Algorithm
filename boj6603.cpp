#include<iostream>
#include<vector>
using namespace std;
//���� ����, �ߺ� x, �������� ���� �Ǽ� �־���

int k;			//k�� 0�� ������ ����
int lotto[13];	//k���� ���� ���� �迭
vector<int> v;	//������ ����

void dfs(int idx, int cnt) {
	//�츮�� 6������ ���� ���� �ŹǷ� cnt == 6�� �Ǹ� ���
	if (cnt == 6) {
		for (int i = 0; i < 6; i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = idx; i < k; i++) {
		v.push_back(lotto[i]);	//���Ϳ� �ϳ��� ����ְ�
		dfs(i + 1, cnt + 1);	//dfs �����ֱ�
		v.pop_back();
	}
}

int main() {
	//k�� 0�� ���� ������ ���ѷ���
	while (1) {
		cin >> k;
		if (k == 0) break;	//Ż��
		for (int i = 0; i < k; i++) {
			cin >> lotto[i];
		}
		//Ž�� ����
		dfs(0, 0);
		cout << '\n';
	}

	return 0;
}