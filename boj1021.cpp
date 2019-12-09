#include<iostream>
#include<deque>

using namespace std;
int n, m;
int arr[51];
deque<int> dq;
deque<int>::iterator iter;
int cnt, num;
void Input() {
	//입력
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}
}


void Solve() {
	cnt = 0;
	for (int i = 0; i < m; i++) {
		int curNum;
		cin >> curNum;
		int idx = 0;
		for (iter = dq.begin(); iter != dq.end(); iter++) {
			if (*iter == curNum) break;
			idx++;
		}

		int left = idx;
		int right = dq.size() - idx;

		if (left < right) {
			for (int j = 1; j <= left; j++) {
				int front = dq.front();
				dq.push_back(front);
				dq.pop_front();
				cnt++;
			}
		}
		else {
			for (int j = 1; j <= right; j++) {
				int back = dq.back();
				dq.push_front(back);
				dq.pop_back();
				cnt++;
			}
		}
		//left까지 가고 나서는 앞에꺼 빼주기
		dq.pop_front();
	}
	cout << cnt;
}


int main() {
	Input();
	Solve();
	return 0;
}