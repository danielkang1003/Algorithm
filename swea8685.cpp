#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int tc;
int arr[10];

int maxN, minN;

int main() {
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		//�Է¹ޱ�
		for (int i = 0; i < 10; i++) {
			cin >> arr[i];
		}
		maxN = 0, minN = 1000001;
		//�迭�� ���ڵ��� ���Ѵ�
		for (int i = 0; i < 10; i++) {
			int temp = 0;
			while (arr[i] > 0) {
				temp += arr[i] % 10;
				arr[i] /= 10;
			}
			maxN = max(temp, maxN);
			minN = min(temp, minN);
		}
		cout << "#" << t << ' ' << maxN << " " << minN << '\n';
		memset(arr, 0, sizeof(arr));
	}

	return 0;
}