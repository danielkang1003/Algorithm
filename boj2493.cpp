#include<iostream>
#include<stack>
#include<vector>


using namespace std;

//로직은 숫자를 받아서 스택이 비어있으면 0 출력해주고 스택에 인덱스와 높이를 넣어준다
//스택이 비어있지 않다면 스택에 저장되있는 높이(s.top().second)와 현재 입력된 높이랑 비교한다
//비교해서 스택에 있는 것이 크다면 스택에 있는 인덱스(s.top().first 출력해주고 탈출
//만약 스택의 높이보다 입력된 높이가 크다면 스택의 상단에 있는 것은 어차피
//신호를 받지 못하므로 pop해주면 된다!using namespace std;

int n, num;
stack<pair<int, int>> s;
//n이 50만이라는 숫자여서 입출력을 printf,scanf 또는
//sync를 해주지 않으면 시간초과 뜸.
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		while (!s.empty()) {
			if (s.top().second > num) {
				cout << s.top().first << ' ';
				break;
			}
			s.pop();
		}

		if (s.empty()) cout << "0 ";
		s.push(make_pair(i, num));
	}
	return 0;
}