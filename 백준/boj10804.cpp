#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int a, b;
int arr[21];

int main() {
	for (int i = 1; i <= 20; i++) {
		arr[i] = i;
	}

	//10���� ������ �۾�
	for (int tc = 1; tc <= 10; tc++) {
		cin >> a >> b;

		//�˰��򿡼� reverse() ��� ����ص� ��
		//reverse(arr + a, arr + b + 1);
		while (a < b) {
			int temp = arr[a];
			arr[a] = arr[b];
			arr[b] = temp;
			a++, b--;
		}

	}
	for (int i = 1; i <= 20; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';
	return 0;
}