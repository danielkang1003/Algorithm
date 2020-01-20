#include<iostream>

using namespace std;

int n;
//char room[101][101];
string room[101];

int vertical() {
	int answer = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (room[i][j] == '.') {
				cnt++;
			}
			else if (room[i][j] == 'X') {
				if (cnt >= 2) {
					answer++;
					cnt = 0;
				}
				else cnt = 0;
			}
		}
		if (cnt >= 2) answer++;
	}
	return answer;
}

int horizontal() {
	int answer = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (room[j][i] == '.') cnt++;
			else if (room[j][i] == 'X') {
				if (cnt >= 2) {
					answer++;
					cnt = 0;
				}
				else cnt = 0;
			}
		}
		if (cnt >= 2) answer++;
	}
	return answer;
}

int main() {
	//规过 1
	//cin >> n;
	//for (int i = 0; i < n; i++) {
	//	cin >> room[i];
	//}
	//int ver = 0, hor = 0;	//技肺 啊肺
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n-1; j++) {
	//		hor += room[i][j] == '.' && room[i][j + 1] == '.' && room[i][j + 2] != '.',
	//		ver += room[j][i] == '.' && room[j + 1][i] == '.' && room[j + 2][i] != '.';
	//	}
	//}
	//cout << hor << ' '<< ver << '\n';

	//规过 2
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> room[i];
	}
	cout << vertical() << " " << horizontal() << '\n';

	return 0;
}