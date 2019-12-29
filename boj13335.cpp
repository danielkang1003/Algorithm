#include<iostream>
#include<queue>
using namespace std;

int n, w, l; //n : Ʈ�� ��, w: �ٸ� ����, l: �ٸ� ����
int truck[1000];
queue<int> q;
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> w >> l;
	for (int i = 0; i < n; i++) {
		cin >> truck[i];
	}
	//idx: Ʈ���� ���� ��ġ, sum: �ٸ� ���Ը� ������ �� �ִ���,
	//cnt: ���ʰ� ��������, moved: �ٸ��� �̵��� Ʈ�� ��
	int idx = 0, sum = 0, cnt = 0, moved = 0;
	//�ٸ��� �� �̵��� �� ���� ������
	while (moved != n) {
		//q�� ����ִ� Ʈ���� �ٸ� ���̸� ������ �ȵ�.
		//�׷��� ���࿡ ���� á�ٸ� ���� ������� Ʈ���� ���ְ�
		//Ʈ�� ���Ը� moved 1 ����.
		if (q.size() >= w) {
			int temp = q.front();
			q.pop();
			sum -= temp;
			if (temp != 0) {	//�̰� ť�� ���� �ٸ� ���Ը� �������� ���Ѵٸ� 0�� �־��� ����
				moved++;
			}
		}
		if (truck[idx] + sum <= l) {	//�������� Ʈ����� ���� Ʈ���� ť�� ���� �ٸ� ���� ������ �����ϴٸ�
			q.push(truck[idx]);
			sum += truck[idx];
			idx++;
		}
		else {
			q.push(0);	//���������� Ʈ���� ���� �ٸ��� ������ Ʈ������ ���Ը� ������ 0 �־������.
		}
		cnt++;
	}
	cout << cnt;	//��� ���
	return 0;
}