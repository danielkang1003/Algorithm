#include<iostream>

using namespace std;

int len, answer, answer1, answer2;
char map[9][9], c_map[9][9];


void input() {
	cin >> len;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> map[i][j];
		}
	}
}

int palindrome(char map[9][9]) {
	int cnt = 0;
	//가로,세로 탐색
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j <= 8 - len; j++) {
			//cout << "y = " << j << "에대해 탐색 시작\n";
			bool flag = true;
			int idx = 0;
			for (int k = len - 1 + j; k >= len / 2 + j; k--) {
				if (k >= 8) break;
				if (map[i][j + idx] == map[i][k]) {
					//cout << "(" << i << "," << j + idx << ")의 " << map[i][j + idx] << "와 (" << i << "," << k << ")의 " << map[i][k] << "와 같습니다\n";
					idx++;
				}
				else {
					//cout << "(" << i << "," << j + idx << ")의 " << map[i][j + idx] << "와 (" << i << "," << k << ")의 " << map[i][k] << "가 다릅니다\n";
					flag = false;
					break;
				}
			}
			if (flag == true) cnt++;
			//cout << cnt << '\n';
		}
	}
	return cnt;
}

void copyMap() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			c_map[i][j] = map[j][i];
		}
	}
}

void print() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << c_map[i][j] << ' ';
		}
		cout << '\n';
	}
}

void getSum() {
	answer1 = palindrome(map);
	//print();
	answer2 = palindrome(c_map);
	answer = answer1 + answer2;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	for (int t = 1; t <= 10; t++) {
		input();
		copyMap();
		getSum();
		cout << "#" << t << ' ' << answer << '\n';
	}

	return 0;
}