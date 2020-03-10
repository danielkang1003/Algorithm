#include<iostream>
#include<cstring>

using namespace std;

int tNum, pairNum, a, b, answer;
bool map[100][100], check[100];

void init() {
	memset(map, false, sizeof(map));
	memset(check, false, sizeof(check));
	answer = 0;
}

void dfs(int point) {
	check[point] = 1;
	if (point == 99) {	//끝점 도착하면
		answer = 1;
		return;
	}
	for (int i = 0; i < 100; i++) {
		//이동가능한 길이면서, 방문한적 없다면
		if (map[point][i] == 1 && check[i] == 0) dfs(i);
	}
}

void input() {
	cin >> tNum >> pairNum;
	for (int i = 0; i < pairNum; i++) {
		cin >> a >> b;
		map[a][b] = 1;
	}
	dfs(0);	//0부터 시작
}

int main() {
	for (int t = 1; t <= 10; t++) {
		init();
		input();
		cout << "#" << t << " " << answer << '\n';
	}
	return 0;
}
/*
1 16
0 1 0 2 1 4 1 3 4 8 4 3 2 9 2 5 5 6 5 7 7 99 7 9 9 8 9 10 6 10 3 7
*/