#include<iostream>
#include<algorithm>
using namespace std;

int score[9], selected[6];
bool check[9];
int maxScore = -1;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	for (int i = 1; i <= 8; i++) {
		cin >> score[i];
	}
	int maxScore, sum = 0, idx = 0, cnt = 0;
	while (true) {
		cnt++;
		maxScore = -1;
		for (int i = 1; i <= 8; i++) {
			if (maxScore < score[i] && check[i] == 0) {
				maxScore = score[i];
				idx = i;
			}
		}
		sum += maxScore;
		check[idx] = 1;
		selected[cnt] = idx;
		if (cnt == 5) break;
	}
	cout << sum << '\n';
	sort(selected + 1, selected + 6);
	for (int i = 1; i <= 5; i++) {
		cout << selected[i] << ' ';
	}

	return 0;
}