#include<iostream>
#include<algorithm>
using namespace std;

int colorArr[5]; //1 : R/ 2 : B/ 3: Y/ 4: G
int numArr[10]; //1~9 숫자


// 회고: 제출을 하는데 자꾸 틀렸다고 떠서 문제를 다시 읽었는데,
//		두가지 이상의 규칙을 적용할 수 있는 경우에 가장 높은 점수를 적용한다고
//		되어있다. 
//		세장의 카드가 같을때 처리에서 3장이 같고 또다른 2장의 숫자가 같음 처리를 먼저했어야했는데
//		3장만 같은것을 먼저 처리해줘서 if문에서 그걸 정답으로
//		처리해서 틀렸다고 떴었다.
//		문제에 해결책이 있따....
int main() {
	int biggestNum = 0;
	for (int i = 0; i < 5; i++) {
		char col;
		int num;
		cin >> col >> num;
		if (col == 'R') colorArr[1]++;
		else if (col == 'B') colorArr[2]++;
		else if (col == 'Y') colorArr[3]++;
		else colorArr[4]++;
		numArr[num]++;
		if (biggestNum < num) biggestNum = num;
	}
	int fourth = 0, third = 0, twiceNum1 = 0, twiceNum2 = 0;
	for (int i = 1; i <= 9; i++) {
		if (numArr[i] == 4) fourth = i;
		else if (numArr[i] == 3) third = i;
		else if (numArr[i] == 2) {
			if (twiceNum1 > 0) twiceNum2 = i;
			else twiceNum1 = i;
		}
	}

	bool checkSameColor = false;
	for (int i = 1; i <= 4; i++) {
		if (colorArr[i] == 5) checkSameColor = true;
	}
	bool straightNum = false;
	for (int i = 1; i <= 6; i++) {
		if (numArr[i] == 1 && numArr[i + 1] == 1 && numArr[i + 2] == 1 && numArr[i + 3] == 1 && numArr[i + 4] == 1)
			straightNum = true;
	}
	if (checkSameColor && straightNum) {
		cout << 900 + biggestNum;
		return 0;
	}
	if (checkSameColor) {
		cout << 600 + biggestNum;
		return 0;
	}

	if (straightNum) {
		cout << 500 + biggestNum;
		return 0;
	}

	if (fourth != 0) {
		cout << 800 + fourth;
		return 0;
	}

	if (third != 0 && twiceNum1 != 0) {
		cout << (10 * third) + twiceNum1 + 700;
		return 0;
	}
	if (third != 0) {
		cout << 400 + third;
		return 0;
	}

	if (twiceNum1 != 0 && twiceNum2 != 0) {
		int big = max(twiceNum1, twiceNum2);
		int small = min(twiceNum1, twiceNum2);
		cout << 300 + (10 * big) + small;
		return 0;
	}
	if (twiceNum1 != 0) {
		cout << 200 + twiceNum1;
		return 0;
	}
	cout << 100 + biggestNum;
	return 0;
}