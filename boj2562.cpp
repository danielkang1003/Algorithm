#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> arr;

int main() {
	//1�� ��� ((arr_c�迭 �����Ͽ� arr �ִ밪�̶� ������ ��ȯ�ϵ��� ����: ��ȿ������)
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



	//////////2�� ��� (�����ϰ� �׳� �̷��� ������ ����...)
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