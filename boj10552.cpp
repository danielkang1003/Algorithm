#include<iostream>
#include<vector>
#include<queue>

using namespace std;


int n, m, p;	//사람 수, 티비 채널 수, 티비에 켜진 채널
vector<int> channel[100001];
bool check[100001];

int changeChannel() {
	queue<int> q;
	q.push(p);	//첫 채널 넣어줌
	check[p] = 1;	//켜진 채널 체크

	int cnt = 0;
	while (!q.empty()) {
		int currentCh = q.front();
		q.pop();

		if (channel[currentCh].size() == 0) return cnt;	//채널을 싫어하는 사람이있다면 1이상일 것
		if (check[channel[currentCh][0]] == true)break;	//방문했다면
		q.push(channel[currentCh][0]);	//좋아하는 채널 넣기
		check[channel[currentCh][0]] = 1;	//방문 체크
		cnt++;

	}
	return -1;	//그렇지 않을 때
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> m >> p;
	for (int i = 0; i < n; i++) {	//나이 작은 -> 큰 순
		int a, b;	//좋아하는 채널, 싫어하는 채널
		cin >> a >> b;
		channel[b].push_back(a);	//싫어하는 채널을 인덱스로 두고 좋아하는 채널 넣기
	}
	//출력으로 채널 변경에 필요한 횟수, 안된다면 -1
	cout << changeChannel() << '\n';

}