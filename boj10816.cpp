#include<iostream>
#include<algorithm>
using namespace std;

int n, m, num;
int upper, lower;
int arr[500000];

//target���� ū ù��° ��ġ�� ã�� ���̱⿡ arr[mid] <= target���� Ŭ �� start = mid + 1�� �ǰ�
//target�� ã�Ƶ� start ���� ������Ų�ٴ� �̾߱�
int upperBound(int target, int len) {
	int start = 0;
	int end = len;
	while (start < end) {
		int mid = (start + end) / 2;
		//if (arr[mid] > target) end = mid;
		//else start = mid + 1;	//arr[mid] <= target�� �� key ���� ū ù ��ġ�� ã�ƾ��ϹǷ� mid + 1��
		if (arr[mid] <= target) start = mid + 1;
		else end = mid;
	}
	return start;	//���ϴ� ���� �ʰ��ϴ� ù �ε��� ��ġ ��ȯ
}

//target���� ũ�ų� ���� ù��° ��ġ�� ã�� ���̱⿡ if(arr[mid] < key) �̸� start = mid + 1
//�� target ���� ã�������� �����ؼ� start�� �����ϴ°� �ƴ϶�, target���� �������� start�� �����Ѵ�.
int lowerBound(int target, int len) {
	int start = 0;
	int end = len;
	while (start < end) {
		int mid = (start + end) / 2;
		if (arr[mid] < target) start = mid + 1;
		else end = mid;
	}
	return start;	//���ϴ� �� �̻��� ù��° ��ġ ��ȯ
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