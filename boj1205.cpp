#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, youjinScore, p;
vector<int> v;

int main() {
	cin >> n >> youjinScore >> p;
	int rank = 1;

	for (int i = 0; i < n; i++) {
		int scores;
		cin >> scores;
		v.push_back(scores);
	}
	if (n == p && v[n - 1] >= youjinScore) {
		//����Ʈ ������ ������ ������ ������
		rank = -1;
	}
	else {
		for (int i = 0; i < n; i++) {
			//���� �ý��ۿ� �ö� ��ȣ�� ���鼭 ������ �������� ������ ������
			//�����༭ ��� �����ֱ�
			if (v[i] > youjinScore) rank++;
		}
	}
	cout << rank;
	return 0;
}