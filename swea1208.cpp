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
			//cout << "맥스 값: " << maxN << ", 위치: " << maxIdx << ", 최소값: " << minN << ", 위치: " << minIdx << '\n';
			map[maxIdx]--;
			map[minIdx]++;
		}
		minN = 101, maxN = 0;
		for (int i = 0; i < 100; i++) {
			//cout << map[i] << ' ';
			if (minN > map[i]) minN = map[i];
			if (maxN < map[i]) maxN = map[i];
		}
		//cout << "\n최종 맥스값: " << maxN << ", 최소값: " << minN << "\n 차이: " << maxN - minN << '\n';
		sum = maxN - minN;
		cout << "#" << t << " " << sum << '\n';
	}
	return 0;
}