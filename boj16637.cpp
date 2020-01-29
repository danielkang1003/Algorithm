//방법 1. 기본 완탐
#include<iostream>
#include<climits>

using namespace std;

int n, depth;
string input;
long long answer = INT_MIN;	//climits로 음수 최대값으로 선언(음수값의 답 처리위해)
int num[10], oper[10];

int cal(int a, int b, char oper) {
	if (oper == '+') return a + b;
	else if (oper == '-') return a - b;
	else if (oper == '*') return a * b;
}

int maxNum(int a, int b) {
	return a > b ? a : b;
}

void dfs(int operationIdx, int numResult) {
	if (operationIdx == depth) {
		answer = maxNum(answer, numResult);
		return;
	}
	//현재 위치 기준으로 괄호 묶어서 계산해나가기
	int currentResult = cal(numResult, num[operationIdx + 1], oper[operationIdx]);
	dfs(operationIdx + 1, currentResult);

	//다음 자리에 괄호 처리하여 계산 이어나가기
	if (operationIdx + 1 < depth) {
		int nxtResult = cal(num[operationIdx + 1], num[operationIdx + 2], oper[operationIdx + 1]);
		int curResult = cal(numResult, nxtResult, oper[operationIdx]);
		dfs(operationIdx + 2, curResult);
	}
}

int main() {
	cin >> n >> input;
	int len = input.length();
	int numIdx = 0, operIdx = 0;
	for (int i = 0; i < len; i++) {
		if (i % 2 == 0) num[numIdx++] = input[i] - '0';	//숫자만 담은 배열
		else oper[operIdx++] = input[i];	//부호만 담은 배열
	}
	depth = n / 2;
	if (n == 1) {
		cout << num[0] << '\n';
		return 0;
	}
	else if (n == 3) {
		cout << cal(num[0], num[1], oper[0]) << '\n';
		return 0;
	}

	dfs(0, num[0]);
	cout << answer << '\n';
	return 0;
}

//방법 2. 괄호의 추가 여부를 체크하며 완전 탐색
//#include<iostream>
//#include<climits>
//#include<vector>
//#include<string>
//
//using namespace std;
//
//int n, depth;
//long long answer = INT_MIN;
//char input[20];
//bool checkBracket[20];
//
//long long maxNum(int a, int b) {
//	return a > b ? a : b;
//}
//
//long long cal(long long a, long long b, string op) {
//	if (op == "+") return a + b;
//	else if (op == "-") return a - b;
//	else if (op == "*") return a * b;
//}
//
//long long calculate() {
//	vector<string> v;
//	for (int i = 0; i < n;) {
//		if (checkBracket[i] == false) {
//			string temp = "";
//			temp += input[i];
//			v.push_back(temp);
//			i++;
//		}
//		else {
//			string temp = "";
//			temp += input[i];
//			long long temp1 = stoi(temp);	//연산자 앞에 수
//
//			temp = "";
//			temp += input[i + 2];
//			long long temp2 = stoi(temp);	//연산자 뒤에 수
//
//			temp = "";
//			temp += input[i + 1];	//연산자
//			string op = temp;
//			long long tempResult = cal(temp1, temp2, op);
//			v.push_back(to_string(tempResult));
//			i += 3;
//		}
//	}
//	long long val = stoi(v[0]);
//	for (int i = 1; i < v.size(); i += 2) {
//		if (v[i] == "+") {
//			val += stoi(v[i + 1]);
//		}
//		else if (v[i] == "-") {
//			val -= stoi(v[i + 1]);
//		}
//		else if (v[i] == "*") {
//			val *= stoi(v[i + 1]);
//		}
//	}
//	return val;
//}
//
//void dfs(int idx) {
//	if (idx == n) {
//		answer = maxNum(answer, calculate());
//		return;
//	}
//	for (int i = idx; i < n; i = i + 2) {
//		if (i + 2 < n) {
//			if (checkBracket[i] == false && checkBracket[i + 2] == false) {
//				checkBracket[i] = true;
//				checkBracket[i + 2] = true;
//				dfs(idx + 2);
//				checkBracket[i] = false;
//				checkBracket[i + 2] = false;
//			}
//		}
//		else {
//			dfs(i + 1);
//		}
//	}
//}
//
//int main() {
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> input[i];
//	}
//	depth = n / 2;
//	dfs(0);
//	cout << answer << '\n';
//
//	return 0;
//}