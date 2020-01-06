#include<iostream>

using namespace std;

int t, n;
int arr[1001];
bool check[1001];

//��ȯ�ϸ� ����Ŭ Ȯ��
void dfs(int start) {
	check[start] = 1;
	int nxt = arr[start];
	if (check[nxt] == 0) dfs(nxt);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];	//�迭 �����鼭
			check[i] = 0;	//check�迭�� �ʱ�ȭ ���ֱ� while loop�̹Ƿ�
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (check[i] == 0) {	//�湮���� ������ dfs
				dfs(i);
				cnt++;				//�ٵ��� 1 ����.
			}
		}
		cout << cnt << '\n';
	}

	return 0;
}