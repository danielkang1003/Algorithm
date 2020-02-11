#include<iostream>
#include<queue>

using namespace std;

int n, k;	//수빈, 동생
bool check[100001];

//방법 1. priority queue 사용. 이동 시간 기준으로 순위를 세움
int pqbfs() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	//경과 시간 기준으로 우선순위를 결정해야해서
	//경과 시간이 짧으면 더 높은 우선순위를 갖도록 pq 정의
	pq.push({ 0,n });	//경과 시간 기준으로. 짧을수록 우선순위가 큼
	check[n] = 1;
	while (!pq.empty()) {
		int cnt = pq.top().first;	//이동 시간
		int cur = pq.top().second;	//위치
		pq.pop();

		if (cur == k) return cnt;

		if (cur * 2 <= 100001 && check[cur * 2] == 0) {
			pq.push({ cnt, cur * 2 });
			check[cur * 2] = 1;
		}
		if (cur + 1 <= 100001 && check[cur + 1] == 0) {
			pq.push({ cnt + 1, cur + 1 });
			check[cur + 1] = 1;
		}
		if (cur - 1 >= 0 && check[cur - 1] == 0) {
			pq.push({ cnt + 1, cur - 1 });
			check[cur - 1] = 1;
		}
	}
}


//방법 2. 일반 bfs
//왼쪽으로 먼저가는 것이 아닌 오른쪽으로 먼저 가면 오답처리뜸.
int bfs() {
	queue<pair<int, int>> q;
	check[n] = 1;
	q.push({ n, 0 });	//수빈 위치, 시간
	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;

		//cout << "현재 수빈 자리: " << cur << '\n';
		if (cur == k) {
			return cnt;
			break;
		}
		q.pop();

		//순간이동
		if (cur * 2 <= 100000 && check[cur * 2] == 0) {
			q.push({ cur * 2, cnt });
			check[cur * 2] = 1;
		}
		////////////////////////////////////////////////
		//오답 처리 조심해야하는 부분.
		if (cur - 1 >= 0 && check[cur - 1] == 0) {
			q.push({ cur - 1, cnt + 1 });
			check[cur - 1] = 1;
		}
		if (cur + 1 <= 100000 && check[cur + 1] == 0) {
			q.push({ cur + 1, cnt + 1 });
			check[cur + 1] = 1;
		}
		////////////////////////////////////////////////
	}
}

int main() {
	cin >> n >> k;
	//int answer = bfs();
	int answer = pqbfs();
	cout << answer;
	return 0;
}