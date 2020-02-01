#include<iostream>

using namespace std;

int n, finalScore;
int playerScore[50][10]; //각 이닝별 선수 예상 점수
int optimizedSelect[10];	//순열로 선수 세우기 위한 배열
bool check[10];				//순열로 골라진 선수 판별위함

int findMaxScore(int a, int b) {
	return a > b ? a : b;
}

void gameStart() {
	int score = 0;	//매 게임마다 선수들이 성적낸 것을 비교하며 최대 점수를 고를 것임
	int playerIdx = 1;	//선수는 1번부터 투입
	for (int i = 0; i < n; i++) {	//첫(0번째부터) 이닝 부터 시작
		int outCnt = 0;	//3아웃이 되면 inningChange true로
		bool inningChange = false;	//3아웃 판단
		bool baseStatus[4] = { 0, };	//1,2,3루 자리 0으로 지정
		while (true) {
			for (int j = playerIdx; j < 10; j++) {	//선수들 게임에 내보냄
				int currentPlayer = playerScore[i][optimizedSelect[j]];	//이닝별 선수를 차례대로 고름
				//현재 선수의 값이 0 : 아웃, 1: 1안타, 2: 2안타, 3:3루타, 4: 홈런
				if (currentPlayer == 0) {
					//타석에 선 선수가 아웃(0)이면
					outCnt++;
				}
				else if (currentPlayer == 1) {
					//1안타 치면
					for (int go = 3; go >= 1; go--) {
						if (baseStatus[go] == 1) {
							//앞에 나간 선수가 있다면
							if (go == 3) {
								//3루에 선수가 있으면
								baseStatus[go] = 0;	//선수를 홈으로 들여오고
								score++;	//점수 추가
							}
							else {
								//2루와 1루의 선수들 이동
								baseStatus[go] = 0;
								baseStatus[go + 1] = 1;
							}
						}
					}
					baseStatus[1] = 1;	//현재 타자가 1루 치고 1번자리로 나감
				}
				else if (currentPlayer == 2) {
					for (int go = 3; go >= 1; go--) {
						if (baseStatus[go] == 1) {
							if (go == 3 || go == 2) {
								//3루 또는 2루에 이전 선수가 나가있다면
								baseStatus[go] = 0;
								score++;
							}
							else {	//go가 1루에 있을 때 -> 3루로 가야함
								baseStatus[go] = 0;
								baseStatus[go + 2] = 1;	//3루로 이동
							}
						}
					}
					//2안타 친 상태
					baseStatus[2] = 1;	//현재 타자가 2루쳤으므로 2번 자리로 이동
				}
				else if (currentPlayer == 3) {	//3루를 친 상태
					for (int go = 3; go >= 1; go--) {
						if (baseStatus[go] == 1) {	//3루를 치면 타석에 있는 모든 선수들을 들여보내고 점수 냄
							baseStatus[go] = 0;
							score++;
						}
					}
					baseStatus[3] = 1;
				}
				else {//홈런(4) 친 상태
					for (int go = 1; go <= 3; go++) {
						if (baseStatus[go] == 1) {	//앞에 나가있는 선수들을 들여보내고 점수 냄
							baseStatus[go] = 0;
							score++;
						}
					}
					score++;	//홈런친 현재 선수의 점수 냄
				}
				if (outCnt == 3) {//3 아웃은 inningChange를 true로 변경하고 다음 타자를 정해주어야
					inningChange = true;
					playerIdx = j + 1;	//j까지 타석에 섰으므로 j + 1 해주기
					if (playerIdx == 10) playerIdx = 1;	//마지막 선수가 9번이었다면 playerIdx = 10 (9 + 1)로 되므로 처음으로 돌려줌
					break;
				}
			}
			if (inningChange == true) break;
			playerIdx = 1;	//마지막 타자까지 공격 끝냈는데 3아웃 발생하지 않아서 계속 공격해야하는 상황.
			//마지막 타자까지 공격을 끝냈으므로 1번 선수부터 다시 시작
		}
	}
	finalScore = findMaxScore(finalScore, score);
}

void dfs(int cnt) {
	if (cnt == 10) {
		//모든 선수를 순열로 세움
		gameStart();	//게임을 시작하지
		return;
	}
	for (int i = 1; i < 10; i++) {
		//9명의 선수에게 번호 부여
		if (check[i] == 0) {
			check[i] = 1;
			optimizedSelect[i] = cnt;
			dfs(cnt + 1);
			check[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < 10; j++) {
			//각 이닝 마다 10 명의 선수 점수를 넣음
			cin >> playerScore[i][j];
		}
	}
	//감독은 4번타자를 1번 선수로 지목
	optimizedSelect[4] = 1;
	check[4] = 1;
	dfs(2);	//2번째 선수부터 순열로 선수 뽑기
	cout << finalScore;
	return 0;
}