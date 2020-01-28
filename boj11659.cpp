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
	if (right < start || left > end) return 0;	//전체 범위와 특정 구간(left, right)가 겹치지 않음
	if (left <= start && end <= right) return tree[node];	//전체 범위가 left right에 완전 속해있음. 하위노드 탐색할 필요 없이 start~end 합인 tree[node]반환

	//그외. left right가 start~ end에 속해있거나 범위가 일부 겹칠 때
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
//이걸 이렇게 쉽게 푼 사람도 있음..
//숫자를 더해 줄 때 새 배열에 총 합을 넣어주는데 마지막 총합에서 구간의 합 시작 전을 뺴줌...
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