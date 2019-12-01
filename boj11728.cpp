#include<iostream>

using namespace std;

int n, m; //�迭 a,b�� ũ��

void merge(int* a, int n, int* b, int m) {
	//merge�� �� �迭 �Ҵ�
	int* arr = new int[n + m];
	int idx = 0;
	int idx1 = 0;
	int idx2 = 0;

	//a �迭�� b �迭���� �������� ���Ѵ�
	//������ idx1(a �迭)�� idx2(b�迭�� ���) �� �� �迭�� ���̸�
	//���� ������ ���ȸ� ����
	while (idx1 < n && idx2 < m) {
		if (a[idx1] < b[idx2]) {
			arr[idx++] = a[idx1++];
		}
		else arr[idx++] = b[idx2++];
	}
	//���� ���� ���ؼ� �ְ� ���� ���� arr �迭�� �־��ش�
	while (idx1 < n) {
		//a �迭���� ������ ��
		arr[idx++] = a[idx1++];
	}
	while (idx2 < m) {
		//b �迭���� ������ ��
		arr[idx++] = b[idx2++];
	}
	for (int i = 0; i < n + m; i++)
		cout << arr[i]<< ' ';
	delete[] arr;
}
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	int* a = new int[n];
	int* b = new int[m];
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
	merge(a, n, b, m);
	delete[] a, b;
	return 0;
}