#include<iostream>
#include<string>
#include<stack>
//valid PS(VPS)
using namespace std;



int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string input;	//괄호 받음
		cin >> input;
		stack<char> s;
		bool flag = true;
		int len = input.length();
		for (int i = 0; i < len; i++) {
			if (s.empty()) {
				//비어있고, ( 나오면
				if (input[i] == '(') {
					s.push(input[i]);
				}
				else if (input[i] == ')') {
					//비어있는데 ) 나오면 틀린 것
					flag = false;
					break;
				}
			}
			else {//비어있지 않을 때
				if (input[i] == '(') {
					s.push(input[i]);
				}
				else if (input[i] == ')') {
					if (s.top() == '(') {
						s.pop();
					}
				}
			}
		}
		if (!flag || !s.empty()) cout << "NO\n";
		else cout << "YES\n";

		//나는 위와 같이 for 안에 엄청 복잡하게 했는데,
		//간단한 풀이를 찾아보니 이렇게도 풀엇다.
		//스택이 비어있고, 인풋이 )면 강제로 넣고,
		//for문 도는 것을 중단 시키고 비어있지 않으니까
		//NO를 호출하도록 유도했다...감탄
		//이렇게 배워간다.
		/*
		for (int i = 0; i < len; i++) {
			if (input[i] == '(') s.push(input[i]);
			else if (input[i] == ')') {
				if (s.empty()) {
					s.push(input[i]);
					break;
				}
				else s.pop();
			}
		}
		if (!s.empty()) cout << "NO\n";
		else cout << "YES\n";
		*/
	}

	return 0;
}