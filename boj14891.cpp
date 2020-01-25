#include<iostream>

using namespace std;

int main() {
	char gear[4][9];	//string���� �Է��� ������ �������� �ι��� �־��־����
	for (int i = 0; i < 4; i++) {
		cin >> gear[i];
	}

	int k;
	cin >> k;
	while (k--) {
		int target, dir;	//target�� ���� ���, dir�� ����
		cin >> target >> dir;
		target--;			//-1�ϴ� ������ �迭�� �ִ� ��ϴ� 0���� �־����Ƿ�
		int move_dir[4] = { 0, };	//�� ��ϸ� ��� �������� �Է¹��� �迭
		move_dir[target] = dir;	//�Է¹��� ����� ������ ������ dir�� ������

		for (int left = target - 1; left >= 0; left--) {
			int right = left + 1;
			if (gear[left][2] == gear[right][6]) {
				//���� ���� ��
				break;
			}
			else {
				//���� �ٸ��� ������
				move_dir[left] = move_dir[right] * -1;	//-1�� ���ϸ� ���� dir �� ���� ��Ͽ� ���⿡ �ݴ�� ��
			}
		}

		for (int right = target + 1; right < 4; right++) {
			int left = right - 1;
			if (gear[left][2] == gear[right][6]) {
				//���� ���� ��
				break;
			}
			else {
				//���� �ٸ��� ������
				move_dir[right] = move_dir[left] * -1;	//-1�� ���ϸ� ���� dir �� ���� ��Ͽ� ���⿡ �ݴ�� ��
			}
		}

		for (int i = 0; i < 4; i++) {
			if (move_dir[i] == 1) {
				//�ð�������� ȸ��
				char temp = gear[i][7];
				for (int j = 7; j >= 1; j--) {
					gear[i][j] = gear[i][j - 1];
				}
				gear[i][0] = temp;
			}
			else if (move_dir[i] == -1) {
				//�ݽð�������� ȸ��
				char temp = gear[i][0];
				for (int j = 0; j < 7; j++) {
					gear[i][j] = gear[i][j + 1];
				}
				gear[i][7] = temp;
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < 4; i++) {
		if (gear[i][0] == '1') {
			answer += (1 << i);	//12�� ����(gear[i][����]�� S��(1)�̶�� 1��, 2,4,8�� ����)
		}
	}
	cout << answer;
	return 0;
}