#include<iostream>


using namespace std;
typedef long long ll;
ll tree[4 * 1000000];
ll arr[1000001];

int n, m, k, order;
ll b, c;

ll init(ll start, ll end, ll node) {
	if (start == end) return tree[node] = arr[start];
	ll mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

void update(ll start, ll end, ll node, ll targetIdx, ll diff) {
	if (targetIdx > end || targetIdx < start) return;
	tree[node] += diff;
	if (start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, targetIdx, diff);
	update(mid + 1, end, node * 2 + 1, targetIdx, diff);
}

ll sum(ll start, ll end, ll node, ll left, ll right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	init(1, n, 1);

	for (int i = 0; i < m + k; i++) {
		cin >> order >> b >> c;
		if (order == 1) {
			//숫자 변경
			int diff = c - arr[b];
			arr[b] = c;
			update(1, n, 1, b, diff);
		}
		else {
			//구간합 출력
			cout << sum(1, n, 1, b, c) << '\n';
		}
	}

	return 0;
}
