#include<iostream>
#include<vector>

using namespace std;

//segment tree
//�������� �����Ͱ� ���������� ������ �� Ư���� ������ �������� ���� ���ϴ� ���
//������ ���� ���� ������ �����ϰ� ���� �� �ִ� �ڷᱸ��

const int number = 12;
int arr[] = { 1,9,3,8,4,5,5,9,10,3,4,5 };
int tree[4 * number];

//Ʈ�� �ʱ�ȭ
int init(int start, int end, int node) {
	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

//left�� right�� �������� ���ϰ� ���� ������ ����
int sum(int start, int end, int node, int left, int right) {
	if (left > end || right < start) return 0;	//���� ��
	if (left <= start && end <= right) return tree[node];	//���� ��
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}


//idx ��° ���� change�� ������ ��
void update(int start, int end, int node, int idx, int change) {
	if (idx < start || idx > end) return;	//���ϴ� ������ �ƴ�
	tree[node] += change;
	if (start == end) return;	//�� ���Ҹ� ����Ű�� �ִ� �� idx�� ã���� ��
	int mid = (start + end) / 2;
	update(start, mid, node * 2, idx, change);
	update(mid + 1, end, node * 2 + 1, idx, change);
}
//�Ǵ� �̷���
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
	//���� �� Ʈ���� �ε����� �����ϰ�� ��� �ε��� 0���� ����
	//���� �� Ʈ�� ����
	init(0, number - 1, 1);
	//idx = 0~12 ���� �� ���ϱ�
	cout << "0���� 12������ ���� ��: " << sum(0, number - 1, 1, 0, 12) << '\n';
	//idx = 3~8 ���� �� ���ϱ�
	cout << "3���� 8������ ���� ��: " << sum(0, number - 1, 1, 3, 8) << '\n';
	//���� �� �����ϱ�
	cout << "�ε��� 5�� ���Ҹ� -5��ŭ ����" << '\n';
	update(0, number - 1, 1, 5, -5);
	cout << "3���� 8������ ���� ��: " << sum(0, number - 1, 1, 3, 8) << '\n';
	return 0;
}