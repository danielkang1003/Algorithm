#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m, k;
int food[11][11];
int addFood[11][11];
vector<int> tree[11][11];
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };

void print() {
	cout << "################\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << food[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "################\n";
}

void ssSeason() {	//봄여름 시즌
	//print();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (tree[i][j].size() == 0) continue;
			//나무가 없다면 지나감
			int deadTreeFood = 0;
			vector<int> addAge;
			sort(tree[i][j].begin(), tree[i][j].end());	//나이가 작은거가 앞으로 오기위해
			for (int k = 0; k < tree[i][j].size(); k++) {
				int age = tree[i][j][k];
				//cout << "(" << i << ' ' << j << ")의 나무 나이: " << age <<'\n';
				if (food[i][j] >= age) {//양분이 부족하지 않으면
					food[i][j] -= age;
					addAge.push_back(age + 1);
					//cout << "양분을 흡수해서 (" << i << ' ' << j << ")의 나이는" << age << "이고 남은 양분은 " << food[i][j] << '\n';
				}
				else {
					deadTreeFood += (age / 2);
					//cout << "(" << i << ' ' << j << ")의 나무가 죽어 양분이 " << deadTreeFood << "만큼 추가됩니다\n";
				}
			}
			tree[i][j].clear();	//진행했던 나무비워주고 새로 넣어주기
			for (int k = 0; k < addAge.size(); k++) {
				tree[i][j].push_back(addAge[k]);	//양분이 있어서 나이를 먹은 나무를 넣어줌
			}
			food[i][j] += deadTreeFood;
		}
	}
	//cout << "봄& 여름: \n";
	//print();
}

void fall() { //가을에는 나무 번식. 나이는 5배수인것만 인접 8칸에 나이가 1인 나무 생성
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (tree[i][j].size() == 0) {
				//cout << "(" << i << ',' << j << ")에 나무가 없습니다.\n";
				continue;
			}

			for (int k = 0; k < tree[i][j].size(); k++) {
				int age = tree[i][j][k];
				if (age % 5 == 0) {
					//cout << "(" << i << ',' << j << ")의 나이가 5의 배수 입니다.\n";
					for (int dir = 0; dir < 8; dir++) {
						int nx = i + dx[dir];
						int ny = j + dy[dir];
						if (nx < 1 || ny < 1 || nx >= n + 1 || ny >= n + 1) continue;
						tree[nx][ny].push_back(1);
					}
				}

				//cout << "(" << i << ',' << j << ")에 나무가 있지만 나이가 " << age << "로 5의 배수가 아닙니다\n";
			}
		}
	}
	//cout << "가을: \n";
	//print();
}

void winter() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			food[i][j] += addFood[i][j];
		}
	}
	//cout << "겨울: \n";
	//print();
}

int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> addFood[i][j];
			food[i][j] = 5;
		}
	}

	for (int i = 0; i < m; i++) {
		int x, y, old;
		cin >> x >> y >> old;
		tree[x][y].push_back(old);	//한 칸에 여러개의 나무가 있을수도 있으므로 각 나무의 나이를 저장
	}

	for (int i = 0; i < k; i++) {
		//k년까지 사계절 활동
		ssSeason();
		fall();
		winter();
	}
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < tree[i][j].size(); k++)
				answer++;
		}
	}
	cout << answer;
	return 0;
}