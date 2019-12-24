#include<iostream>
#include<vector>
using namespace std;
//조합 문제, 중복 x, 오름차순 정렬 되서 주어짐

int k;			//k가 0이 나오면 종료
int lotto[13];	//k개의 수를 받을 배열
vector<int> v;	//조합을 위한

void dfs(int idx, int cnt) {
	//우리는 6가지의 수를 뽑을 거므로 cnt == 6가 되면 출력
	if (cnt == 6) {
		for (int i = 0; i < 6; i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = idx; i < k; i++) {
		v.push_back(lotto[i]);	//벡터에 하나씩 담아주고
		dfs(i + 1, cnt + 1);	//dfs 돌려주기
		v.pop_back();
	}
}

int main() {
	//k가 0이 나올 때까지 무한루프
	while (1) {
		cin >> k;
		if (k == 0) break;	//탈출
		for (int i = 0; i < k; i++) {
			cin >> lotto[i];
		}
		//탐색 시작
		dfs(0, 0);
		cout << '\n';
	}

	return 0;
}