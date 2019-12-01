#include<iostream>

using namespace std;

int a[1000000];

void quick_sort(int* arr, int start, int end) {
	//���̰� 1 ���ϸ� �Լ� ��������
	if (end - start <= 1) return;
	int pivot = arr[start];	//���� ���� �ǹ����� ����
	int left = start + 1;	//left�� �ǹ� ������ ����
	int right = end - 1;	//right�� ���������� ����
	while (true) {
		//left�� right���� ���� �۾ƾ��Ѵ�.
		//idx�� left�� �迭�� ���� �ǹ����� ���������� left�� �����ϰ�,
		//idx�� right�� �迭�� ���ڰ� �ǹ����� Ŭ������ right�� �����Ѵ�.
		while (left <= right && arr[left] <= pivot) left++;
		while (left <= right && arr[right] >= pivot) right--;
		if (left > right) break; //left�� right�� �ڸ��� �ٲ�ٸ� Ż��
		
		//�������ֱ�
		//swap(arr[left], arr[right]);
		int temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
	}
	//swap(arr[start], arr[right]);
	int swapp = arr[start];
	arr[start] = arr[right];
	arr[right] = swapp;
	quick_sort(arr, start, right);
	quick_sort(arr, right + 1, end);
}
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	quick_sort(a, 0, n);
	for (int i = 0; i < n; i++) 
		cout << a[i] << '\n';
	return 0;
}