#include<iostream>
#include<algorithm>
#include<vector>
//k��° �� ���� 11004
using namespace std;

int n, k;
vector<int> v;
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	cout << v[k - 1];
	return 0;
}

/*
int main() {
	//�޸𸮶� �ð��� ��û ��ƸԴ´�.
	//�����Ҵ��� ���ְ� �޸� �����ְ� �ϴ� ������� ��.
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k, num;
	cin >> n >> k;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr[i] = num;
	}
	sort(arr, arr + n);
	cout << arr[k - 1];
	delete[] arr;
	return 0;
}
*/