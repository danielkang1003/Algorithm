#include<iostream>

using namespace std;

int n, answer;
int col[15];		//y�� üũ
int increase[30];	//x + y üũ (���� �� -> ������ �� ����)
int decrease[30];	//x - y + n - 1 (���� �� -> ������ �Ʒ� ����)
// col �迭�� ũ��� n ��ŭ, inc, dec �� 2*n -1��ŭ �밢���� �ο�
// ���ǻ� -1�� ������ϰ� 2n������ �ؼ� ����


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


////�Ǵ� �̷� ����� �ִ���..
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