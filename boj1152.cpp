#include<iostream>
#include<string>	//getline ���� ���� ���̺귯��
using namespace std;


int main() {
	string str;
	getline(cin, str);
	int len = str.length(), count = 1;
	for (int i = 1; i < len; i++) {
		if (str[i] == ' ' && str[i] != str[i - 1]) {//str[1]�� ��ĭ str[0]�� ���ڶ��
			count++;	//�ϳ� ����
		}
	}
	if (str[len - 1] == ' ') {//�� �������� ��ĭ�� �� ������ 1�� �����ϱ�
		count--;
	}
}