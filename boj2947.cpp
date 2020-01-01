#include<iostream>

using namespace std;

int arr[5];
int num;

int main() {
	for (int i = 0; i < 5; i++) {
		cin >> num;
		arr[i] = num;
	}

	//배열 크기를 넘지 않기 위해 4까지 돌리고 i만큼 빼주고 스왑
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4 - i; j++) {
			bool check = 1;	//체크가 0이면 변경됬다는 이야기. 출력할 것
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				check = 0;
			}
			if (!check) {	//출력
				for (int k = 0; k < 5; k++) {
					cout << arr[k] << ' ';
				}
				cout << '\n';
			}
		}
	}
	return 0;
}