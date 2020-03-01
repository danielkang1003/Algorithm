#include<iostream>
#include<algorithm>
using namespace std;

int n, m, num;
int upper, lower;
int arr[500000];

//target보다 큰 첫번째 위치를 찾는 것이기에 arr[mid] <= target보다 클 때 start = mid + 1이 되고
//target을 찾아도 start 값을 증가시킨다는 이야기
int upperBound(int target, int len) {
	int start = 0;
	int end = len;
	while (start < end) {
		int mid = (start + end) / 2;
		//if (arr[mid] > target) end = mid;
		//else start = mid + 1;	//arr[mid] <= target일 때 key 보다 큰 첫 위치를 찾아야하므로 mid + 1임
		if (arr[mid] <= target) start = mid + 1;
		else end = mid;
	}
	return start;	//원하는 값을 초과하는 첫 인덱스 위치 반환
}

//target보다 크거나 같은 첫번째 위치를 찾는 것이기에 if(arr[mid] < key) 이면 start = mid + 1
//즉 target 값을 찾았을때도 포함해서 start를 변경하는게 아니라, target보다 작을때만 start를 변경한다.
int lowerBound(int target, int len) {
	int start = 0;
	int end = len;
	while (start < end) {
		int mid = (start + end) / 2;
		if (arr[mid] < target) start = mid + 1;
		else end = mid;
	}
	return start;	//원하는 값 이상의 첫번째 위치 반환
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	cin >> m;
	while (m--) {
		cin >> num;
		upper = upperBound(num, n);
		lower = lowerBound(num, n);
		cout << upper - lower << ' ';
	}

	return 0;
}