//��� 1. �⺻ ��Ž
#include<iostream>
#include<climits>

using namespace std;

int n, depth;
string input;
long long answer = INT_MIN;	//climits�� ���� �ִ밪���� ����(�������� �� ó������)
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
	//���� ��ġ �������� ��ȣ ��� ����س�����
	int currentResult = cal(numResult, num[operationIdx + 1], oper[operationIdx]);
	dfs(operationIdx + 1, currentResult);

	//���� �ڸ��� ��ȣ ó���Ͽ� ��� �̾����
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
		if (i % 2 == 0) num[numIdx++] = input[i] - '0';	//���ڸ� ���� �迭
		else oper[operIdx++] = input[i];	//��ȣ�� ���� �迭
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

//��� 2. ��ȣ�� �߰� ���θ� üũ�ϸ� ���� Ž��
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
//			long long temp1 = stoi(temp);	//������ �տ� ��
//
//			temp = "";
//			temp += input[i + 2];
//			long long temp2 = stoi(temp);	//������ �ڿ� ��
//
//			temp = "";
//			temp += input[i + 1];	//������
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