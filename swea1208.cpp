#include<iostream>

using namespace std;

int map[100], dump, minN, maxN, minIdx, maxIdx, sum;

int main() {
	for (int t = 1; t <= 10; t++) {
		cin >> dump;
		for (int i = 0; i < 100; i++) {
			cin >> map[i];
		}

		while (dump--) {
			minN = 101, maxN = 0, sum = 0;
			for (int i = 0; i < 100; i++) {
				if (minN > map[i]) minN = map[i], minIdx = i;
				if (maxN < map[i]) maxN = map[i], maxIdx = i;
			}
			//cout << "�ƽ� ��: " << maxN << ", ��ġ: " << maxIdx << ", �ּҰ�: " << minN << ", ��ġ: " << minIdx << '\n';
			map[maxIdx]--;
			map[minIdx]++;
		}
		minN = 101, maxN = 0;
		for (int i = 0; i < 100; i++) {
			//cout << map[i] << ' ';
			if (minN > map[i]) minN = map[i];
			if (maxN < map[i]) maxN = map[i];
		}
		//cout << "\n���� �ƽ���: " << maxN << ", �ּҰ�: " << minN << "\n ����: " << maxN - minN << '\n';
		sum = maxN - minN;
		cout << "#" << t << " " << sum << '\n';
	}
	return 0;
}