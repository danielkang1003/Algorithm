#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> seoul;


string solution(vector<string> seoul) {
	string answer = "�輭���� ";
	int size = seoul.size();
	for (int i = 0; i < size; i++) {
		if (seoul[i] == "Kim") answer += to_string(i);
	}
	answer += "�� �ִ�";
	return answer;
}

int main() {
	vector<string> seoul = { "Jane","Kim" };
	string answer = solution(seoul);
	cout << answer << '\n';

	return 0;
}