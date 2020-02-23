#include<iostream>
#include<string>

using namespace std;

string document, input;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	getline(cin, document);
	getline(cin, input);
	int docSize = document.size();
	int inpSize = input.size();
	int len = docSize - inpSize;
	if (inpSize > docSize) cout << 0 << '\n';
	else {
		int answer = 0;
		for (int i = 0; i < len + 1; i++) {
			bool bothEqual = true;
			for (int j = 0; j < inpSize; j++) {
				//cout << "현재 i:" << i << " 범위:" << len + 1 <<'\n';
				if (document[i + j] != input[j]) {
					bothEqual = false;
					break;
				}
			}
			if (bothEqual) {
				answer++;
				i += inpSize - 1;
			}
		}
		cout << answer;
	}
	return 0;
}