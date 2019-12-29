#include<iostream>
#include<queue>
using namespace std;

int n, w, l; //n : 트럭 수, w: 다리 길이, l: 다리 하중
int truck[1000];
queue<int> q;
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> w >> l;
	for (int i = 0; i < n; i++) {
		cin >> truck[i];
	}
	//idx: 트럭의 현재 위치, sum: 다리 무게를 지탱할 수 있는지,
	//cnt: 몇초가 지났는지, moved: 다리를 이동한 트럭 수
	int idx = 0, sum = 0, cnt = 0, moved = 0;
	//다리를 다 이동할 떄 까지 돌린다
	while (moved != n) {
		//q에 들어있는 트럭이 다리 길이를 넘으면 안됨.
		//그래서 만약에 가득 찼다면 밑의 방식으로 트럭을 뺴주고
		//트럭 무게면 moved 1 증가.
		if (q.size() >= w) {
			int temp = q.front();
			q.pop();
			sum -= temp;
			if (temp != 0) {	//이건 큐에 만약 다리 무게를 지탱하지 못한다면 0을 넣어줄 것임
				moved++;
			}
		}
		if (truck[idx] + sum <= l) {	//지나가는 트럭들과 현재 트럭이 큐에 들어가도 다리 무게 지탱이 가능하다면
			q.push(truck[idx]);
			sum += truck[idx];
			idx++;
		}
		else {
			q.push(0);	//지나가려는 트럭과 현재 다리를 지나는 트럭들이 무게를 넘으면 0 넣어줘야함.
		}
		cnt++;
	}
	cout << cnt;	//결과 출력
	return 0;
}