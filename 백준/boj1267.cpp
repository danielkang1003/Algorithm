#include<iostream>
#include<algorithm>
using namespace std;

int n, num;

int main() {
	cin >> n;
	//영수 요금제, 민수 요금제
	int ys_total = 0, ms_total = 0;
	for (int i = 0; i < n; i++) {
		cin >> num;
		//영수 요금제는 30초마다 10원씩
		ys_total += 10 * (num / 30 + 1);
		//민수 요금제는 60초마다 15원씩
		ms_total += 15 * (num / 60 + 1);
	}
	if (ys_total < ms_total) cout << "Y ";
	else if (ys_total == ms_total) cout << "Y M ";
	else cout << "M ";
	int res = min(ys_total, ms_total);
	cout << res;
	return 0;
}