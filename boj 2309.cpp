#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;

vector<int> v; //9명의 일곱 난쟁이 키를 저장할 벡터
stack<int> s; //2명을 골라낼 스택
int height;	//각 난쟁이의 키

int main() {
	//total 변수를 정해주고, 키를 모두 받았다.
	//9명의 난쟁이 키는 100을 넘고 7 난쟁이의 키는 100이므로
	//총 키의 합에서 두명을 뺴주려고 했다.
	int total = 0;
	for (int i = 0; i < 9; i++) {
		cin >> height;
		total += height;
		v.push_back(height);
	}
	//이 부분이 현재 9난쟁이 키 중에서 오버된 두 난쟁이 키의 합
	int sub = total - 100;
	//난쟁이 1 과 난쟁이 2의 키를 가져오기 위한 변수
	int num1 = 0, num2 = 0;
	
	sort(v.rbegin(), v.rend());	//sort는 스택에 넣고 출력할때를 위해
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (v[i] + v[j] == sub) {	//전체를 돌아보면서 두명의 합이 같으면 변수에 저장
				num1 = v[i];
				num2 = v[j];
				break;
			}
		}
	}
	//저장된 난쟁이 2명의 키가 벡터에 저장된 값이랑 같으면 스택에 넣지않고,
	//나머지는 스택에 넣어줌
	for (int i = 0; i < 9; i++) {
		if (v[i] == num1 || v[i] == num2) {
			continue;
		}
		s.push(v[i]);
	}
	//출력의 결과
	for (int i = 0; i < 7; i++) {
		int top = s.top();
		cout << top << '\n';
		s.pop();
	}
	return 0;
}