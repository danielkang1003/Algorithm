#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

int n, answer = INT_MAX;
int player[21][21];
bool check[21];
int half;

//팀을 나누는데 너무 깊게 생각해서 오래걸린 문제...
void dfs(int idx, int cnt) {
	if (cnt == half) {
		vector<int> team1, team2;
		for (int i = 1; i <= n; i++) {
			if (check[i] == 1) team1.push_back(i);
			else team2.push_back(i);
		}
		/*cout << "TEAM1: ";
		for (int i = 0; i < team1.size(); i++) {
			cout << team1[i] << ' ';
		}
		cout << "\nTEAM2: ";
		for (int i = 0; i < team2.size(); i++) {
			cout << team2[i] << ' ';
		}
		cout << '\n';*/
		int team1_stat = 0, team2_stat = 0;
		for (int i = 0; i < half; i++) {
			for (int j = 0; j < half; j++) {
				if (i == j) continue;
				/*cout << "TEAM1 선수 " << team1[i] << " 와 " << team1[j] << " 의 점수: "
					<< player[team1[i]][team1[j]] << "+" << player[team1[j]][team1[i]]<< ' '
					<<player[team1[i]][team1[j]] + player[team1[j]][team1[i]] <<'\n';
				cout << "TEAM2 선수 " << team2[i] << " 와 " << team2[j] << " 의 점수: "
					<< player[team2[i]][team2[j]] << "+" << player[team2[j]][team2[i]] << ' '
					<< player[team2[i]][team2[j]] + player[team2[j]][team2[i]] << '\n';*/

				team1_stat += (player[team1[i]][team1[j]]/* + player[team1[j]][team1[i]]*/);
				team2_stat += (player[team2[i]][team2[j]]/* + player[team2[j]][team2[i]]*/);
			}
		}
		int diff = abs(team1_stat - team2_stat);
		//cout << "팀의 스텟 차이: " << diff << '\n';
		if (answer > diff) answer = diff;

	}
	for (int i = idx; i <= n; i++) {
		if (check[i] == 0) {
			check[i] = 1;
			dfs(i + 1, cnt + 1);
			check[i] = 0;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> player[i][j];
		}
	}
	half = n / 2;
	dfs(1, 0);
	cout << answer;
	return 0;
}