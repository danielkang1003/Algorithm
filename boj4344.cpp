#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

vector<int> scores;
int main() {
	int C, N;
	cin >> C;
	while (C--) {
		int count = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			int score = 0;
			cin >> score;
			scores.push_back(score);
		}
		//numeric에 있는 accumulate가 vector 원소값을 더해줌
		double avg = accumulate(scores.begin(), scores.end(), 0.0) / scores.size();
		
		//빌때까지 돌면서 점수가 평균보다 큰지 확인. 확인후 count
		while (!scores.empty()) {
			int check = scores.back();
			scores.pop_back();

			if (check > avg) count++;
		}
		printf("%.3lf%%\n", (double)count / N * 100);
	}

	return 0;
}