#include<iostream>

using namespace std;

int n, answer;
int col[15];		//y축 체크
int increase[30];	//x + y 체크 (왼쪽 밑 -> 오른쪽 위 방향)
int decrease[30];	//x - y + n - 1 (왼쪽 위 -> 오른쪽 아래 방향)
// col 배열의 크기는 n 만큼, inc, dec 는 2*n -1만큼 대각선에 부여
// 편의상 -1은 적용안하고 2n까지만 해서 적용


void dfs(int k) {
	if (k == n) {
		answer++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (col[i] || increase[i + k] || decrease[k - i + n - 1]) continue;
		col[i] = 1;
		increase[i + k] = 1;
		decrease[k - i + n - 1] = 1;
		dfs(k + 1);
		col[i] = 0;
		increase[i + k] = 0;
		decrease[k - i + n - 1] = 0;
	}
}

int main() {
	cin >> n;
	dfs(0);
	cout << answer;
	return 0;
}


////또는 이런 방법도 있더라..
//#include<iostream>
//#include<cmath>
//
//using namespace std;
//
//int n, answer;
//int chess[15];
//
//bool possible(int k) {
//	for (int i = 0; i < k; i++) {
//		if (chess[i] == chess[k] || abs(chess[k] - chess[i]) == k - i)
//			return false;
//	}
//	return true;
//}
//
//void dfs(int k) {
//	if (k == n) {
//		answer++;
//		return;
//	}
//	for (int i = 0; i < n; i++) {
//		chess[k] = i;
//		if (possible(k)) 
//			dfs(k + 1);
//	}
//}
//
//int main() {
//	cin >> n;
//	dfs(0);
//	cout << answer;
//
//	return 0;
//}