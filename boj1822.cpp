#include<iostream>
#include<algorithm>

using namespace std;
int a, b;
int arrA[500000], arrB[500000];
bool check[500000];

int binarySearch(int target, int len) {
	int start = 0;
	int end = len;
	while (start < end) {
		int mid = (start + end) / 2;
		if (arrA[mid] < target) start = mid + 1;
		else if (arrA[mid] > target) end = mid;
		else return mid;
	}
	return -1;
}
//이분탐색 사용
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> a >> b;
	for (int i = 0; i < a; i++) cin >> arrA[i];
	for (int i = 0; i < b; i++) cin >> arrB[i];

	sort(arrA, arrA + a);

	int n = a;
	for (int i = 0; i < b; i++) {
		int idx = binarySearch(arrB[i], a);
		if (idx != -1) {
			check[idx] = 1;
			n--;
		}
	}
	cout << n << '\n';
	for (int i = 0; i < a; i++) {
		if (check[i] == 0) cout << arrA[i] << ' ';
	}

	return 0;
}

/*
//set 사용법
#include<iostream>
#include<set>

using namespace std;

int n, m;
set<int> s;
set<int>::iterator it;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		s.insert(num);
	}
	for (int i = 0; i < m; i++) {
		int target;
		cin >> target;
		it = s.find(target);
		if (it == s.end()) continue;
		else s.erase(target);
	}
	cout << s.size() << '\n';
	for (it = s.begin(); it != s.end(); it++)
		cout << *it << ' ';
	return 0;
}
*/