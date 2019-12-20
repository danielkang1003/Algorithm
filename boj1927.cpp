#include<iostream>
//�ּ��� ���� (�θ� ��尡 ����)
using namespace std;

int n;
int arr[100001];
int a_size = 0;

void add(int num) {
	a_size++;
	arr[a_size] = num;
	int idx = a_size;
	while (idx != 1) {
		int p_node = idx / 2;//�θ� ���
		if (arr[p_node] < arr[idx]) break;	//�θ��尡 ������ �Ѿ��
		swap(arr[p_node], arr[idx]);		//�ƴϸ� ����
		idx = p_node;						//�ε����� p_node�� ����
	}
}

int top() {
	if (a_size == 0) return 0;
	else return arr[1];
}

void pop() {
	if (a_size == 0) return;
	swap(arr[1], arr[a_size]);
	a_size--;
	int idx = 1;
	while (2 * idx <= a_size) {
		//���� �ڽ��� idx( 2 *idx)�� a_size���� ũ�� idx�� leaf��
		int min_child;
		if (arr[2 * idx] < arr[2 * idx + 1] || 2 * idx + 1 > a_size) min_child = 2 * idx;
		else min_child = 2 * idx + 1;
		if (arr[idx] < arr[min_child]) break;
		swap(arr[idx], arr[min_child]);
		idx = min_child;
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	while (n--) {
		int num;
		cin >> num;
		if (num == 0) {
			cout << top() << '\n';
			pop();
		}
		else {
			add(num);
		}
	}

	return 0;
}