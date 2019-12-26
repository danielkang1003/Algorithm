#include<iostream>
#include<vector>
using namespace std;

int n, s;
int arr[20];
int cnt;
void dfs(int sum, int k) {
	if (k == n) {	//k가 n이라면 sum이랑 s가 같은지 보고 같으면 +1 해주기
		if (sum == s) cnt++;
		return;
	}
	dfs(sum + arr[k], k + 1);	//현재 가리키는 숫자 더하고 n 늘리기
	dfs(sum, k + 1);	//현재 가리키는 수를 안더하고 n 늘리기
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dfs(0, 0);	//조합
	if (s == 0) {	//s가 0이면 끝까지 아무것도 안더해도 경우의수가 추가 되서 1 뺴주기
		cout << cnt - 1;
	}
	else cout << cnt;
	return 0;
}

//비트마스크
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int n, s, cnt;
//const int MAX = 21;
//int arr[MAX];
//int main() {
//	cin >> n >> s;
//	for (int i = 0; i < n; i++) {
//		cin >> arr[i];
//	}
//	//1 << n 은 2의 n승
//	for (int i = 1; i < (1 << n); i++) {
//		int tmp = i;
//		int tot = 0;
//		for (int j = 0; j < n; j++) {
//			if (tmp % 2 == 1) tot += arr[j];
//			tmp /= 2;
//		}
//		if (tot == s) cnt++;
//	}
//	cout << cnt;
//
//	return 0;
//}