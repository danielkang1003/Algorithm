#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int n, answer;//이닝, 가장 높은 점수를 출력
int expectedScore[51][10];	//각 이닝의 선수들 예상 점수 저장 배열
//순열을 위한 배열
int order[10];
bool check[10];

int findMax(int a, int b) {
	return a > b ? a : b;
}

void startGame() {
	int score = 0;	//각 이닝당 성적을 더할 변수
	int playerIdx = 1;	//이닝끝나고 타석 서는 순서 유지하기 위함. 1번부터 시작
	int baseStatus[4];	//0: 홈, 1: 1루, 2: 2루, 3: 3루

	for (int i = 1; i <= n; i++) {
		int outCnt = 0;	//3아웃 카운트
		bool inningCheck = false;	//3아웃이면 다음 이닝으로 넘어감 true로 기존은 false
		memset(baseStatus, 0, sizeof(baseStatus));
		while (true) {
			for (int j = playerIdx; j < 10; j++) {
				//1번 선수부터 야구 시작
				int curPlayer = expectedScore[i][order[j]];
				//현재 타석의 타자가 0: 아웃, 1: 1안타,2: 2루타, 3: 3루타 칠 때
				if (curPlayer == 0) outCnt++;	//아웃침
				else if (curPlayer == 1) {
					for (int go = 3; go >= 1; go--) {
						if (baseStatus[go] == 1) {
							if (go == 3) {//3루 자리에 있으면
								baseStatus[go] = 0;//들어온것으로 처리
								score++;//점수 1점 추가
							}
							else {//3루 자리 아니면
								baseStatus[go + 1] = 1;	//한칸씩 전진
								baseStatus[go] = 0;	//원래 자리는 없음으로 표시
							}
						}
					}
					baseStatus[1] = 1;	//현재 타자가 1안타 쳤으므로 1루 상태에 1 체크
				}
				else if (curPlayer == 2) {	//2루타
					for (int go = 3; go >= 1; go--) {
						if (baseStatus[go] == 1) {
							if (go == 3 || go == 2) {
								baseStatus[go] = 0;
								score++;
							}
							else {
								baseStatus[go + 1] = 1;
								baseStatus[go] = 0;
							}
						}
					}
					baseStatus[2] = 1;
				}
				else if (curPlayer == 3) {	//3루타
					for (int go = 3; go >= 1; go--) {	//앞의 주자들 모두 들어올 수 있음
						if (baseStatus[go] == 1) {
							baseStatus[go] = 0;
							score++;
						}
					}
					baseStatus[3] = 1;
				}
				else {
					//홈런
					for (int go = 1; go <= 3; go++) {
						if (baseStatus[go] == 1) {
							baseStatus[go] = 0;
							score++;	//앞에 나가있는 선수가 있다면 점수 추가
						}
					}
					score++;	//자신이 홈런친거 1점 추가
				}

				if (outCnt == 3) {
					playerIdx = j + 1;	//다음 이닝에 이어서 치기위함
					if (playerIdx == 10) playerIdx = 1;	//마지막 타자까지 쳤다면 1로 다시 돌아옴
					//만약 9번째 타자에서 멈췄다면 9 + 1 (다음타자 위해 + 1) 이 10이라면 1로 다시 초기화
					inningCheck = true;
					break;
				}
			}
			//3아웃으로 이닝이 끝나면 종료
			if (inningCheck) break;
			playerIdx = 1;	//이닝이 끝나지 않았다면 1타자가 다시 타석에
		}
	}
	answer = findMax(answer, score);
}

void dfs(int cnt) {
	if (cnt == 10) {
		//모든 선수의 타순을 정하면 끝
		/*for (int i = 0; i < 10; i++) {
			cout << order[i] << ' ';
		}
		cout << '\n';*/
		startGame();
		return;
	}
	for (int i = 1; i < 10; i++) {
		if (check[i] == 0) {
			check[i] = 1;
			order[i] = cnt;
			dfs(cnt + 1);
			check[i] = 0;
		}
	}
}


int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < 10; j++) {
			//각 이닝당 9명 선수의 점수를 받음
			cin >> expectedScore[i][j];
		}
	}
	check[4] = 1;
	order[4] = 1;	//4번 타자의 타순은 1번으로 조건 지정
	dfs(2);

	cout << answer;
	return 0;
}