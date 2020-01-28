#include<iostream>

using namespace std;

int n, m;
int arr[100001];
int tree[4 * 100000];

int init(int start, int end, int node) {
	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

int sum(int start, int end, int node, int left, int right) {
	if (right < start || left > end) return 0;	//��ü ������ Ư�� ����(left, right)�� ��ġ�� ����
	if (left <= start && end <= right) return tree[node];	//��ü ������ left right�� ���� ��������. ������� Ž���� �ʿ� ���� start~end ���� tree[node]��ȯ

	//�׿�. left right�� start~ end�� �����ְų� ������ �Ϻ� ��ĥ ��
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);

}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	init(1, n, 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << sum(1, n, 1, a, b) << '\n';
	}

	return 0;
}
/*
//�̰� �̷��� ���� Ǭ ����� ����..
//���ڸ� ���� �� �� �� �迭�� �� ���� �־��ִµ� ������ ���տ��� ������ �� ���� ���� ����...
int arr[100001];
int sum[100001];

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n,m, answer = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		answer += arr[i];
		sum[i] = answer;
	}
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a, b;
		cout << sum[end] - sum[a -1] <<'\n';
	}
	return 0;
}

*/