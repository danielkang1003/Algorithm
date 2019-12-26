#include<iostream>
#include<vector>
using namespace std;

int n, s;
int arr[20];
int cnt;
void dfs(int sum, int k) {
	if (k == n) {	//k�� n�̶�� sum�̶� s�� ������ ���� ������ +1 ���ֱ�
		if (sum == s) cnt++;
		return;
	}
	dfs(sum + arr[k], k + 1);	//���� ����Ű�� ���� ���ϰ� n �ø���
	dfs(sum, k + 1);	//���� ����Ű�� ���� �ȴ��ϰ� n �ø���
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dfs(0, 0);	//����
	if (s == 0) {	//s�� 0�̸� ������ �ƹ��͵� �ȴ��ص� ����Ǽ��� �߰� �Ǽ� 1 ���ֱ�
		cout << cnt - 1;
	}
	else cout << cnt;
	return 0;
}

//��Ʈ����ũ
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
//	//1 << n �� 2�� n��
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