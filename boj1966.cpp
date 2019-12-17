#include<iostream>
#include<queue>
using namespace std;

int tc, n, m, imp, cnt;

int main() {
	cin >> tc;
	while (tc--) {
		cnt = 0;
		cin >> n >> m;
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		for (int i = 0; i < n; i++) {
			cin >> imp;
			q.push(make_pair(i, imp));
			pq.push(imp);
		}
		while (!q.empty()) {
			int currentIdx = q.front().first;
			int currentImp = q.front().second;
			q.pop();

			//현재 우선순위의 중요도랑 큐에 있는 중요도가 같지 않다면
			//넘기기
			if (currentImp != pq.top()) {
				q.push(make_pair(currentIdx, currentImp));
			}
			else {
				//우선순위 중요도가 큐에있는 중요도와 같다면
				cnt++;
				pq.pop();
				if (currentIdx == m) {
					cout << cnt << '\n';
					break;
				}
			}
		}
	}

	return 0;
}