#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;

vector<int> v; //9���� �ϰ� ������ Ű�� ������ ����
stack<int> s; //2���� ��� ����
int height;	//�� �������� Ű

int main() {
	//total ������ �����ְ�, Ű�� ��� �޾Ҵ�.
	//9���� ������ Ű�� 100�� �Ѱ� 7 �������� Ű�� 100�̹Ƿ�
	//�� Ű�� �տ��� �θ��� ���ַ��� �ߴ�.
	int total = 0;
	for (int i = 0; i < 9; i++) {
		cin >> height;
		total += height;
		v.push_back(height);
	}
	//�� �κ��� ���� 9������ Ű �߿��� ������ �� ������ Ű�� ��
	int sub = total - 100;
	//������ 1 �� ������ 2�� Ű�� �������� ���� ����
	int num1 = 0, num2 = 0;
	
	sort(v.rbegin(), v.rend());	//sort�� ���ÿ� �ְ� ����Ҷ��� ����
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (v[i] + v[j] == sub) {	//��ü�� ���ƺ��鼭 �θ��� ���� ������ ������ ����
				num1 = v[i];
				num2 = v[j];
				break;
			}
		}
	}
	//����� ������ 2���� Ű�� ���Ϳ� ����� ���̶� ������ ���ÿ� �����ʰ�,
	//�������� ���ÿ� �־���
	for (int i = 0; i < 9; i++) {
		if (v[i] == num1 || v[i] == num2) {
			continue;
		}
		s.push(v[i]);
	}
	//����� ���
	for (int i = 0; i < 7; i++) {
		int top = s.top();
		cout << top << '\n';
		s.pop();
	}
	return 0;
}