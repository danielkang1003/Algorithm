#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m;
int arr[500000];

//vector�� arr �迭�� upper bound lower bound ���ϱ�
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	vector<int> v;
	vector<int>::iterator low, up;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
		//cin >> arr[i];
	}
	sort(v.begin(), v.end());
	//sort(arr, arr + n);

	cin >> m;
	while (m--) {
		int target;
		cin >> target;
		low = lower_bound(v.begin(), v.end(), target);
		up = upper_bound(v.begin(), v.end(), target);
		//cout << upper_bound(arr, arr + n, target) - lower_bound(arr, arr + n, target) << ' ';
		cout << up - low << ' ';
	}

	return 0;
}