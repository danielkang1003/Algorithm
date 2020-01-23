#include<iostream>
#include<algorithm>

using namespace std;

int n;
string input, temp;
int main() {
	cin >> n;
	cin >> input;
	string result = input;
	for (int i = 1; i < n; i++) {	//첫번째 input으로 받았고, 그 다음거를 비교위해 1부터 n-1까지 반복
		string temp;
		cin >> temp;
		for (int j = 0; j < input.length(); j++) {	//한 문자씩 돌면서 비교
			if (input[j] != temp[j]) result[j] = '?';	//처음 받았던 단어랑 그 이후 받은 단어 비교
			//만약 입력받은 단어들이 다르면 ?로 바꿔줌
		}
	}
	cout << result;

	return 0;
}