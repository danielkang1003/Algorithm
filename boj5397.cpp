#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
int n;	//TC
string input;
stack<char> s_main, s_temp;
int main() {
	//문자열 길이가 1000000이므로 속도 향상위해 사용
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;

	//주어진 TC 만큼 반복
	while (n--) {
		cin >> input;

		//입력받는 문자열 만큼 돌리기위해 length 사용하여 len에 넣어줌
		int len = input.length();
		for (int i = 0; i < len; i++) {
			//메인 스택이 비어있지 않고 반복되는 인풋의 i가 < 일 떄
			//메인 스택의 것을 temp로 넣고 메인에서는 빼주기
			if (input[i] == '<') {
				if (!s_main.empty()) {
					s_temp.push(s_main.top());
					s_main.pop();
				}
			}
			//temp 스택이 비어있지 않고 반복되는 인풋의 i가 >일 떄
			//temp에 저장되어있는 글자를 메인으로 넣어주고 temp에서 pop
			else if (input[i] == '>') {
				if (!s_temp.empty()) {
					s_main.push(s_temp.top());
					s_temp.pop();
				}
			}
			//-면 그냥 메인에서 삭제해주기
			else if (input[i] == '-') {
				if (!s_main.empty()) s_main.pop();
			}
			//< > - 아니면 메인에다가 넣어주기
			else {
				s_main.push(input[i]);
			}
		}

		//temp 스택이 비어있지 않으면 다 빼주고 메인에 넣어주기
		while (!s_temp.empty()) {
			s_main.push(s_temp.top());
			s_temp.pop();
		}

		//메인 스택의 것을 answer 문자열에 넣기
		string answer = "";
		while (!s_main.empty()) {
			answer += s_main.top();
			s_main.pop();
		}
		//reverse해주면 원래대로 출력!
		reverse(answer.begin(), answer.end());

		cout << answer << '\n';
	}

	return 0;
}