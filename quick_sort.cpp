#include<iostream>

using namespace std;

int a[1000000];

void quick_sort(int* arr, int start, int end) {
	//길이가 1 이하면 함수 빠져나옴
	if (end - start <= 1) return;
	int pivot = arr[start];	//가장 앞은 피벗으로 고정
	int left = start + 1;	//left는 피벗 옆에서 시작
	int right = end - 1;	//right는 마지막에서 시작
	while (true) {
		//left는 right보다 수가 작아야한다.
		//idx가 left인 배열의 수가 피벗보다 작을떄까지 left는 증가하고,
		//idx가 right인 배열의 숫자가 피벗보다 클때까지 right는 감소한다.
		while (left <= right && arr[left] <= pivot) left++;
		while (left <= right && arr[right] >= pivot) right--;
		if (left > right) break; //left가 right랑 자리가 바뀐다면 탈출
		
		//스왑해주기
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