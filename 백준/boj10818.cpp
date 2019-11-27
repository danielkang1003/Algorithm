#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> arr;

int main() {
	int N, num;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());
	
	cout << arr[0] << ' ' << arr[N - 1];

	return 0;
}
