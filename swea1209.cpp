#include<iostream>
#include<cstring>

using namespace std;

int tnum, answer;
int map[100][100];

void init() {
	memset(map, 0, sizeof(map));
	answer = 0;
}

void input() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			cin >> map[i][j];
		}
	}
}

void findMax() {
	int sum;
	//가로 합 구하기
	for (int i = 0; i < 100; i++) {
		sum = 0;
		for (int j = 0; j < 100; j++) {
			sum += map[i][j];
		}
		if (sum > answer) answer = sum;
	}
	//세로 합 구하기
	for (int j = 0; j < 100; j++) {
		sum = 0;
		for (int i = 0; i < 100; i++) {
			sum += map[i][j];
		}
		if (sum > answer) answer = sum;
	}
	//대각선 합 구하기
	sum = 0;
	for (int i = 0; i < 100; i++) {
		sum += map[i][i];
	}
	if (sum > answer) answer = sum;
	sum = 0;
	for (int j = 99; j >= 0; j--) {
		sum += map[99 - j][j];
	}
	if (sum > answer) answer = sum;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	for (int tc = 1; tc <= 10; tc++) {
		cin >> tnum;
		init();
		input();
		findMax();
		cout << "#" << tc << " " << answer;
	}

	return 0;
}