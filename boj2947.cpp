#include<iostream>

using namespace std;

int arr[5];
int num;

int main() {
	for (int i = 0; i < 5; i++) {
		cin >> num;
		arr[i] = num;
	}

	//�迭 ũ�⸦ ���� �ʱ� ���� 4���� ������ i��ŭ ���ְ� ����
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4 - i; j++) {
			bool check = 1;	//üũ�� 0�̸� �����ٴ� �̾߱�. ����� ��
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				check = 0;
			}
			if (!check) {	//���
				for (int k = 0; k < 5; k++) {
					cout << arr[k] << ' ';
				}
				cout << '\n';
			}
		}
	}
	return 0;
}