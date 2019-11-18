#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> arr;

int main() {
	//1번 방법 ((arr_c배열 복사하여 arr 최대값이랑 같으면 반환하도록 설정: 비효율적임)
	int num;

	for (int i = 0; i < 9; i++) {
		cin >> num;
		arr.push_back(num);
		//cout << '#' << i <<' ' <<  arr[i] << ' ' << '\n';
	}

	vector<int> arr_c = arr;
	int count = 0;
	sort(arr.begin(), arr.end());
	for (int i = 0; i < 9; i++) {
		if (arr.at(8) == arr_c[i]) {
			count = i;
		}
	}
	cout << arr.at(8) << '\n' << count + 1;

	/*for (int i = 0; i < 9; i++) {
		cout << arr.at(i) << ' ';
	}*/



	//////////2번 방법 (간단하게 그냥 이렇게 했으면 됬음...)
	int max = 0, num, count = 0;
	for (int i = 0; i < 9; i++) {
		cin >> num;
		arr.push_back(num);
		if (max < arr.at(i)) {
			max = arr.at(i);
			count = i + 1;
		}
	}
	cout << max << '\n' << count;
	return 0;
}