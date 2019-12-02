#include<iostream>
#include<algorithm>
using namespace std;
pair<int, int> time[100001];
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	//(시작, 끝) 시간이 아닌, (끝시간, 시작시간)으로 저장
	for (int i = 0; i < n; i++) {
		cin >> time[i].second >> time[i].first;
	}

	sort(time, time + n);
	/*for (int i = 0; i < n; i++) {
		cout << time[i].first << ' ' <<time[i].second<<'\n';
	}*/
	int res = 0;	//최대 사용할 수 있는 회의수 카운트
	int cur = 0;	//현재 시간을 잡아준다.
	for (int i = 0; i < n; i++) {
		if (cur > time[i].second) continue;	//만약 현재시간보다 시작시간이 이전이라면 넘어간다
		//cout << "현재 시간: " << cur << " " << "고른 회의" << time[i].first << " " << time[i].second << '\n';
		res++;	//회의 수 증가 ( 시작 시간이 현재시간 이후인 회의이므로)
		cur = time[i].first;	//현재시간을 끝나는 시간으로 변경

	}
	cout << res << '\n';
	return 0;
}