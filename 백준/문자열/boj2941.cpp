#include<iostream>
#include<cstring>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string input;
	int count = 0;
	cin >> input;
	if (input.empty()) {
		cout << count;
		return 0;
	}
	//모든 input을 .at(i) 로 하면 런타임 에러가 뜨는데,
	// []을 이용한 접근은 범위를 체크하지 않아서 범위를
	//벗어난 접근을 시도할 경우 예외 발생하지 않고 에러 발생
	// 반면, at()을 이용한 접근은 범위를 체크하여 벗어난 접근을 시도하면
	// out of range 예외를 발생한다.
	//범위 내 접근 보장한다면 별도 범위 체크가 필요 없으므로 []로 원소 접근
	//그렇지 않으면 at()으로 접근하여 예외 처리해주기
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == 'c') {
			if(input[i + 1] == '=' || input[i + 1] == '-')
				i++;
		}
		else if (input[i] == 'd') {
			if (input[i+1] == '-') {
				i++;
			}
			else if (input[i+1] == 'z' && input[i+2] == '=') {
				i += 2;
			}
		}
		else if (input[i] == 'l' && input[i+1] == 'j') {
			i++;
		}
		else if (input[i] == 'n' && input[i+1] == 'j') {
			i++;
		}
		else if (input[i] == 's' && input[i+1] == '=') {
			i++;
		}
		else if (input[i] == 'z' && input[i+1] == '=') {
			i++;
		}
		count++;
		
	}
	cout << count << '\n';
	return 0;
}
