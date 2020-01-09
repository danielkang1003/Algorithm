#include<iostream>
#include<queue>

using namespace std;

int n;
queue<int> q;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	//카드 q에 넣기
	for (int i = 1; i <= n; i++) q.push(i);
	//q가 비어있지않으면 숫자를 뒤로 넘겨주고 1개 남으면 출력해주고 끝
	while (!q.empty()) {
		if (q.size() == 1) {
			cout << q.front();
			q.pop();
			break;
		}
		//이 부분이 앞의 카드를 버리고 그다음 카드를 뒤로 넘기고 넘긴 값을 삭제해주는 작업
		q.pop();
		q.push(q.front());
		q.pop();
	}

	return 0;
}