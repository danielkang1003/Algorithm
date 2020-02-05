#include<iostream>
#include<algorithm>
using namespace std;

int n;
int numbers[11];
int oper[4];
int maxVal = -1000000000, minVal = 1000000000;
int Plus, Minus, multiple, division;
int operCnt;

//void dfs1(int plus, int minus, int multi, int div, int sum, int cnt) {
//	if (cnt == n) {
//		if (maxVal < sum) maxVal = sum;
//		if (minVal > sum) minVal = sum;
//	}
//
//	if (plus > 0) dfs1(plus - 1, minus, multi, div, sum + numbers[cnt], cnt + 1);
//	if (minus > 0) dfs1(plus, minus - 1, multi, div, sum - numbers[cnt], cnt + 1);
//	if (multi > 0) dfs1(plus, minus, multi - 1, div, sum * numbers[cnt], cnt + 1);
//	if (div > 0) dfs1(plus, minus, multi, div - 1, sum / numbers[cnt], cnt + 1);
//}

void dfs2(int p, int mi, int mul, int div, int sum, int idx, int cnt) {
	if (cnt == operCnt) {
		maxVal = max(maxVal, sum);
		minVal = min(minVal, sum);
		return;
	}

	if (Plus > p) dfs2(p + 1, mi, mul, div, sum + numbers[idx], idx + 1, cnt + 1);
	if (Minus > mi) dfs2(p, mi + 1, mul, div, sum - numbers[idx], idx + 1, cnt + 1);
	if (multiple > mul) dfs2(p, mi, mul + 1, div, sum * numbers[idx], idx + 1, cnt + 1);
	if (division > div) dfs2(p, mi, mul, div + 1, sum / numbers[idx], idx + 1, cnt + 1);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}
	// dfs1
	/*for (int i = 0; i < 4; i++) {
		cin >> oper[i];
	}*/
	cin >> Plus >> Minus >> multiple >> division;
	operCnt = Plus + Minus + multiple + division;
	//+, -, *, /, sum, cnt
	//dfs1(oper[0], oper[1], oper[2], oper[3], numbers[0], 1);
	dfs2(0, 0, 0, 0, numbers[0], 1, 0);
	cout << maxVal << '\n' << minVal;
	return 0;
}