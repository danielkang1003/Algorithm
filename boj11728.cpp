#include<iostream>

using namespace std;

int n, m; //배열 a,b의 크기

void merge(int* a, int n, int* b, int m) {
	//merge할 새 배열 할당
	int* arr = new int[n + m];
	int idx = 0;
	int idx1 = 0;
	int idx2 = 0;

	//a 배열과 b 배열에서 작은수를 비교한다
	//실행은 idx1(a 배열)과 idx2(b배열에 사용) 이 각 배열의 길이를
	//넘지 않을떄 동안만 실행
	while (idx1 < n && idx2 < m) {
		if (a[idx1] < b[idx2]) {
			arr[idx++] = a[idx1++];
		}
		else arr[idx++] = b[idx2++];
	}
	//위의 수를 비교해서 넣고 남은 값을 arr 배열에 넣어준다
	while (idx1 < n) {
		//a 배열에서 남았을 떄
		arr[idx++] = a[idx1++];
	}
	while (idx2 < m) {
		//b 배열에서 남았을 떄
		arr[idx++] = b[idx2++];
	}
	for (int i = 0; i < n + m; i++)
		cout << arr[i]<< ' ';
	delete[] arr;
}
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	int* a = new int[n];
	int* b = new int[m];
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
	merge(a, n, b, m);
	delete[] a, b;
	return 0;
}