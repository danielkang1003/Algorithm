#include<iostream>

using namespace std;

typedef long long ll;
const int MOD = 1000000007;
int n, m, k;
ll arr[1000001];
ll tree[1000001 * 4];

ll init(int start, int end, int node) {
	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = (init(start, mid, node * 2) % MOD * init(mid + 1, end, node * 2 + 1) % MOD) % MOD;
}

ll update(int start, int end, int node, int target, int change) {
	if (target > end || target < start) return tree[node];
	if (start == end) return tree[node] = arr[target] = change;
	int mid = (start + end) / 2;
	return tree[node] = (update(start, mid, node * 2, target, change) * update(mid + 1, end, node * 2 + 1, target, change)) % MOD;
}

ll multiply(int start, int end, int node, int left, int right) {
	if (left > end || right < start) return 1;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return ((multiply(start, mid, node * 2, left, right) % MOD) * (multiply(mid + 1, end, node * 2 + 1, left, right) % MOD)) % MOD;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	init(1, n, 1);

	for (int i = 0; i < m + k; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, n, 1, b, c);
		}
		else {
			cout << multiply(1, n, 1, b, c) << '\n';
		}
	}
	return 0;
}