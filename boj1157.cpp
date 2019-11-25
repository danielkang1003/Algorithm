#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int check[26];
string input;
int maxCnt, idx, cnt;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> input;

	//단어 개수 세서 check에 숫자 넣기
	for (int i = 0; i < input.length(); i++) {
		if (input[i] >= 'A' && input[i] <= 'Z') {
			//대문자라면
			check[input[i] - 'A']++;
		}
		else {
			//소문자라면
			check[input[i] - 'a']++;
		}
	}

	//많이 사용된 값을 찾아서 maxCnt 와 idx로 저장
	for (int i = 0; i < 26; i++) {
		if (check[i] >= maxCnt) {
			maxCnt = check[i];
			idx = i;
		}
	}

	//check배열을 돌아서 이전의 maxCnt랑 같으면 cnt 증가
	//근데 cnt 가 두개 이상이면 많이 사용된 알파벳이 2개
	//이상이라는 뜻이므로 문제 조건과 같이 ? 출력
	for (int i = 0; i < 26; i++) {
		if (check[i] == maxCnt) {
			cnt++;
			if (cnt >= 2) {
				cout << "?\n";
				return 0;
			}
		}
	}

	cout << (char)(idx + 65);

	return 0;
}