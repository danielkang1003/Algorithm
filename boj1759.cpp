#include<iostream>
#include<algorithm>

using namespace std;

int l, c;
char alphabet[15];

//1. 암호는 오름차순으로 되있을 것
//2. 암호에는 최소 한개의 모음과 최소 두개의 자음으로 구성

//인자값으로 인덱스, 길이, 모음, 자음, 그리고 암호(정답) 넘겨준다.
void dfs(int idx, int k, int aeiou, int others, string password) {
	//모음1개와 자음 2개 이상이고 길이가 l이라면 출력함
	if (k == l) {
		if (aeiou >= 1 && others >= 2) {
			cout << password << '\n';
		}
		return;
	}
	//암호는 오름차순이므로 지나간 알파벳은 보지 않는다.
	for (int i = idx; i < c; i++) {
		//모음일떄 dfs
		if (alphabet[i] == 'a' || alphabet[i] == 'e' || alphabet[i] == 'i' ||
			alphabet[i] == 'o' || alphabet[i] == 'u') {
			dfs(i + 1, k + 1, aeiou + 1, others, password + alphabet[i]);
		}
		//자음일때 dfs
		else {
			dfs(i + 1, k + 1, aeiou, others + 1, password + alphabet[i]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		cin >> alphabet[i];
	}
	//암호는 오름차순으로 해서 출력하기 위해
	sort(alphabet, alphabet + c);
	dfs(0, 0, 0, 0, "");	//첫 시작은 모두 0 이고 암호는 비어있음.
	return 0;
}