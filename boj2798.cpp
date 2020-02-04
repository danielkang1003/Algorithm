#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
int card[100];
int check[100];
vector<int> v;
//조합

int sum, answer;
void dfs(int idx, int cnt) {
	if (cnt == 3) {
		sum = 0;
		//cout << "뽑은 수: ";
		for (int i = 0; i < v.size(); i++) {
			//cout << v[i] << ' ';
			sum += v[i];
		}

		//cout << "\n합: ";
		if (sum <= m) {
			answer = max(answer, sum);
			//cout << answer <<'\n';
		}

		/*else {
			cout << -1 << '\n';
		}*/
		return;
	}
	for (int i = idx; i < n; i++) {
		if (check[i] == 0) {
			check[i] = 1;
			v.push_back(card[i]);
			dfs(i, cnt + 1);
			v.pop_back();
			check[i] = 0;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}
	answer = 0;
	dfs(0, 0);
	cout << answer;

	return 0;
}