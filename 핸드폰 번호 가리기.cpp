#include<iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
	string answer = "";
	//int size = phone_number.size();
	////��ȣ ���̰� 11�϶�(�ڵ���)�� 9�� 10�϶� (������ 9�ڸ�, �� �ܴ� 10�ڸ� ���� ��ȣ)
	//if (size == 11) {
	//	for (int i = 0; i < size; i++) {
	//		if (i <= 6) answer.append("*");
	//		else answer.push_back(phone_number[i]);
	//	}
	//}
	//else if (size == 10) {
	//	for (int i = 0; i < size; i++) {
	//		if (i <= 5) answer.append("*");
	//		else answer.push_back(phone_number[i]);
	//	}
	//}
	////���� ������ȣ 02�϶�
	//else if (size == 9) {
	//	for (int i = 0; i < size; i++) {
	//		if (i <= 4) answer.append("*");
	//		else answer.push_back(phone_number[i]);
	//	}
	//}
	int size = phone_number.size();
	for (int i = 0; i < size - 4; i++) {
		phone_number[i] = '*';
	}

	return phone_number;
}

int main() {
	string phone_number = "027778888";
	cout << solution(phone_number) << '\n';

	return 0;
}