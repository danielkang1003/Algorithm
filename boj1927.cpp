#include<iostream>
//최소힙 문제 (부모 노드가 작음)
using namespace std;

int n;
int arr[100001];
int a_size = 0;

void add(int num) {
	a_size++;
	arr[a_size] = num;
	int idx = a_size;
	while (idx != 1) {
		int p_node = idx / 2;//부모 노드
		if (arr[p_node] < arr[idx]) break;	//부모노드가 작으면 넘어가고
		swap(arr[p_node], arr[idx]);		//아니면 스왑
		idx = p_node;						//인덱스는 p_node로 변경
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
		//왼쪽 자식의 idx( 2 *idx)가 a_size보다 크면 idx가 leaf임
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