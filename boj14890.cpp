#include<iostream>
#include<algorithm>

using namespace std;

int n, l;
int vmap[100][100], hmap[100][100];	//����, ���� ��

bool setStair(int map[][100], int x, int y) {
	for (int j = y + 1; j < y + 1 + l; j++) {
		if (map[x][y + 1] != map[x][j]) {
			//ù �õ��� ����. ���� �Ѱܿ� ��� �ִ� ���� ĭ����
			//���� ���̸�ŭ Ȯ���ϸ� ���̰� ������ Ȯ��
			return false;	//�ٸ��ٸ� 0 ��ȯ
		}
	}
	return true;	//���ٸ� 1 ��ȯ
}

int possiblePath(int map[][100]) {
	int possibleCnt = 0;
	for (int i = 0; i < n; i++) {
		bool flag = true;
		int prev = 1;	//����� �� ���̰� ������ ���� ����
		for (int j = 0; j < n - 1; j++) {
			if (map[i][j] == map[i][j + 1]) {	//���� ����̶� ���̰� ���ٸ�(����)
				prev++;	//��� ���ư��ɷ� ���� ǥ��
			}
			else if (map[i][j] == map[i][j + 1] + 1) {	//���� ��� �ִ� ��� ���̰� ����(������)
				if (setStair(map, i, j) == 1) {
					//���� ���̸�ŭ ���̰� ���ٸ�
					j = j + l - 1;
					prev = 0;
				}
				else {
					flag = false;
					break;
				}
			}
			else if (map[i][j] + 1 == map[i][j + 1]) {	//���� ��� �ִ� ��ܳ��̰� ����(������)
				if (prev >= l) {
					prev = 1;
				}
				else {
					flag = false;
					break;
				}
			}
			else if (abs(map[i][j] - map[i][j + 1]) >= 2) {//���� ���� 2 �̻��̸�
				flag = false;
				break;
			}
		}
		if (flag) {
			//�ٸ��� ���� �� ���� ����
			possibleCnt++;
		}
	}
	return possibleCnt;
}

int main() {
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> hmap[i][j];	//���θ� �ް�
			vmap[j][i] = hmap[i][j];	//���θʿ� ���θ� ������� ����
		}
	}
	int a = possiblePath(vmap);
	int b = possiblePath(hmap);
	int answer = a + b;
	cout << answer << '\n';
	return 0;
}