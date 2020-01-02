#include<iostream>

using namespace std;

int n, a, b, c;
int classroom[1000001];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		classroom[i] = a;
	}
	cin >> b >> c;

	long long total = 0;
	for (int i = 0; i < n; i++) {
		classroom[i] = classroom[i] - b;	//�Ѱ����� 1����. ���ְ�
		total++;							//1�� �÷��ֱ�
		if (classroom[i] > 0) {				//�÷��ְ� ���� �л��� ������
			int subTeacher = classroom[i] / c;	//�ΰ������� �Ѿ
			if (classroom[i] % c != 0) {		//�׷��� �л��� ������
				subTeacher++;					//�ΰ��� �Ѹ� ����
			}
			total += subTeacher;			//�� ������ �ΰ��� ��
		}
	}
	cout << total;
	return 0;
}