#include<iostream>

using namespace std;

int main() {
	char gear[4][9];	//string으로 입력을 받으면 마지막에 널문자 넣어주어야함
	for (int i = 0; i < 4; i++) {
		cin >> gear[i];
	}

	int k;
	cin >> k;
	while (k--) {
		int target, dir;	//target은 돌릴 톱니, dir은 방향
		cin >> target >> dir;
		target--;			//-1하는 이유는 배열에 있는 톱니는 0부터 넣었으므로
		int move_dir[4] = { 0, };	//각 톱니를 어떻게 움직일지 입력받을 배열
		move_dir[target] = dir;	//입력받은 톱니의 움직일 방향은 dir로 고정임

		for (int left = target - 1; left >= 0; left--) {
			int right = left + 1;
			if (gear[left][2] == gear[right][6]) {
				//극이 같을 때
				break;
			}
			else {
				//극이 다르면 움직임
				move_dir[left] = move_dir[right] * -1;	//-1로 곱하면 현재 dir 즉 옆의 톱니에 방향에 반대로 됨
			}
		}

		for (int right = target + 1; right < 4; right++) {
			int left = right - 1;
			if (gear[left][2] == gear[right][6]) {
				//극이 같을 때
				break;
			}
			else {
				//극이 다르면 움직임
				move_dir[right] = move_dir[left] * -1;	//-1로 곱하면 현재 dir 즉 옆의 톱니에 방향에 반대로 됨
			}
		}

		for (int i = 0; i < 4; i++) {
			if (move_dir[i] == 1) {
				//시계방향으로 회전
				char temp = gear[i][7];
				for (int j = 7; j >= 1; j--) {
					gear[i][j] = gear[i][j - 1];
				}
				gear[i][0] = temp;
			}
			else if (move_dir[i] == -1) {
				//반시계방향으로 회전
				char temp = gear[i][0];
				for (int j = 0; j < 7; j++) {
					gear[i][j] = gear[i][j + 1];
				}
				gear[i][7] = temp;
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < 4; i++) {
		if (gear[i][0] == '1') {
			answer += (1 << i);	//12시 방향(gear[i][변함]이 S극(1)이라면 1점, 2,4,8로 증가)
		}
	}
	cout << answer;
	return 0;
}