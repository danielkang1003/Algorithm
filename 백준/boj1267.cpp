#include<iostream>
#include<algorithm>
using namespace std;

int n, num;

int main() {
	cin >> n;
	//���� �����, �μ� �����
	int ys_total = 0, ms_total = 0;
	for (int i = 0; i < n; i++) {
		cin >> num;
		//���� ������� 30�ʸ��� 10����
		ys_total += 10 * (num / 30 + 1);
		//�μ� ������� 60�ʸ��� 15����
		ms_total += 15 * (num / 60 + 1);
	}
	if (ys_total < ms_total) cout << "Y ";
	else if (ys_total == ms_total) cout << "Y M ";
	else cout << "M ";
	int res = min(ys_total, ms_total);
	cout << res;
	return 0;
}