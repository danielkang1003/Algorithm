#include<iostream>
#include<vector>

using namespace std;

//segment tree
//여러개의 데이터가 연속적으로 존재할 때 특정한 범위의 데이터의 합을 구하는 방법
//데이터 합을 가장 빠르고 간단하게 구할 수 있는 자료구조

const int number = 12;
int arr[] = { 1,9,3,8,4,5,5,9,10,3,4,5 };
int tree[4 * number];

//트리 초기화
int init(int start, int end, int node) {
	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

//left와 right는 구간합을 구하고 싶은 범위로 설정
int sum(int start, int end, int node, int left, int right) {
	if (left > end || right < start) return 0;	//범위 밖
	if (left <= start && end <= right) return tree[node];	//범위 내
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}


//idx 번째 수를 change로 변경할 때
void update(int start, int end, int node, int idx, int change) {
	if (idx < start || idx > end) return;	//원하는 구간이 아님
	tree[node] += change;
	if (start == end) return;	//한 원소를 가리키고 있는 즉 idx를 찾았을 때
	int mid = (start + end) / 2;
	update(start, mid, node * 2, idx, change);
	update(mid + 1, end, node * 2 + 1, idx, change);
}
//또는 이렇게
/*
long long update(int start, int end, int node, int idx, int change) {
	if (idx < start || end < idx) return tree[node];
	if (start == end) return tree[node] = arr[idx] = change;
	int mid = (start + end) / 2;
	return tree[node] = update(start, mid, node * 2, idx, change) +
		update(mid + 1, end, node * 2 + 1, idx, change);
}
*/


int main() {
	//구간 합 트리의 인덱스를 제외하고는 모두 인덱스 0부터 시작
	//구간 합 트리 생성
	init(0, number - 1, 1);
	//idx = 0~12 구간 합 구하기
	cout << "0부터 12까지의 구간 합: " << sum(0, number - 1, 1, 0, 12) << '\n';
	//idx = 3~8 구간 합 구하기
	cout << "3에서 8까지의 구간 합: " << sum(0, number - 1, 1, 3, 8) << '\n';
	//구간 합 갱신하기
	cout << "인덱스 5의 원소를 -5만큼 수정" << '\n';
	update(0, number - 1, 1, 5, -5);
	cout << "3부터 8까지의 구간 합: " << sum(0, number - 1, 1, 3, 8) << '\n';
	return 0;
}