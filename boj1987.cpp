#include<iostream>
#include<algorithm>

using namespace std;

int r, c;
char map[21][21];
bool check[26];	//���ĺ� ������ŭ
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int answer;

void dfs(int x, int y, int cnt) {
	answer = max(answer, cnt);
	//cout << "���� �ְ��� ������: " << answer <<'\n';
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 1 || ny < 1 || nx >= r + 1 || ny >= c + 1) continue;
		char curAlpha = map[x][y];
		int curAlphaIdx = map[x][y] - 'A';
		char nextAlpha = map[nx][ny];
		int nextAlphaIdx = map[nx][ny] - 'A';
		//cout << "���� ���� ���ĺ�: " << curAlpha <<"(" << x <<',' <<y <<") " << " ���� ���� ���ĺ�: " << nextAlpha <<"(" << nx << ',' << ny << ") " <<'\n';
		if (check[nextAlphaIdx] == 1) continue;
		check[nextAlphaIdx] = 1;
		dfs(nx, ny, cnt + 1);
		check[nextAlphaIdx] = 0;
	}

}
int main() {
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> map[i][j];
		}
	}
	answer = 0;
	check[map[1][1] - 'A'] = 1;
	dfs(1, 1, 1);
	cout << answer;
	return 0;
}

//#include<iostream>
//#include<algorithm>
//#include<queue>
//
//using namespace std;
//
//int r, c;
//char map[21][21];
//bool check[21][21];
//int dx[4] = { 0,0,1,-1 };
//int dy[4] = { 1,-1,0,0 };
//char temp;
//
//bool alphabet[26] = { 0, };	//������ ���� ���ĺ����� Ȯ��
//
//int bfs() {
//	queue<pair<int, int>> q;
//	q.push({ 1,1 });
//	check[1][1] = 1;
//	int cnt = 1;
//	while (!q.empty()) {
//		int x = q.front().first;
//		int y = q.front().second;
//		char cur = map[x][y];
//		int curAlphabet = map[x][y] - 'A';
//		alphabet[curAlphabet] = 1;
//		cout << "���� ��� �ִ� ĭ: " << cur << '\n';
//		q.pop();
//
//		for (int dir = 0; dir < 4; dir++) {
//			int nx = x + dx[dir];
//			int ny = y + dy[dir];
//			char nextAlphabet = map[nx][ny];
//			int nxtAlphabet = map[nx][ny] - 'A';
//			if (cur == nextAlphabet) continue;
//			if (nx < 1 || ny < 1 || nx >= r + 1 || ny >= c + 1) continue;
//			if (check[nx][ny] == 1) continue;
//			if (alphabet[nxtAlphabet] == 1) continue;
//			cout << "���� ��ǥ: " << x << " " << y << " ���� ���ĺ�: " << cur << "\n�������� ��ǥ: " << nx << " " << ny << "���ĺ�: " << nextAlphabet << '\n';
//			cout << "������� ���� ĭ ��: " << cnt <<'\n';
//			alphabet[nxtAlphabet] = 1;
//			q.push({ nx,ny });
//			check[nx][ny] = 1;
//		}
//		cnt++;
//	}
//	return cnt;
//}
//
//int main() {
//	cin >> r >> c;
//	for (int i = 1; i <= r; i++) {
//		for (int j = 1; j <= c; j++) {
//			cin >> map[i][j];
//		}
//	}
//	int answer = bfs();
//	for (int i = 0; i < 26; i++) {
//		cout << alphabet[i] << ' ';
//	}
//	cout << '\n';
//	cout <<"��: "<< answer -1;
//	//cout << answer;
//	return 0;
//} 

