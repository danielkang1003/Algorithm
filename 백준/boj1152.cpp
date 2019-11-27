#include<iostream>
#include<string>	//getline 쓰기 위한 라이브러리
using namespace std;


int main() {
	string str;
	getline(cin, str);
	int len = str.length(), count = 1;
	for (int i = 1; i < len; i++) {
		if (str[i] == ' ' && str[i] != str[i - 1]) {//str[1]은 빈칸 str[0]은 문자라면
			count++;	//하나 증가
		}
	}
	if (str[len - 1] == ' ') {//맨 마지막에 빈칸일 시 선언을 1로 햇으니까
		count--;
	}
}
