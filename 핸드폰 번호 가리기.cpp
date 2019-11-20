#include<iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
	string answer = "";
	//int size = phone_number.size();
	////번호 길이가 11일때(핸드폰)와 9와 10일때 (서울은 9자리, 그 외는 10자리 지방 번호)
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
	////서울 지역번호 02일때
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