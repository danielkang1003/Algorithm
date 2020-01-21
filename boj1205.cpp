#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, youjinScore, p;
vector<int> v;

int main() {
	cin >> n >> youjinScore >> p;
	int rank = 1;

	for (int i = 0; i < n; i++) {
		int scores;
		cin >> scores;
		v.push_back(scores);
	}
	if (n == p && v[n - 1] >= youjinScore) {
		//리스트 꽉차고 유진이 점수도 낮으면
		rank = -1;
	}
	else {
		for (int i = 0; i < n; i++) {
			//점수 시스템에 올라간 번호를 돌면서 유진이 점수보다 높은게 있으면
			//더해줘서 등수 구해주기
			if (v[i] > youjinScore) rank++;
		}
	}
	cout << rank;
	return 0;
}