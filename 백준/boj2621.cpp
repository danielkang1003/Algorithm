#include<iostream>
#include<algorithm>
using namespace std;

int colorArr[5]; //1 : R/ 2 : B/ 3: Y/ 4: G
int numArr[10]; //1~9 ����


// ȸ��: ������ �ϴµ� �ڲ� Ʋ�ȴٰ� ���� ������ �ٽ� �о��µ�,
//		�ΰ��� �̻��� ��Ģ�� ������ �� �ִ� ��쿡 ���� ���� ������ �����Ѵٰ�
//		�Ǿ��ִ�. 
//		������ ī�尡 ������ ó������ 3���� ���� �Ǵٸ� 2���� ���ڰ� ���� ó���� �����߾���ߴµ�
//		3�常 �������� ���� ó�����༭ if������ �װ� ��������
//		ó���ؼ� Ʋ�ȴٰ� ������.
//		������ �ذ�å�� �ֵ�....
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