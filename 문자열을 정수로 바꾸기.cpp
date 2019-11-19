#include<iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = 0;
	int strToInt = atoi(s.c_str());
	answer = strToInt;
	return answer;
}

int main() {
	string str1 = "1234", str2 = "-1234";
	cout << solution(str1) << '\n';
	cout << solution(str2) << '\n';

	return 0;
}