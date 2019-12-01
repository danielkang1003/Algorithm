#include<iostream>

using namespace std;

void merge(int* arr1, int len1, int* arr2, int len2) {
	int* arr_sort = new int[len1 + len2];
	int idx = 0;
	int idx1 = 0;
	int idx2 = 0;
	while (idx1 < len1 && idx2 < len2) {
		if (arr1[idx1] < arr2[idx2]) {
			cout << arr1[idx1] << " 이 " << arr2[idx2] << "보다 작습니다.\n";
			arr_sort[idx++] = arr1[idx1++];
		}
		else {
			cout << arr2[idx2] << " 이 " << arr1[idx1] << "보다 작습니다.\n";
			arr_sort[idx++] = arr2[idx2++];
		}
		for (int i = 0; i < arr_sort[len1 + len2]; i++) {
			cout << arr_sort[i] << ' ';
		}
		cout << '\n';
	}

	while (idx1 < len1) {
		arr_sort[idx++] = arr1[idx1++];
	}
	while (idx2 < len2) {
		arr_sort[idx++] = arr2[idx2++];
	}
	for (int i = 0; i < len1 + len2; i++)
		cout << arr_sort[i] << ' ';
	delete[] arr_sort;
}

int main() {
	int a[5] = { -9,1,6,8,12 };
	int b[4] = { -7,7,13,15 };
	merge(a, 5, b, 4);

	delete[] a, b;
	return 0;
}